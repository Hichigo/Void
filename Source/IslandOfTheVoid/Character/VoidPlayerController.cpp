// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "VoidPlayerController.h"


AVoidPlayerController::AVoidPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCameraRotation = false;

	SpeedCameraTilt = 30.0f;

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AVoidPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

void AVoidPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("RightMouse", IE_Pressed, this, &AVoidPlayerController::OnRightMousePressed);
	InputComponent->BindAction("MiddleMouse", IE_Pressed, this, &AVoidPlayerController::OnMiddleMousePressed);
	InputComponent->BindAction("MiddleMouse", IE_Released, this, &AVoidPlayerController::OnMiddleMouseRelease);

	InputComponent->BindAxis("CameraTilt", this, &AVoidPlayerController::OnCameraTilt);
	InputComponent->BindAxis("CameraRotation", this, &AVoidPlayerController::OnCameraRotation);
}

void AVoidPlayerController::BeginPlay()
{
	Super::BeginPlay();

	CharacterRef = Cast<AVoidCharacter>(GetPawn());
}

void AVoidPlayerController::OnRightMousePressed()
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, true, Hit);

		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(Hit.ImpactPoint, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, Hit.ImpactPoint);
		}
	}
}

void AVoidPlayerController::OnMiddleMousePressed()
{
	bCameraRotation = true;
}

void AVoidPlayerController::OnMiddleMouseRelease()
{
	bCameraRotation = false;
}

void AVoidPlayerController::OnCameraTilt(float Value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Value: %f, %b"), Value, bCameraTilt);
	if (bCameraRotation)
	{
		FRotator CameraRotation = CharacterRef->GetCameraBoom()->RelativeRotation;
		float pitch = CameraRotation.Pitch + SpeedCameraTilt * Value;
		
		CameraRotation.Pitch = FMath::Clamp(pitch, -80.0f, -10.0f);

		CharacterRef->GetCameraBoom()->SetRelativeRotation(CameraRotation);
		
	}
}

void AVoidPlayerController::OnCameraRotation(float Value)
{
	if (bCameraRotation)
	{
		FRotator CameraRotation = CharacterRef->GetCameraBoom()->RelativeRotation;
		float yaw = CameraRotation.Yaw + SpeedCameraTilt * Value;

		CameraRotation.Yaw = yaw;

		CharacterRef->GetCameraBoom()->SetRelativeRotation(CameraRotation);

	}
}

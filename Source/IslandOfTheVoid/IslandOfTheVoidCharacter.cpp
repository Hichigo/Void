// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "IslandOfTheVoid.h"
#include "IslandOfTheVoidCharacter.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"

AIslandOfTheVoidCharacter::AIslandOfTheVoidCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AIslandOfTheVoidCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		PC->GetHitResultUnderCursor(ECC_Visibility, true, Hit);
		
		//if (Hit.bBlockingHit)
		//{
		//	// We hit something, move there
		//	APawn* const MyPawn = GetPawn();
		//	if (MyPawn)
		//	{
		//		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		//		float const Distance = FVector::Dist(Hit.ImpactPoint, MyPawn->GetActorLocation());

		//		// We need to issue move command only if far enough in order for walk animation to play correctly
		//		if (NavSys && (Distance > 120.0f))
		//		{
		//			NavSys->SimpleMoveToLocation(this, Hit.ImpactPoint);
		//		}
		//	}
		//}
	}
}

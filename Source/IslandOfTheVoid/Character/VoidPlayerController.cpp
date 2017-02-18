// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "VoidPlayerController.h"


AVoidPlayerController::AVoidPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCameraRotation = false;

	SpeedCameraTilt = 5.0f;
	SpeedCameraZoom = 20.0f;
	
	Stat = ObjectInitializer.CreateDefaultSubobject<UStatComponent>(this, TEXT("Stat"));

	Ability = ObjectInitializer.CreateDefaultSubobject<UAbilityComponent>(this, TEXT("Ability"));
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Hand;
}

TArray<int32> AVoidPlayerController::TakeAbility(TArray<UDataAbility*> ArrayAbility, int32 SearchIndex)
{
	TArray<int32> EmptyArray;
	EmptyArray.Empty();

	// find ability
	UDataAbility *FindedAbility = Ability->FindAbilityById(ArrayAbility, SearchIndex);
	if (FindedAbility != nullptr)
	{
		// if experience enough 
		if (Stat->ReduceExperience(FindedAbility->AbilityInfo.Price))
		{
			FindedAbility->AbilityInfo.bIsTake = true;
			TArray<UDataAbility*> L_NextAbility = FindedAbility->GetNextAbilites();
			if (L_NextAbility.Num())
			{
				TArray<int32> ReturnIndexes;
				ReturnIndexes.Empty();
				for (int32 Index = 0; Index < L_NextAbility.Num(); ++Index)
				{
					// access ability
					if (L_NextAbility[Index]->AccessAbility())
					{
						ReturnIndexes.Add(L_NextAbility[Index]->AbilityInfo.ID);
					}
				}
				return ReturnIndexes;
			}
		}
	}
	return EmptyArray;
}

void AVoidPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	bool bCame = false;

	/** Without this check crash editor */
	if(CharacterRef != nullptr)
		bCame = CharacterRef->GetActorLocation().Equals(Goal, 120.0);

	if (bCame)
	{
		Goal.Set(-999.0, -999.0, -999.0);
		if (Stat->GetAllStats().Movement.Type == EMoveType::Running)
		{
			CharacterRef->GetCharacterMovement()->MaxWalkSpeed = Stat->GetAllStats().Movement.WalkSpeed;
			Stat->SetMovemetType(EMoveType::Walking);
		}
		
		
	}
}

void AVoidPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("RightMouse", IE_Pressed, this, &AVoidPlayerController::OnRightMousePressed);
	InputComponent->BindAction("RightMouse", IE_DoubleClick, this, &AVoidPlayerController::OnRightMouseDoublePressed);
	InputComponent->BindAction("MiddleMouse", IE_Pressed, this, &AVoidPlayerController::OnMiddleMousePressed);
	InputComponent->BindAction("MiddleMouse", IE_Released, this, &AVoidPlayerController::OnMiddleMouseRelease);
	
	InputComponent->BindAxis("CameraTilt", this, &AVoidPlayerController::OnCameraTilt);
	InputComponent->BindAxis("CameraRotation", this, &AVoidPlayerController::OnCameraRotation);
	InputComponent->BindAxis("CameraZoom", this, &AVoidPlayerController::OnCameraZoom);
}

void AVoidPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/** Get main player reference */
	CharacterRef = Cast<AVoidCharacter>(GetPawn());
}

void AVoidPlayerController::MoveCharacterToCursor()
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
			Goal = Hit.ImpactPoint;
		}
	}
}

void AVoidPlayerController::OnRightMousePressed()
{
	CharacterRef->GetCharacterMovement()->MaxWalkSpeed = Stat->GetAllStats().Movement.WalkSpeed;
	Stat->SetMovemetType(EMoveType::Walking);
	
	MoveCharacterToCursor();
	
}

void AVoidPlayerController::OnRightMouseDoublePressed()
{
	CharacterRef->GetCharacterMovement()->MaxWalkSpeed = Stat->GetAllStats().Movement.RunSpeed;
	Stat->SetMovemetType(EMoveType::Running);

	MoveCharacterToCursor();
}

void AVoidPlayerController::OnMiddleMousePressed()
{
	bCameraRotation = true;

	// remember mouse position
	GetMousePosition(MousePosition.X, MousePosition.Y);

	// hide mouse cursor
	bShowMouseCursor = false;
}

void AVoidPlayerController::OnMiddleMouseRelease()
{
	bCameraRotation = false;

	// show mouse cursor
	bShowMouseCursor = true;
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

		//return mouse cursor to remember postion
		SetMouseLocation(MousePosition.X, MousePosition.Y);

	}
}

void AVoidPlayerController::OnCameraZoom(float Value)
{
	if (CharacterRef != nullptr)
	{
		float ArmLength = CharacterRef->GetCameraBoom()->TargetArmLength;
		ArmLength = ArmLength + SpeedCameraZoom * Value;
		CharacterRef->GetCameraBoom()->TargetArmLength = FMath::Clamp(ArmLength, 400.0f, 2000.0f);
	}
}

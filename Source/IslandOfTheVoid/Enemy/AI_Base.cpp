// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AIController_Base.h"
#include "AI_Base.h"


// Sets default values
AAI_Base::AAI_Base()
	:	StartPointPatrol(0)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIControllerClass = AAIController_Base::StaticClass();

	MainAction = EActionEnemy::Patrol;
	PatrolDirection = EPatrolDirection::Loop;

	GetMesh()->OnBeginCursorOver.AddDynamic(this, &AAI_Base::CustomOnBeginMouseOver);
	GetMesh()->OnEndCursorOver.AddDynamic(this, &AAI_Base::CustomOnEndMouseOver);

	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0, 180.0, 0.0);
}

// Called when the game starts or when spawned
void AAI_Base::BeginPlay()
{
	Super::BeginPlay();
	

	if ( PatrolPath != nullptr )
	{
		const int32 NumOfSplinePoints = PatrolPath->GetSpline()->GetNumberOfSplinePoints();

		if ( (StartPointPatrol < 0) || (StartPointPatrol > NumOfSplinePoints) )
		{
			StartPointPatrol = 0;

			
			
		}
	}
}

// Called every frame
void AAI_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_Base::CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->CurrentMouseCursor = EMouseCursor::Crosshairs;
}

void AAI_Base::CustomOnEndMouseOver(UPrimitiveComponent* TouchedComponent)
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->CurrentMouseCursor = EMouseCursor::Hand;
}


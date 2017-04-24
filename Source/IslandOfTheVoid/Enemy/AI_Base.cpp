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


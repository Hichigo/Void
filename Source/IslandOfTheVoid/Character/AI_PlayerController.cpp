// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AI_PlayerController.h"

AAI_PlayerController::AAI_PlayerController(const FObjectInitializer& ObjectInitializer)
{
	AIPerceptionComp = ObjectInitializer.CreateDefaultSubobject<UAIPerceptionComponent>(this, TEXT("AIEyes"));
	AIPerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AAI_PlayerController::OnSenseUpdated);
	AIPerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AAI_PlayerController::OnTartgetSenseUpdated);
	SetPerceptionComponent(*AIPerceptionComp);
	Eyes = ObjectInitializer.CreateDefaultSubobject<UAISenseConfig_Sight>(this, TEXT("Eyes"));
	Eyes->SightRadius = 1000.0f;
	Eyes->LoseSightRadius = 1500.0f;
	Eyes->DetectionByAffiliation.bDetectEnemies = true;
	Eyes->DetectionByAffiliation.bDetectFriendlies = true;
	Eyes->DetectionByAffiliation.bDetectNeutrals = true;
	AIPerceptionComp->ConfigureSense(*Eyes);

	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorTreeComp"));

}

void AAI_PlayerController::BeginPlay()
{

}

void AAI_PlayerController::Possess(APawn * InPawn)
{
	MainPlayer = Cast<AVoidCharacter>(InPawn);
}

void AAI_PlayerController::UnPossess()
{

}

void AAI_PlayerController::OnSenseUpdated(TArray<AActor*> UpdatedActors)
{

}

void AAI_PlayerController::OnTartgetSenseUpdated(AActor * Actor, FAIStimulus Stimulus)
{

}

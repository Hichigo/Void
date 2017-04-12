// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AIController_Base.h"


AAIController_Base::AAIController_Base(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AIPerception = ObjectInitializer.CreateDefaultSubobject<UAIPerceptionComponent>(this, TEXT("AIPerception"));
	
	SightConfig = ObjectInitializer.CreateDefaultSubobject<UAISenseConfig_Sight>(this, TEXT("SightConfig"));
	
	AIPerception->ConfigureSense(*SightConfig);

	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());

	SightConfig->SightRadius = 1250.0f;
	SightConfig->LoseSightRadius = 1300.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	
	//Sence.BindUFunction(this, "OnPerceptionUpdated");

	AIPerception->OnPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnPerceptionUpdated);
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnTartgetPerceptionUpdated);
		//->OnTargetPerceptionUpdated.//__Internal_AddDynamic(this, &AAIController_Base::OnPerceptionUpdated);
}

void AAIController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	Pawn = Cast<AAI_Base>(GetPawn());

	MainAction = Pawn->MainStats.MainAction;

}

void AAIController_Base::OnPerceptionUpdated(TArray<AActor*> Actors)
{
}

void AAIController_Base::OnTartgetPerceptionUpdated(AActor *Actors, FAIStimulus Stimulus)
{
}


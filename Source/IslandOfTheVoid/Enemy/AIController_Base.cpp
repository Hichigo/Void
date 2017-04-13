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
	SightConfig->LoseSightRadius = 1500.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	
	//Sence.BindUFunction(this, "OnPerceptionUpdated");
	AIPerception->OnPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnSenceUpdated);
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnTartgetSenceUpdated);

	
}

void AAIController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	Pawn = Cast<AAI_Base>(GetPawn());

	MainAction = Pawn->MainStats.MainAction;

	AIPerception->OnPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnSenceUpdated);
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnTartgetSenceUpdated);

	ACharacter *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, SightConfig->GetSenseImplementation(), GetPawn());
	UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, SightConfig->GetSenseImplementation(), Player);
	
	

	UE_LOG(LogTemp, Warning, TEXT("Success %s"), *Player->GetName());
}

void AAIController_Base::OnSenceUpdated(TArray<AActor*> Actors)
{
	ACharacter *Player = GetCharacter();
	FActorPerceptionBlueprintInfo InfoActor;

	UE_LOG(LogTemp, Warning, TEXT("Success %s"), *Player->GetName());
	for (auto Actor : Actors)
	{
		if (Player == Actor)
		{
			AIPerception->GetActorsPerception(Actor, InfoActor);

			FAIStimulus Stimulus = InfoActor.LastSensedStimuli[0];

			if (Stimulus.WasSuccessfullySensed())
			{
				UE_LOG(LogTemp, Warning, TEXT("Success"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed"));
			}
		}
	}
}

void AAIController_Base::OnTartgetSenceUpdated(AActor *Actors, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("target"));
}


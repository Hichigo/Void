// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AIController_Base.h"


AAIController_Base::AAIController_Base()
{
	AIPerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIEyes"));
	AIPerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnSenseUpdated);
	AIPerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnTartgetSenseUpdated);
	SetPerceptionComponent(*AIPerceptionComp);
	Eyes = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Eyes"));
	Eyes->SightRadius = 500.0f;
	Eyes->LoseSightRadius = 600.0f;
	Eyes->DetectionByAffiliation.bDetectEnemies = true;
	Eyes->DetectionByAffiliation.bDetectFriendlies = true;
	Eyes->DetectionByAffiliation.bDetectNeutrals = true;
	AIPerceptionComp->ConfigureSense(*Eyes);
}

void AAIController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	//MainAction = Pawn->MainStats.MainAction;


	//ACharacter *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	//UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, Eyes->GetSenseImplementation(), Pawn);
	//UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, Eyes->GetSenseImplementation(), Player);
	
}

void AAIController_Base::OnSenseUpdated(TArray<AActor*> UpdatedActors)
{
	//ACharacter *Player = GetCharacter();
	//FActorPerceptionBlueprintInfo InfoActor;

	UE_LOG(LogTemp, Warning, TEXT("Senced Actors"));
	/*for (auto Actor : UpdatedActors)
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
	}*/
}

void AAIController_Base::OnTartgetSenseUpdated(AActor *Actor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("target"));
}


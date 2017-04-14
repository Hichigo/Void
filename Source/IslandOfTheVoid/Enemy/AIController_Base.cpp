// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AIController_Base.h"


AAIController_Base::AAIController_Base(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AIPerception = ObjectInitializer.CreateDefaultSubobject<UAIPerceptionComponent>(this, TEXT("AIPerception"));
	AIPerception->OnPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnSenseUpdated);
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnTartgetSenseUpdated);


	Eyes = ObjectInitializer.CreateDefaultSubobject<UAISenseConfig_Sight>(this, TEXT("Eyes"));
	
	AIPerception->ConfigureSense(*Eyes);

	AIPerception->SetDominantSense(Eyes->GetSenseImplementation());
	
	Eyes->SightRadius = 1250.0f;
	Eyes->LoseSightRadius = 1500.0f;
	Eyes->DetectionByAffiliation.bDetectEnemies = true;
	Eyes->DetectionByAffiliation.bDetectNeutrals = true;
	Eyes->DetectionByAffiliation.bDetectFriendlies = true;
	

	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));
	
}

void AAIController_Base::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);
	
	Pawn = Cast<AAI_Base>(InPawn);

	if (Pawn)
	{
		if (Pawn->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*Pawn->BehaviorTree->BlackboardAsset);
		}
		BehaviorComp->StartTree(*Pawn->BehaviorTree);
	}
}

void AAIController_Base::UnPossess()
{
	Super::UnPossess();

	BehaviorComp->StopTree();
}

void AAIController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	MainAction = Pawn->MainStats.MainAction;


	ACharacter *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, Eyes->GetSenseImplementation(), Pawn);
	UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, Eyes->GetSenseImplementation(), Player);
	
}

void AAIController_Base::OnSenseUpdated(TArray<AActor*> UpdatedActors)
{
	ACharacter *Player = GetCharacter();
	FActorPerceptionBlueprintInfo InfoActor;

	UE_LOG(LogTemp, Warning, TEXT("Senced Actors %s"), *Player->GetName());
	for (auto Actor : UpdatedActors)
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

void AAIController_Base::OnTartgetSenseUpdated(AActor *Actor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("target"));
}


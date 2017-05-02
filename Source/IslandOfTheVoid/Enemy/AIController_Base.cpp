// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AIController_Base.h"


AAIController_Base::AAIController_Base(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	AIPerceptionComp = ObjectInitializer.CreateDefaultSubobject<UAIPerceptionComponent>(this, TEXT("AIEyes"));
	AIPerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnSenseUpdated);
	AIPerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AAIController_Base::OnTartgetSenseUpdated);
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

void AAIController_Base::BeginPlay()
{
	Super::BeginPlay();
	
	
	BlackboardComp->SetValueAsEnum(FName("Action"), (uint8)MainAction);
	
}

void AAIController_Base::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);
	
	Pawn = Cast<AAI_Base>(InPawn);

	if (Pawn && Pawn->BehaviorTree)
	{
		if (Pawn->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*Pawn->BehaviorTree->BlackboardAsset);
		}

		BlackboardComp->SetValueAsVector(FName("HomeLocation"), Pawn->GetActorLocation());
		BlackboardComp->SetValueAsRotator(FName("IdleRotation"), Pawn->GetActorRotation());
		MainAction = Pawn->MainAction;

		BehaviorComp->StartTree(*(Pawn->BehaviorTree));
	}
}

void AAIController_Base::UnPossess()
{
	Super::UnPossess();

	BehaviorComp->StopTree();
}

void AAIController_Base::OnSenseUpdated(TArray<AActor*> UpdatedActors)
{
	ACharacter *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	FActorPerceptionBlueprintInfo InfoActor;

	for (auto Actor : UpdatedActors)
	{
		if (Player == Actor)
		{
			AIPerceptionComp->GetActorsPerception(Actor, InfoActor);

			FAIStimulus Stimulus = InfoActor.LastSensedStimuli[0];
			
			if (Stimulus.WasSuccessfullySensed())
			{
				UE_LOG(LogTemp, Warning, TEXT("Success"));
				BlackboardComp->SetValueAsEnum(FName("Action"), (uint8)EActionEnemy::Chase);
				BlackboardComp->SetValueAsObject(FName("Player"), InfoActor.Target);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed"));
				BlackboardComp->SetValueAsObject(FName("Player"), nullptr);
			}
		}
	}
}

void AAIController_Base::OnTartgetSenseUpdated(AActor *Actor, FAIStimulus Stimulus)
{
	UE_LOG(LogTemp, Warning, TEXT("target"));
	ACharacter *Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (Actor == Player)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			//clear timer
			GetWorldTimerManager().ClearTimer(ForgetPlayerTimer);
			Pawn->GetCharacterMovement()->MaxWalkSpeed = 500.0f;
			BlackboardComp->SetValueAsEnum(FName("Action"), (uint8)EActionEnemy::Chase);
		}
		else
		{
			BlackboardComp->SetValueAsVector(FName("LastSeePlayerLocation"), Actor->GetActorLocation());
			Pawn->GetCharacterMovement()->MaxWalkSpeed = 350.0f;
			UE_LOG(LogTemp, Warning, TEXT("LastSeePlayerLocation"));
			//set timer and save id timer
			GetWorldTimerManager().SetTimer(ForgetPlayerTimer, this, &AAIController_Base::ForgetPlayer, 15.0f, false);
			BlackboardComp->SetValueAsEnum(FName("Action"), (uint8)EActionEnemy::Search);
		}
	}
}

void AAIController_Base::ForgetPlayer()
{
	Pawn->GetCharacterMovement()->MaxWalkSpeed = 200.0f;
	BlackboardComp->SetValueAsEnum(FName("Action"), (uint8)MainAction);
}


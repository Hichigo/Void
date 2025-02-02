// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Enemy/AI_Base.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
//#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
//#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
//#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Float.h"
//#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Rotator.h"
//#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Enum.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

#include "AIController_Base.generated.h"

//class UBehaviorTreeComponent;
//class UBlackboardComponent;

/**
 * 
 */
UCLASS()
class ISLANDOFTHEVOID_API AAIController_Base : public AAIController
{
	GENERATED_BODY()

	AAIController_Base(const FObjectInitializer& ObjectInitializer);

public:
	virtual void BeginPlay() override;

	virtual void Possess(APawn* InPawn) override;

	virtual void UnPossess() override;

	UPROPERTY(EditAnywhere, Category = "AI")
	EActionEnemy MainAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UAIPerceptionComponent* AIPerceptionComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Sight* Eyes;

	UFUNCTION(BlueprintCallable, Category = "AI")
	void OnSenseUpdated(TArray<AActor*> UpdatedActors);

	UFUNCTION(BlueprintCallable, Category = "AI")
	void OnTartgetSenseUpdated(AActor *Actor, FAIStimulus Stimulus);

	/** Returns BlackboardComp subobject **/
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

private:
	AAI_Base *Pawn;
	

	UPROPERTY(transient)
	UBlackboardComponent* BlackboardComp;

	/* Cached BT component */
	UPROPERTY(transient)
	UBehaviorTreeComponent* BehaviorComp;

	void ForgetPlayer();

	FTimerHandle ForgetPlayerTimer;
};

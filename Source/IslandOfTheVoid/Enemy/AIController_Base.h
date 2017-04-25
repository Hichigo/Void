// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Enemy/AI_Base.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
	UAIPerceptionComponent* AIPerceptionComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Test)
	UAISenseConfig_Sight* Eyes;

	UFUNCTION(BlueprintCallable, Category = Test)
	void OnSenseUpdated(TArray<AActor*> UpdatedActors);

	UFUNCTION(BlueprintCallable, Category = Test)
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
};

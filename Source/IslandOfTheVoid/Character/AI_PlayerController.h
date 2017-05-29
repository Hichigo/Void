// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Character/VoidCharacter.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "AI_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDOFTHEVOID_API AAI_PlayerController : public AAIController
{
	GENERATED_BODY()
	

	AAI_PlayerController(const FObjectInitializer& ObjectInitializer);

public:
	virtual void BeginPlay() override;

	virtual void Possess(APawn* InPawn) override;

	virtual void UnPossess() override;

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
	AVoidCharacter *MainPlayer;


	UPROPERTY(transient)
	UBlackboardComponent* BlackboardComp;

	/* Cached BT component */
	UPROPERTY(transient)
	UBehaviorTreeComponent* BehaviorComp;
	
};

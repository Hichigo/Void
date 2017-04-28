// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "Enemy/AI_Base.h"
#include "Enemy/AI_PathPatrol.h"
#include "GetNextPointPatrol.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDOFTHEVOID_API UGetNextPointPatrol : public UBTTask_BlueprintBase
{
	GENERATED_BODY()

	virtual void ReceiveExecuteAI(AAIController* OwnerController, APawn* ControlledPawn);

public:
	

	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector TargetLocation;
	
	
};

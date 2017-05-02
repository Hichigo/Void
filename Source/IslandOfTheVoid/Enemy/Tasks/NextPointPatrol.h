// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enemy/AIController_Base.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NextPointPatrol.generated.h"

/**
 * 
 */
UCLASS(Category = "IslandOfTheVoid")
class ISLANDOFTHEVOID_API UNextPointPatrol : public UBTTask_BlackboardBase
{
	GENERATED_BODY()



	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;


};

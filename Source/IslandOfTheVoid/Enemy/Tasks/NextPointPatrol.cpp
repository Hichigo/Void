// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "NextPointPatrol.h"




EBTNodeResult::Type UNextPointPatrol::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AAIController_Base *Controller = Cast<AAIController_Base>(OwnerComp.GetAIOwner());
	AAI_Base *Pawn = Cast<AAI_Base>(Controller->GetPawn());
	
	
	USplineComponent *Spline;

	
	Spline = Pawn->GetPathPatrol()->GetSpline();

	FVector TargetPos = Spline->GetLocationAtSplinePoint(Pawn->StartPointPatrol, ESplineCoordinateSpace::World);

	const UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	auto BBID = Blackboard->GetKeyID(BlackboardKey.SelectedKeyName);
	auto BBKeyType = Blackboard->GetKeyType(BBID);

	if (BBKeyType == UBlackboardKeyType_Vector::StaticClass())
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), TargetPos);
	}

	switch (Pawn->PatrolDirection)
	{
	case EPatrolDirection::Loop:
		if (Pawn->StartPointPatrol >= Spline->GetNumberOfSplinePoints())
		{
			Pawn->StartPointPatrol = 0;
		}
		else
		{
			Pawn->StartPointPatrol++;
		}
		return EBTNodeResult::Succeeded;
	case EPatrolDirection::Forward:
		Pawn->StartPointPatrol++;
		if (Pawn->StartPointPatrol >= Spline->GetNumberOfSplinePoints() - 1)
		{
			Pawn->StartPointPatrol = Spline->GetNumberOfSplinePoints() - 1;
			Pawn->PatrolDirection = EPatrolDirection::Backward;
		}
		return EBTNodeResult::Succeeded;
	case EPatrolDirection::Backward:
		Pawn->StartPointPatrol--;
		if (Pawn->StartPointPatrol <= 0)
		{
			Pawn->StartPointPatrol = 0;
			Pawn->PatrolDirection = EPatrolDirection::Forward;
		}
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}



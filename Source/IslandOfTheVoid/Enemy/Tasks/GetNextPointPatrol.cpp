// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "GetNextPointPatrol.h"

void UGetNextPointPatrol::ReceiveExecuteAI(AAIController * OwnerController, APawn * ControlledPawn)
{
	AAI_Base *Pawn = Cast<AAI_Base>(ControlledPawn);
	USplineComponent *Spline;
	int32 NextPointIndex = 0;

	Pawn = Cast<AAI_Base>(ControlledPawn);
	NextPointIndex = Pawn->StartPointPatrol;
	Spline = Pawn->GetPathPatrol()->GetSpline();

	FVector TargetPos = Spline->GetLocationAtSplinePoint(NextPointIndex, ESplineCoordinateSpace::World);
	UE_LOG(LogTemp, Warning, TEXT("Next Point Index"));


	//const UBlackboardComponent* BlackboardComp = Pawn->GetController()
	//AAIController* MyController = OwnerComp.GetAIOwner();
	//bool HasLOS = false;

	//if (MyController && MyBlackboard)
	//{
	//	auto MyID = MyBlackboard->GetKeyID(EnemyKey.SelectedKeyName);
	//	auto TargetKeyType = MyBlackboard->GetKeyType(MyID);

	FinishExecute(true);
}

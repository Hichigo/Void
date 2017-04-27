// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "GetNextPointPatrol.h"

void UGetNextPointPatrol::ReceiveExecuteAI(AAIController * OwnerController, APawn * ControlledPawn)
{
	AAI_Base *Pawn;
	USplineComponent * Spline;
	int32 NextPointIndex = 0;
	if (ControlledPawn == nullptr)
	{
		Pawn = Cast<AAI_Base>(ControlledPawn);
		NextPointIndex = Pawn->StartPointPatrol;
		Spline = Pawn->GetPathPatrol()->GetSpline();
	}

//	FVector TargetPos = Spline->GetLocationAtSplinePoint(NextPointIndex, ESplineCoordinateSpace::World);
	
}

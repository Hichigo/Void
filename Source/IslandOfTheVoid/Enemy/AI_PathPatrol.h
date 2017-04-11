// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Classes/Components/SplineComponent.h"
#include "AI_PathPatrol.generated.h"

UCLASS()
class ISLANDOFTHEVOID_API AAI_PathPatrol : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAI_PathPatrol(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	FORCEINLINE USplineComponent* GetSpline() const { return Spline; }
	
private:
	class USplineComponent *Spline;

};

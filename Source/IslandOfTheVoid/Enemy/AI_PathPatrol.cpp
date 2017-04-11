// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AI_PathPatrol.h"


// Sets default values
AAI_PathPatrol::AAI_PathPatrol(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Spline = ObjectInitializer.CreateDefaultSubobject<USplineComponent>(this, TEXT("Spline"));

}

// Called when the game starts or when spawned
void AAI_PathPatrol::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_PathPatrol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


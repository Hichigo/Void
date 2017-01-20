// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "StatComponent.h"


// Sets default values for this component's properties
UStatComponent::UStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UStatComponent::HealthIncrease()
{
	if (HeroStat.Experience - HeroStat.BaseStats.Health.Price >= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("HORHOSH!"));
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Health.Price;
	}
}

// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	HeroStat.Experience = 300;
	HeroStat.BaseStats.Health.Price = 100;

}


// Called every frame
void UStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


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
	if (CheckHealthIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Health.Price;
		HeroStat.BaseStats.Health.Count += 1;
	}
}

void UStatComponent::VitalityIncrease()
{
	if (CheckHealthIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Vitality.Price;
		HeroStat.BaseStats.Vitality.Count += 1;
	}
}

void UStatComponent::StrengthIncrease()
{
	if (CheckHealthIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Strength.Price;
		HeroStat.BaseStats.Strength.Count += 1;
	}
}

void UStatComponent::AgilityIncrease()
{
	if (CheckHealthIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Agility.Price;
		HeroStat.BaseStats.Agility.Count += 1;
	}
}

void UStatComponent::IntelligenceIncrease()
{
	if (CheckHealthIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Intelligence.Price;
		HeroStat.BaseStats.Intelligence.Count += 1;
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

bool UStatComponent::CheckHealthIncrease()
{
	return HeroStat.Experience - HeroStat.BaseStats.Health.Price >= 0;
}

bool UStatComponent::CheckVitalityIncrease()
{
	return HeroStat.Experience - HeroStat.BaseStats.Vitality.Price >= 0;
}

bool UStatComponent::CheckStrengthIncrease()
{
	return HeroStat.Experience - HeroStat.BaseStats.Strength.Price >= 0;
}

bool UStatComponent::CheckAgilityIncrease()
{
	return HeroStat.Experience - HeroStat.BaseStats.Agility.Price >= 0;
}

bool UStatComponent::CheckIntelligenceIncrease()
{
	return HeroStat.Experience - HeroStat.BaseStats.Intelligence.Price >= 0;
}


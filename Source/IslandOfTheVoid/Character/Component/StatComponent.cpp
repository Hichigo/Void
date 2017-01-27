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

		HeroStat.BaseStats.Health.CalculateNewPriceMax();

		HeroStat.BaseStats.Vitality.CalculateNewPriceMin();
		HeroStat.BaseStats.Strength.CalculateNewPriceMin();
		HeroStat.BaseStats.Agility.CalculateNewPriceMin();
		HeroStat.BaseStats.Intelligence.CalculateNewPriceMin();
	}
}

void UStatComponent::VitalityIncrease()
{
	if (CheckVitalityIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Vitality.Price;
		HeroStat.BaseStats.Vitality.Count += 1;

		HeroStat.BaseStats.Vitality.CalculateNewPriceMax();

		HeroStat.BaseStats.Health.CalculateNewPriceMin();
		HeroStat.BaseStats.Strength.CalculateNewPriceMin();
		HeroStat.BaseStats.Agility.CalculateNewPriceMin();
		HeroStat.BaseStats.Intelligence.CalculateNewPriceMin();
	}
}

void UStatComponent::StrengthIncrease()
{
	if (CheckStrengthIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Strength.Price;
		HeroStat.BaseStats.Strength.Count += 1;

		HeroStat.BaseStats.Strength.CalculateNewPriceMax();
		
		HeroStat.BaseStats.Vitality.CalculateNewPriceMin();
		HeroStat.BaseStats.Health.CalculateNewPriceMin();
		HeroStat.BaseStats.Agility.CalculateNewPriceMin();
		HeroStat.BaseStats.Intelligence.CalculateNewPriceMin();
	}
}

void UStatComponent::AgilityIncrease()
{
	if (CheckAgilityIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Agility.Price;
		HeroStat.BaseStats.Agility.Count += 1;

		HeroStat.BaseStats.Agility.CalculateNewPriceMax();
		
		HeroStat.BaseStats.Vitality.CalculateNewPriceMin();
		HeroStat.BaseStats.Health.CalculateNewPriceMin();
		HeroStat.BaseStats.Strength.CalculateNewPriceMin();
		HeroStat.BaseStats.Intelligence.CalculateNewPriceMin();
	}
}

void UStatComponent::IntelligenceIncrease()
{
	if (CheckIntelligenceIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Intelligence.Price;
		HeroStat.BaseStats.Intelligence.Count += 1;

		HeroStat.BaseStats.Intelligence.CalculateNewPriceMax();
		
		HeroStat.BaseStats.Vitality.CalculateNewPriceMin();
		HeroStat.BaseStats.Health.CalculateNewPriceMin();
		HeroStat.BaseStats.Strength.CalculateNewPriceMin();
		HeroStat.BaseStats.Agility.CalculateNewPriceMin();
		
	}
}

// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	HeroStat.Experience = 2300;
	HeroStat.BaseStats.Health.Price = 100;
	HeroStat.BaseStats.Health.BasePrice = 10;

	HeroStat.BaseStats.Health.MinFactor = 1.1f;

	HeroStat.BaseStats.Health.MaxFactor = 1.2f;
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


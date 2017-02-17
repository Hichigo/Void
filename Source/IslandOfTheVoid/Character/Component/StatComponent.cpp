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
		HeroStat.BaseStats.Health.Points += 1;

		HeroStat.BaseStats.Health.CalculateNewPriceMax();

		HeroStat.BaseStats.Endurance.CalculateNewPriceMin();
		HeroStat.BaseStats.Strength.CalculateNewPriceMin();
		HeroStat.BaseStats.Agility.CalculateNewPriceMin();
		HeroStat.BaseStats.Intelligence.CalculateNewPriceMin();
	}
}

void UStatComponent::EnduranceIncrease()
{
	if (CheckEnduranceIncrease())
	{
		HeroStat.Experience = HeroStat.Experience - HeroStat.BaseStats.Endurance.Price;
		HeroStat.BaseStats.Endurance.Points += 1;

		HeroStat.BaseStats.Endurance.CalculateNewPriceMax();

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
		HeroStat.BaseStats.Strength.Points += 1;

		HeroStat.BaseStats.Strength.CalculateNewPriceMax();
		
		HeroStat.BaseStats.Endurance.CalculateNewPriceMin();
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
		HeroStat.BaseStats.Agility.Points += 1;

		HeroStat.BaseStats.Agility.CalculateNewPriceMax();
		
		HeroStat.BaseStats.Endurance.CalculateNewPriceMin();
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
		HeroStat.BaseStats.Intelligence.Points += 1;

		HeroStat.BaseStats.Intelligence.CalculateNewPriceMax();
		
		HeroStat.BaseStats.Endurance.CalculateNewPriceMin();
		HeroStat.BaseStats.Health.CalculateNewPriceMin();
		HeroStat.BaseStats.Strength.CalculateNewPriceMin();
		HeroStat.BaseStats.Agility.CalculateNewPriceMin();
		
	}
}

void UStatComponent::LessHealth(float Damage, EWhereAttack Attack)
{
	HeroStat.Total.Health.Current -= Damage;

	switch (Attack)
	{
		case EWhereAttack::Head:
			HeroStat.Head.Health.Current -= Damage;
			break;
		case EWhereAttack::Body:
			HeroStat.Body.Health.Current -= Damage;
			break;
		case EWhereAttack::LeftArm:
			HeroStat.LeftArm.Health.Current -= Damage;
			break;
		case EWhereAttack::RightArm:
			HeroStat.RightArm.Health.Current -= Damage;
			break;
		case EWhereAttack::LeftLeg:
			HeroStat.LeftLeg.Health.Current -= Damage;
			break;
		case EWhereAttack::RightLeg:
			HeroStat.RightLeg.Health.Current -= Damage;
			break;
		case EWhereAttack::AllPart:
			float DivideDamage = Damage / 6.0f;

			HeroStat.Head.Health.Current -= DivideDamage;
			HeroStat.Body.Health.Current -= DivideDamage;
			HeroStat.LeftArm.Health.Current -= DivideDamage;
			HeroStat.RightArm.Health.Current -= DivideDamage;
			HeroStat.LeftLeg.Health.Current -= DivideDamage;
			HeroStat.RightLeg.Health.Current -= DivideDamage;
			break;
	}
}

bool UStatComponent::ReduceExperience(int32 HowMuch)
{
	if (HeroStat.Experience - HowMuch >= 0)
	{
		HeroStat.Experience = HeroStat.Experience - HowMuch;
		return true;
	}
	else {
		return false;
	}
}

// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	

	HeroStat.Experience = 9999;

	HeroStat.Movement.WalkSpeed = 200;
	HeroStat.Movement.RunSpeed = 600;


	HeroStat.Endurance.Current = 50;
	HeroStat.Endurance.Max = 50;

	// set attribute name
#define LOCTEXT_NAMESPACE "AttributeName"
	HeroStat.BaseStats.Health.NameStat = LOCTEXT("HealthName", "Health");
	HeroStat.BaseStats.Endurance.NameStat = LOCTEXT("EnduranceName", "Endurance");
	HeroStat.BaseStats.Strength.NameStat = LOCTEXT("StrengthName", "Strength");
	HeroStat.BaseStats.Agility.NameStat = LOCTEXT("AgilityName", "Agility");
	HeroStat.BaseStats.Intelligence.NameStat = LOCTEXT("IntelligenceName", "Intelligence");
#undef LOCTEXT_NAMESPACE

	//Health base stats
	HeroStat.BaseStats.Health.Points = 8;
	HeroStat.BaseStats.Health.Price = 100;
	HeroStat.BaseStats.Health.BasePrice = 10;
	HeroStat.BaseStats.Health.MinFactor = 1.1f;
	HeroStat.BaseStats.Health.MaxFactor = 1.5f;

	//Endurance base stats
	HeroStat.BaseStats.Endurance.Points = 8;
	HeroStat.BaseStats.Endurance.Price = 100;
	HeroStat.BaseStats.Endurance.BasePrice = 10;
	HeroStat.BaseStats.Endurance.MinFactor = 1.1f;
	HeroStat.BaseStats.Endurance.MaxFactor = 1.5f;

	//Strength base stats
	HeroStat.BaseStats.Strength.Points = 8;
	HeroStat.BaseStats.Strength.Price = 100;
	HeroStat.BaseStats.Strength.BasePrice = 10;
	HeroStat.BaseStats.Strength.MinFactor = 1.1f;
	HeroStat.BaseStats.Strength.MaxFactor = 1.5f;

	//Agility base stats
	HeroStat.BaseStats.Agility.Points = 8;
	HeroStat.BaseStats.Agility.Price = 100;
	HeroStat.BaseStats.Agility.BasePrice = 10;
	HeroStat.BaseStats.Agility.MinFactor = 1.1f;
	HeroStat.BaseStats.Agility.MaxFactor = 1.5f;

	//Intelligence base stats
	HeroStat.BaseStats.Intelligence.Points = 8;
	HeroStat.BaseStats.Intelligence.Price = 100;
	HeroStat.BaseStats.Intelligence.BasePrice = 10;
	HeroStat.BaseStats.Intelligence.MinFactor = 1.1f;
	HeroStat.BaseStats.Intelligence.MaxFactor = 1.5f;

	HeroStat.BaseStats.RegenerationHealth = 1.0f;


	HeroStat.BaseStats.KHealth = 10.0f;

	HeroStat.RecalculateBodyPartHealth();
}



// Called every frame
void UStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (IsNotFullHealth())
	{
		// to do rengeneration total hp and body part
		HeroStat.Total.Health.Current += HeroStat.BaseStats.RegenerationHealth * DeltaTime;

		TArray<FBodyPart*> RegeneratingParts;
		if (HeroStat.Head.Health.Current < HeroStat.Head.Health.Max)
		{
			RegeneratingParts.Add(&HeroStat.Head);
		}
		if (HeroStat.Body.Health.Current < HeroStat.Body.Health.Max)
		{
			RegeneratingParts.Add(&HeroStat.Body);
		}
		if (HeroStat.LeftArm.Health.Current < HeroStat.LeftArm.Health.Max)
		{
			RegeneratingParts.Add(&HeroStat.LeftArm);
		}
		if (HeroStat.RightArm.Health.Current < HeroStat.RightArm.Health.Max)
		{
			RegeneratingParts.Add(&HeroStat.RightArm);
		}
		if (HeroStat.LeftLeg.Health.Current < HeroStat.LeftLeg.Health.Max)
		{
			RegeneratingParts.Add(&HeroStat.LeftLeg);
		}
		if (HeroStat.RightLeg.Health.Current < HeroStat.RightLeg.Health.Max)
		{
			RegeneratingParts.Add(&HeroStat.RightLeg);
		}

		float RegenPerPart = HeroStat.BaseStats.RegenerationHealth * DeltaTime / (float)RegeneratingParts.Num();

		for (auto part : RegeneratingParts)
		{
			part->Health.Current += RegenPerPart;
		}

		if (HeroStat.Total.Health.Current > HeroStat.Total.Health.Max)
		{
			HeroStat.Total.Health.Current = HeroStat.Total.Health.Max;

			HeroStat.Head.Health.Current = HeroStat.Head.Health.Current;
			HeroStat.Body.Health.Current = HeroStat.Body.Health.Current;
			HeroStat.LeftArm.Health.Current = HeroStat.LeftArm.Health.Current;
			HeroStat.RightArm.Health.Current = HeroStat.RightArm.Health.Current;
			HeroStat.LeftLeg.Health.Current = HeroStat.LeftLeg.Health.Current;
			HeroStat.RightLeg.Health.Current = HeroStat.RightLeg.Health.Current;

		}

	}

	if()

	if (IsNotFullEndurance())
	{
		// increase Endurance
		HeroStat.Endurance.Current += HeroStat.BaseStats.RegenerationEndurance;

		// endurance check to not exceed a maximum of
		if (HeroStat.Endurance.Current > HeroStat.Endurance.Max)
		{
			HeroStat.Endurance.Current = HeroStat.Endurance.Max;
		}
	}
}

bool UStatComponent::CheckHealthIncrease()
{
	return HeroStat.Experience - HeroStat.BaseStats.Health.Price >= 0;
}

bool UStatComponent::CheckEnduranceIncrease()
{
	return HeroStat.Experience - HeroStat.BaseStats.Endurance.Price >= 0;
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

bool UStatComponent::IsNotFullHealth()
{
	return HeroStat.Total.Health.Current < HeroStat.Total.Health.Max;
}

bool UStatComponent::IsNotFullEndurance()
{
	return HeroStat.Endurance.Current < HeroStat.Endurance.Max;
}


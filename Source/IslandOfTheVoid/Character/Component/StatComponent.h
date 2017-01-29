// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Structures/Hero/HeroStructures.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISLANDOFTHEVOID_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatComponent();

	

	/** Return all stats hero */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Hero stats")
	FORCEINLINE FHeroStats GetAllStats() const { return HeroStat; }

	/** Health increase */
	UFUNCTION(BlueprintCallable, Category = "Hero stats")
	void HealthIncrease();

	/** Endurance increase */
	UFUNCTION(BlueprintCallable, Category = "Hero stats")
	void EnduranceIncrease();

	/** Strength increase */
	UFUNCTION(BlueprintCallable, Category = "Hero stats")
	void StrengthIncrease();

	/** Agility increase */
	UFUNCTION(BlueprintCallable, Category = "Hero stats")
	void AgilityIncrease();

	/** Intelligence increase */
	UFUNCTION(BlueprintCallable, Category = "Hero stats")
	void IntelligenceIncrease();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	/** All stats hero */
	FHeroStats HeroStat;
		
	/** Check experience for health increase */
	bool CheckHealthIncrease();
	/** Check experience for Endurance increase */
	bool CheckEnduranceIncrease();
	/** Check experience for strength increase */
	bool CheckStrengthIncrease();
	/** Check experience for agility increase */
	bool CheckAgilityIncrease();
	/** Check experience for intelligence increase */
	bool CheckIntelligenceIncrease();

	/** Check on full health */
	bool IsNotFullHealth();
	/** Check on full Endurance */
	bool IsNotFullEndurance();
};

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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:

	/** All stats hero */
	FHeroStats HeroStat;
		
	
};

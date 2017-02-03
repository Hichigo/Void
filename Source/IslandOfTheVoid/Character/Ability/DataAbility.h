// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Structures/Hero/AbilityStructures.h"
#include "Engine/DataAsset.h"
#include "DataAbility.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ISLANDOFTHEVOID_API UDataAbility : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UDataAbility();
	
public:

	UPROPERTY(EditAnywhere)
	FAbility AbilityInfo;

	UPROPERTY(EditAnywhere)
	TArray<UDataAbility*> NextAbility;

	UPROPERTY(EditAnywhere)
	TArray<UDataAbility*> PreviousAbility;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Hero|AbilityInfo")
	FORCEINLINE FAbility GetAbilityInfo() { return AbilityInfo; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Hero|AbilityInfo")
	FORCEINLINE TArray<UDataAbility*> GetNextAbilites() { return NextAbility; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Hero|AbilityInfo")
	FORCEINLINE TArray<UDataAbility*> GetPreviousAbilites() { return PreviousAbility; }

};

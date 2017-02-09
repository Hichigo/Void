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

	/** Ability information */
	UPROPERTY(EditAnywhere)
	FAbility AbilityInfo;

	/** Next ability list */
	UPROPERTY(EditAnywhere)
	TArray<UDataAbility*> NextAbility;

	/** Previous ability list */
	UPROPERTY(EditAnywhere)
	TArray<UDataAbility*> PreviousAbility;

	/** Return current ability info */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Hero|AbilityInfo")
	FORCEINLINE FAbility GetAbilityInfo() { return AbilityInfo; }

	/** Return next ability list */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Hero|AbilityInfo")
	FORCEINLINE TArray<UDataAbility*> GetNextAbilites() { return NextAbility; }

	/** Return previous ability list */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Hero|AbilityInfo")
	FORCEINLINE TArray<UDataAbility*> GetPreviousAbilites() { return PreviousAbility; }

	bool AccessAbility();


};

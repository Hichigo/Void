// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "AbilityStructures.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EAbilityType : uint8 {
	Passive,
	Active,
	Stance,
	Improve
};


USTRUCT(BlueprintType)
struct FAbility {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 ID;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EAbilityType Type;

};

UCLASS()
class ISLANDOFTHEVOID_API UAbilityStructures : public UObject
{
	GENERATED_BODY()
	
	
	
	
};

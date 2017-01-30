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
	Improve,
	RootBranch
};


USTRUCT(BlueprintType)
struct FAbility {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAbilityType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> PrevAbilityId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> NextAbilityId;
};

UCLASS()
class ISLANDOFTHEVOID_API UAbilityStructures : public UObject
{
	GENERATED_BODY()
	
	
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "AbilityStructures.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EAbilityType : uint8 {
	/** passive ability */
	Passive,

	/** active ability */
	Active,

	/** stance ability */
	Stance,

	/** improve ability */
	Improve,

	/** begin ability in branch */
	RootBranch
};

/** Information about ability */
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
	bool bIsTake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTake;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Price;

};

UCLASS()
class ISLANDOFTHEVOID_API UAbilityStructures : public UObject
{
	GENERATED_BODY()
	
	
	
	
};

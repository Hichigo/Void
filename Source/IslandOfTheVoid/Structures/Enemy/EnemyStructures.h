// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "Structures/Hero/HeroStructures.h"
#include "EnemyStructures.generated.h"


/**
* Enumeration for action enemy character
*/
UENUM(BlueprintType)
enum class EActionEnemy : uint8
{
	Idle,
	Wander,
	Patrol,
	Chase,
	Attack,
	Search
};



/**
* Enemy stats
*/
USTRUCT(BlueprintType)
struct FEnemyStats
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBaseStats BaseStats;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Damage;

	/**
	* Total health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart Total;

	/**
	* Total Endurance
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBar Endurance;

	/**
	* Head health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart Head;

	/**
	* Body health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart Body;

	/**
	* Left arm health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart LeftArm;

	/**
	* Right arm health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart RightArm;

	/**
	* Left leg health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart LeftLeg;

	/**
	* Right leg health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart RightLeg;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EActionEnemy MainAction;
};
/**
 * 
 */
UCLASS()
class ISLANDOFTHEVOID_API UEnemyStructures : public UObject
{
	GENERATED_BODY()
	
	
	
	
};

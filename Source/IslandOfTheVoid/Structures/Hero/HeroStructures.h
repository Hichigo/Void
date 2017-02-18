// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "HeroStructures.generated.h"


/**
* Enumeration for move type character
*/
UENUM(BlueprintType)
enum class EMoveType : uint8
{
	Running,
	Walking,
	Crouching,
	Crawling
};

/**
* Enumeration where attack enemy or character
*/
UENUM(BlueprintType)
enum class EWhereAttack : uint8
{
	Head,
	Body,
	LeftArm,
	RightArm,
	LeftLeg,
	RightLeg,
	AllPart
};


/**
 * Struct for progress bar like a health or Endurance etc.
 */
USTRUCT(BlueprintType)
struct FBar {
	GENERATED_USTRUCT_BODY()

	/**
	* Current value <= Max
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Current;

	/**
	 * Maximum value	
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Max;
};

/**
* Struct for damage between min and max
*/
USTRUCT(BlueprintType)
struct FDamage {
	GENERATED_USTRUCT_BODY()

	/**
	* Current value <= Max
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Min;

	/**
	* Maximum value
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Max;
};

/**
* Physical resist
*/
USTRUCT(BlueprintType)
struct FPhysicalResist {
	GENERATED_USTRUCT_BODY()

	/**
	* Resist stabbing damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Stab;

	/**
	* Resist crushing damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Crush;

	/**
	* Resist chopping damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Chop;

	/**
	* Resist cutting damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Cut;
};

/**
* Magic resist
*/
USTRUCT(BlueprintType)
struct FMagicResist {
	GENERATED_USTRUCT_BODY()

	/**
	* Resist fire damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Fire;

	/**
	* Resist cold damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Cold;

	/**
	* Resist lightning damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Lightning;

	/**
	* Resist poison damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Poison;
};

/**
* Physical damage
*/
USTRUCT(BlueprintType)
struct FPhysicalDamage {
	GENERATED_USTRUCT_BODY()

	/**
	* Stabbing damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Stab;

	/**
	* Crushing damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Crush;

	/**
	* Chopping damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Chop;

	/**
	* Cutting damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Cut;
};

/**
* Magic damage
*/
USTRUCT(BlueprintType)
struct FMagicDamage {
	GENERATED_USTRUCT_BODY()

	/**
	* Fire damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Fire;

	/**
	* Cold damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Cold;

	/**
	* Lightning damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Lightning;

	/**
	* Poison damage
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FDamage Poison;
};

/**
* Body part character attributes
*/
USTRUCT(BlueprintType)
struct FBodyPart {
	GENERATED_USTRUCT_BODY()

	/**
	* Health part
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBar Health;

	/**
	* Physical resist part
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FPhysicalResist PhysicalResist;

	/**
	* Magic resist part
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMagicResist MagicResist;
};

/**
* Movement struct
*/
USTRUCT(BlueprintType)
struct FMovement {
	GENERATED_USTRUCT_BODY()

	/**
	* Move type
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EMoveType Type;

	/**
	* Running speed
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RunSpeed;

	/**
	* Walking speed
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float WalkSpeed;

	/**
	* Crouching speed
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CrouchSpeed;

	/**
	* Crawling speed
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float CrawlSpeed;

};

/**
* Standalone stat in base stats
*/
USTRUCT(BlueprintType)
struct FStat {
	GENERATED_USTRUCT_BODY()

	/**
	* Text name stat
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FText NameStat;

	/**
	* Number of points stat
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Points;

	/**
	* Price for increase
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Price;


	/**
	* Price for increase
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 BasePrice;

	/**
	* The coefficient for attributes that did not increase
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float MinFactor;

	/**
	* The coefficient for attributes that did increase
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float MaxFactor;

public:

	void CalculateNewPriceMin()
	{
		Price += BasePrice * MinFactor;
	}

	void CalculateNewPriceMax()
	{
		Price += BasePrice * MaxFactor;
	}
};


/**
* Main character base stats
*/
USTRUCT(BlueprintType)
struct FBaseStats {
	GENERATED_USTRUCT_BODY()

	/**
	* Health stat
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FStat Health;

	/**
	* Endurance stat
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FStat Endurance;

	/**
	* Strength stat
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FStat Strength;

	/**
	* Agility stat
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FStat Agility;

	/**
	* Intelligence stat
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FStat Intelligence;

	/**
	* Coefficient health per one point
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float KHealth;

	/**
	* Regenration per second health
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RegenerationHealth;

	/**
	* Regenration per second Endurance
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RegenerationEndurance;
};

/**
* Main character stats
*/
USTRUCT(BlueprintType)
struct FHeroStats {
	GENERATED_USTRUCT_BODY()

	/**
	* Base stats character
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBaseStats BaseStats;

	/**
	* Experience character
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Experience;

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

	/**
	* Hero movement
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FMovement Movement;

public:
	/** Recalculate health  */
	void RecalculateBodyPartHealth()
	{
		Total.Health.Max = BaseStats.Health.Points * BaseStats.KHealth;

		Total.Health.Current = Total.Health.Max;
		
		float LimbsHealth = Total.Health.Max / 4.0f;
		
		Head.Health.Current = Total.Health.Max;
		Body.Health.Current = Total.Health.Max;

		LeftArm.Health.Current = LimbsHealth;
		RightArm.Health.Current = LimbsHealth;
		LeftLeg.Health.Current = LimbsHealth;
		RightLeg.Health.Current = LimbsHealth;

		Head.Health.Max = Total.Health.Max;
		Body.Health.Max = Total.Health.Max;

		LeftArm.Health.Max = LimbsHealth;
		RightArm.Health.Max = LimbsHealth;
		LeftLeg.Health.Max = LimbsHealth;
		RightLeg.Health.Max = LimbsHealth;

	}
};

UCLASS()
class ISLANDOFTHEVOID_API UHeroStructures : public UObject
{
	GENERATED_BODY()
	
	
	
	
};

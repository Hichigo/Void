// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "HeroStructures.generated.h"



/**
* AI character enum for actions via behavior tree
*/
UENUM(BlueprintType)
enum class EBTCharacterActions : uint8
{
	Idle,
	WalkRun,
	Attack,
	Defence
};

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Current;

	/**
	 * Maximum value	
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Min;

	/**
	* Maximum value
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Stab;

	/**
	* Resist crushing damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Crush;

	/**
	* Resist chopping damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Chop;

	/**
	* Resist cutting damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Fire;

	/**
	* Resist cold damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Cold;

	/**
	* Resist lightning damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Lightning;

	/**
	* Resist poison damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDamage Stab;

	/**
	* Crushing damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDamage Crush;

	/**
	* Chopping damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDamage Chop;

	/**
	* Cutting damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDamage Fire;

	/**
	* Cold damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDamage Cold;

	/**
	* Lightning damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDamage Lightning;

	/**
	* Poison damage
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBar Health;

	/**
	* Physical resist part
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FPhysicalResist PhysicalResist;

	/**
	* Magic resist part
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMoveType Type;

	/**
	* Running speed
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunSpeed;

	/**
	* Walking speed
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkSpeed;

	/**
	* Crouching speed
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CrouchSpeed;

	/**
	* Crawling speed
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText NameStat;

	/**
	* Number of points stat
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Points;

	/**
	* Price for increase
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Price;


	/**
	* Price for increase
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 BasePrice;

	/**
	* The coefficient for attributes that did not increase
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinFactor;

	/**
	* The coefficient for attributes that did increase
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStat Health;

	/**
	* Endurance stat
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStat Endurance;

	/**
	* Strength stat
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStat Strength;

	/**
	* Agility stat
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStat Agility;

	/**
	* Intelligence stat
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStat Intelligence;

	/**
	* Coefficient health per one point
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float KHealth;

	/**
	* Regenration per second health
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RegenerationHealth;

	/**
	* Regenration per second Endurance
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBaseStats BaseStats;

	/**
	* Experience character
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Experience;

	/**
	* Total health and resist
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBodyPart Total;
	
	/**
	* Total Endurance
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBar Endurance;

	/**
	* Head health and resist
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBodyPart Head;

	/**
	* Body health and resist
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBodyPart Body;

	/**
	* Left arm health and resist
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBodyPart LeftArm;

	/**
	* Right arm health and resist
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBodyPart RightArm;

	/**
	* Left leg health and resist
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBodyPart LeftLeg;

	/**
	* Right leg health and resist
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBodyPart RightLeg;

	/**
	* Hero movement
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
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

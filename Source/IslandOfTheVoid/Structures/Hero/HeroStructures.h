// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "HeroStructures.generated.h"


/**
* Struct for progress bar like a health or vitality etc.
*/
UENUM(BlueprintType)
enum class EMoveType : uint8
{
	Runnig,
	Walking,
	Crouching,
	Crawling
};


/**
 * Struct for progress bar like a health or vitality etc.
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
	float Run;

	/**
	* Walking speed
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Walk;

	/**
	* Crouching speed
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Crouch;

	/**
	* Crawling speed
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float Crawl;

};
/**
* Main character stats
*/
USTRUCT(BlueprintType)
struct FHeroStats {
	GENERATED_USTRUCT_BODY()

	/**
	* Total health and resist
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FBodyPart Total;

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

};

UCLASS()
class ISLANDOFTHEVOID_API UHeroStructures : public UObject
{
	GENERATED_BODY()
	
	
	
	
};

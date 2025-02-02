// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Character/Ability/DataAbility.h"
#include "Character/Component/StatComponent.h"
//#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISLANDOFTHEVOID_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityComponent();

	/** Data strength ability id: 0-999 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Ability")
	TArray<UDataAbility*> StrengthAbility;

	/** Data agility ability id: 1000-1999 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Ability")
	TArray<UDataAbility*> AgilityAbility;

	/** Data intelligence ability id: 2000-2999 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hero|Ability")
	TArray<UDataAbility*> IntelligenceAbility;

	/** Find ability by id and return finded ability else return root ability */
	UFUNCTION(BlueprintCallable, Category = "Hero|Ability")
	UDataAbility* FindAbilityById(TArray<UDataAbility*> Ability, int32 index) const;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:


};

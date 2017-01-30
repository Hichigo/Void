// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Character/Ability/DataAbility.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ISLANDOFTHEVOID_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilityComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UDataAbility*> StrengthAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UDataAbility*> AgilityAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UDataAbility*> IntelligenceAbility;

	/*UDataAbility*/void FindAbilityById(TArray<UDataAbility*> Ability, int32 index) const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};

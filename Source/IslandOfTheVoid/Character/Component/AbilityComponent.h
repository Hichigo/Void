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

	UPROPERTY(EditAnywhere)
	TArray<UDataAbility*> StrengthAbility;

	UPROPERTY(EditAnywhere)
	TArray<UDataAbility*> AgilityAbility;

	UPROPERTY(EditAnywhere)
	TArray<UDataAbility*> IntelligenceAbility;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Structures/Hero/AbilityStructures.h"
#include "Engine/DataAsset.h"
#include "DataAbility.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDOFTHEVOID_API UDataAbility : public UDataAsset
{
	GENERATED_BODY()
	
	
public:

	UPROPERTY(EditAnywhere)
	FAbility CurrentAbility;

};

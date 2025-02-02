// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "AbilityComponent.h"



// Sets default values for this component's properties
UAbilityComponent::UAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


UDataAbility* UAbilityComponent::FindAbilityById(TArray<UDataAbility*> ArrayAbility, int32 SearchIndex) const
{
	for (int32 Index = 0; Index != ArrayAbility.Num(); ++Index)
	{
		if (ArrayAbility[Index]->AbilityInfo.ID == SearchIndex)
		{
			return ArrayAbility[Index];
		}
	}

	return nullptr;
}

// Called when the game starts
void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


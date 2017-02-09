// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "DataAbility.h"



UDataAbility::UDataAbility()
{

}

bool UDataAbility::AccessAbility()
{
	if(PreviousAbility.Num())
	{
		bool IsMayTake = true;
		for (int32 Index = 0; Index < PreviousAbility.Num(); ++Index)
		{
			if (!PreviousAbility[Index]->AbilityInfo.bIsTake)
			{
				return false;
			}
		}
		AbilityInfo.bCanTake = true;
		return true;
	}
	return false;
}

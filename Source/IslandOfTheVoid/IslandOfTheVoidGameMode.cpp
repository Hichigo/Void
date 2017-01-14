// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "IslandOfTheVoid.h"
#include "IslandOfTheVoidGameMode.h"
#include "IslandOfTheVoidPlayerController.h"
#include "IslandOfTheVoidCharacter.h"

AIslandOfTheVoidGameMode::AIslandOfTheVoidGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AIslandOfTheVoidPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
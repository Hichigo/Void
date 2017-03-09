// Fill out your copyright notice in the Description page of Project Settings.

#include "IslandOfTheVoid.h"
#include "VoidGameMode.h"



AVoidGameMode::AVoidGameMode()
{
	DefaultPawnClass = AVoidCharacter::StaticClass();
	PlayerControllerClass = AVoidPlayerController::StaticClass();
}

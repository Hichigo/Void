// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "VoidPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDOFTHEVOID_API AVoidPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	AVoidPlayerController(const FObjectInitializer& ObjectInitializer);
	
private:

	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	/** Move character to cursor */
	void OnRightMousePressed();

};

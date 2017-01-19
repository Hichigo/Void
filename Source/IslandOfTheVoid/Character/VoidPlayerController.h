// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VoidCharacter.h"
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
	
	/** Speed camera tilt */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera Setting")
	float SpeedCameraTilt;


private:
	/** If true can camera rotation pitch and yaw */
	bool bCameraRotation;

	/** Reference main character */
	AVoidCharacter *CharacterRef;

	/** Tick event */
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	virtual void BeginPlay() override;

	/** Move character to cursor */
	void OnRightMousePressed();

	/** Middle mouse button pressed */
	void OnMiddleMousePressed();

	/** Middle mouse button release */
	void OnMiddleMouseRelease();

	/** The camera pitch rotation */
	void OnCameraTilt(float Value);

	/** The camera yaw rotation */
	void OnCameraRotation(float Value);
};

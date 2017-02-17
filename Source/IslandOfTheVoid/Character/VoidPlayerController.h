// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "VoidCharacter.h"
#include "Component/StatComponent.h"
#include "Component/AbilityComponent.h"
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

	/** Speed camera zoom */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Setting")
	float SpeedCameraZoom;
	
	/** Returns Ability component subobject **/
	FORCEINLINE class UAbilityComponent* GetAbility() const { return Ability; }

	/** Returns Stat component subobject **/
	FORCEINLINE class UStatComponent* GetStat() const { return Stat; }

	/*
	Найти нужный навык
	проверить хватает ли для его прокачки опыта
	если хватает прокачать
	открыть доступ к следующему/щим навыкам

	если не хватает ничего не делать
	*/
	UFUNCTION(BlueprintCallable, Category = "Hero|Ability")
	TArray<int32> TakeAbility(TArray<UDataAbility*> ArrayAbility, int32 SearchIndex);

private:
	/** If true can camera rotation pitch and yaw */
	bool bCameraRotation;

	/** Where the character goes */
	FVector Goal;

	/** Reference main character */
	AVoidCharacter *CharacterRef;

	/** Remember mouse position when rotate camera */
	FVector2D MousePosition;

	/** Stat component character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats", meta = (AllowPrivateAccess = "true"))
	class UStatComponent* Stat;

	/** Stat component character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability", meta = (AllowPrivateAccess = "true"))
	class UAbilityComponent* Ability;

	/** Tick event */
	virtual void PlayerTick(float DeltaTime) override;

	/** Binding input */
	virtual void SetupInputComponent() override;

	/** Begin play event */
	virtual void BeginPlay() override;

	/** Move character to cursor */
	void MoveCharacterToCursor();

	/** Walk character to cursor */
	void OnRightMousePressed();

	/** Run character to cursor */
	void OnRightMouseDoublePressed();

	/** Middle mouse button pressed */
	void OnMiddleMousePressed();

	/** Middle mouse button release */
	void OnMiddleMouseRelease();

	/** The camera pitch rotation */
	void OnCameraTilt(float Value);

	/** The camera yaw rotation */
	void OnCameraRotation(float Value);

	/** The camera zoom up or down */
	void OnCameraZoom(float Value);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Enemy/AI_Base.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "AIController_Base.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDOFTHEVOID_API AAIController_Base : public AAIController
{
	GENERATED_BODY()

	AAIController_Base(const FObjectInitializer& ObjectInitializer);

public:
	virtual void BeginPlay() override;

private:
	AAI_Base *Pawn;
	
	EActionEnemy MainAction;
	
	UPROPERTY(VisibleAnywhere)
	UAIPerceptionComponent *AIPerception;

	UPROPERTY(VisibleAnywhere)
	UAISenseConfig_Sight* SightConfig;

	//TScriptDelegate<> Sence;

	void OnSenceUpdated(TArray<AActor*> Actors);
	void OnTartgetSenceUpdated(AActor *Actors, FAIStimulus Stimulus);
};

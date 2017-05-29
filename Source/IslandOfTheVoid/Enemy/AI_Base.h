// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Structures/Enemy/EnemyStructures.h"
#include "Enemy/AI_PathPatrol.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "AI_Base.generated.h"


UCLASS()
class ISLANDOFTHEVOID_API AAI_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION()
	void CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
	void CustomOnEndMouseOver(UPrimitiveComponent* TouchedComponent);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy")
	FEnemyStats MainStats;

	UPROPERTY(EditAnywhere, Category = "Behavior")
	EActionEnemy MainAction;

	UPROPERTY(EditAnywhere, Category = "Behavior")
	EPatrolDirection PatrolDirection;

	UPROPERTY(EditAnywhere, Category = "Behavior")
	class UBehaviorTree *BehaviorTree;

	UPROPERTY(EditAnywhere, Category = "Behavior")
	class AAI_PathPatrol *PatrolPath;

	UPROPERTY(EditAnywhere, Category = "Behavior")
	int32 StartPointPatrol;

	FORCEINLINE AAI_PathPatrol* GetPathPatrol() const { return PatrolPath; }

};

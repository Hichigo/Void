// Fill out your copyright notice in the Description page of Project Settings.

#pragma once




/**
* Enumeration for move type character
*/
UENUM(BlueprintType)
enum class EActionEnemy : uint8
{
	Idle,
	Wander,
	Patrol,
	Chase,
	Attack,
	Search
};



/**
 * 
 */
class ISLANDOFTHEVOID_API EnemyStructures
{
public:
	EnemyStructures();
	~EnemyStructures();
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PRUEBATECNICA_API ATestGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SpawnActors(TArray<AActor*> Spawners, TSubclassOf<AActor> ActorToSpawnClass, int32 SpawnCount, float Lifetime);
};

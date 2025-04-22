// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TestGameMode.generated.h"

class ASpawner;
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpawnCalled, int32, SpawnCount, float, Lifetime);
UCLASS()
class PRUEBATECNICA_API ATestGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SendSpawnMessage(int32 SpawnCount, float Lifetime);

	UPROPERTY(BlueprintAssignable)
	FOnSpawnCalled OnSpawnCalled;
};

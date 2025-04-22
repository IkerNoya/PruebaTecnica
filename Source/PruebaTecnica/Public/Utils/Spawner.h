// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class ASpawnArea;

UCLASS()
class PRUEBATECNICA_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	ASpawner();

	UFUNCTION()
	void ExecuteSpawn(int32 Amount, float Lifetime);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<AActor> ActorToSpawn;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TArray<ASpawnArea*> SpawnPoints;

	UPROPERTY(VisibleAnywhere, Category = "Spawner")
	TArray<AActor*> SpawnedActors;
};

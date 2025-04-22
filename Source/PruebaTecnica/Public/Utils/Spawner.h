// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class ASpawnableActor;
class ASpawnArea;

UCLASS()
class PRUEBATECNICA_API ASpawner : public AActor
{
	GENERATED_BODY()

public:
	ASpawner();

	/** Function that begins spawning process */
	UFUNCTION()
	void ExecuteSpawn(int32 Amount, float Lifetime);

protected:
	virtual void BeginPlay() override;

	/** Class of actor we want to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<AActor> ActorToSpawn;	

	/** Array of spawn points to be used for spawning */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TArray<ASpawnArea*> SpawnAreas;

	/** Array of spawned actors to be reused for object pooling */
	UPROPERTY(VisibleAnywhere, Category = "Spawner")
	TArray<ASpawnableActor*> SpawnedActors;
};

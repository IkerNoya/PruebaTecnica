// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnArea.generated.h"

class UBoxComponent;

UCLASS()
class PRUEBATECNICA_API ASpawnArea : public AActor
{
	GENERATED_BODY()

public:
	ASpawnArea();

	/** Gets random spawn location within spawn area */
	UFUNCTION(BlueprintCallable, Category = "Spawner")
	FVector GetRandomSpawnLocation() const;

protected:
	/** Radius to check for a valid point in NavMesh when finding random point in area */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SpawnArea")
	float LocationCheckRadius = 200.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SpawnArea")
	UBoxComponent* SpawnArea;
	
};

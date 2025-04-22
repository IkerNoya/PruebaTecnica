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

	UFUNCTION(BlueprintCallable, Category = "Spawner")
	FVector GetRandomSpawnLocation() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SpawnArea")
	UBoxComponent* SpawnArea;
	
};

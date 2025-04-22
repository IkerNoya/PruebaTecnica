// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnableActor.generated.h"

UCLASS()
class PRUEBATECNICA_API ASpawnableActor : public AActor
{
	GENERATED_BODY()

public:
	ASpawnableActor();

	virtual void SetLifeSpan(float InLifespan) override;

	bool IsActive() const { return bIsActive; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class UStaticMeshComponent* Mesh;
private:
	void OnLifeSpanExpired();

	bool bIsActive = false;
	
	FTimerHandle HandleToDeactivate;
};

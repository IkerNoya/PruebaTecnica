// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/Spawner.h"

#include "NavigationSystem.h"
#include "GameModes/TestGameMode.h"
#include "Utils/SpawnArea.h"


ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASpawner::ExecuteSpawn(int32 Amount, float Lifetime)
{
	for (int32 i = 0; i < Amount; i++)
	{
		int32 RandomIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);
		const FVector SpawnLocation = SpawnPoints[RandomIndex]->GetRandomSpawnLocation();
		FRotator SpawnRotation = FRotator::ZeroRotator;
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		if (AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, SpawnRotation, SpawnParameters))
		{
			SpawnedActor->SetLifeSpan(Lifetime);
		}	
	}
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();

	if (ATestGameMode* GameMode = GetWorld()->GetAuthGameMode<ATestGameMode>())
	{
		GameMode->OnSpawnCalled.AddDynamic(this, &ASpawner::ExecuteSpawn);
	}
}
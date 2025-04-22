// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/Spawner.h"

#include "NavigationSystem.h"
#include "Actor/SpawnableActor.h"
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
		int32 RandomIndex = FMath::RandRange(0, SpawnAreas.Num() - 1);
		const FVector SpawnLocation = SpawnAreas[RandomIndex]->GetRandomSpawnLocation();
		FRotator SpawnRotation = FRotator::ZeroRotator;
		
		// Check if I can use deactivated actors before trying to spawn new ones
		if (SpawnedActors.Num() > 0 && i < SpawnedActors.Num() && !SpawnedActors[i]->IsActive())
		{
			SpawnedActors[i]->SetActorLocation(SpawnLocation);
			SpawnedActors[i]->SetActorRotation(SpawnRotation);
			SpawnedActors[i]->SetLifeSpan(Lifetime);
			continue;
		}
		
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = this;
		if (ASpawnableActor* SpawnedActor = GetWorld()->SpawnActor<ASpawnableActor>(ActorToSpawn, SpawnLocation, SpawnRotation, SpawnParameters))
		{
			SpawnedActor->SetLifeSpan(Lifetime);
			SpawnedActors.Add(SpawnedActor);
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
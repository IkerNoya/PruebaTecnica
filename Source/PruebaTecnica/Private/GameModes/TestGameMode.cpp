// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/TestGameMode.h"

#include "Utils/Spawner.h"

void ATestGameMode::SendSpawnMessage(int32 SpawnCount, float Lifetime)
{
	if (OnSpawnCalled.IsBound())
	{
		OnSpawnCalled.Broadcast(SpawnCount, Lifetime);
	}
}

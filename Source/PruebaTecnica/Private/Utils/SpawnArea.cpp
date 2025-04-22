// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/SpawnArea.h"

#include "NavigationSystem.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"


ASpawnArea::ASpawnArea()
{
	PrimaryActorTick.bCanEverTick = false;
	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	SetRootComponent(SpawnArea);
}

FVector ASpawnArea::GetRandomSpawnLocation() const
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (!NavSys)
	{
		return FVector::ZeroVector;
	}

	// Check random point inside the box, and then try to find a valid point in the NavMesh to avoid clipping or actor spawning mid air
	FNavLocation NavLocation;
	FBoxSphereBounds BoxBounds = SpawnArea->Bounds;
	FVector Location = UKismetMathLibrary::RandomPointInBoundingBox(BoxBounds.Origin, BoxBounds.BoxExtent);
	NavSys->GetRandomPointInNavigableRadius(Location, LocationCheckRadius, NavLocation);
	return NavLocation.Location;
}


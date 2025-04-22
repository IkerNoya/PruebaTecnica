// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/SpawnArea.h"

#include "NavigationSystem.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"


ASpawnArea::ASpawnArea()
{
	PrimaryActorTick.bCanEverTick = false;
	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
}

FVector ASpawnArea::GetRandomSpawnLocation() const
{
	UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (!NavSys)
	{
		return FVector::ZeroVector;
	}
	
	FNavLocation NavLocation;
	FBoxSphereBounds BoxBounds = SpawnArea->Bounds;
	FVector Location = UKismetMathLibrary::RandomPointInBoundingBox(BoxBounds.Origin, BoxBounds.BoxExtent);
	NavSys->GetRandomPointInNavigableRadius(Location, 200.0f, NavLocation);
	return NavLocation.Location;
}


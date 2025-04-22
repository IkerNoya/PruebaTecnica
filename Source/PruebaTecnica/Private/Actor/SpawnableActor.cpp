// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/SpawnableActor.h"

ASpawnableActor::ASpawnableActor()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
}

void ASpawnableActor::SetLifeSpan(float InLifespan)
{
	GetWorld()->GetTimerManager().SetTimer(HandleToDeactivate, this, &ASpawnableActor::OnLifeSpanExpired, InLifespan);
	Mesh->SetVisibility(true);
	bIsActive = true;
}

void ASpawnableActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetVisibility(false);
}

void ASpawnableActor::OnLifeSpanExpired()
{
	SetActorLocation(FVector::Zero());
	Mesh->SetVisibility(false);
	bIsActive = false;
}

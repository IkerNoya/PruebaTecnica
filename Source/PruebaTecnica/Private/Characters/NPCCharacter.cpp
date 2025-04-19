// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPCCharacter.h"

#include "Components/SphereComponent.h"


ANPCCharacter::ANPCCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ANPCCharacter::OnInteract_Implementation()
{
	Super::OnInteract_Implementation();
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPCCharacter.h"

ANPCCharacter::ANPCCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANPCCharacter::OnInteract_Implementation(AActor* InteractedBy)
{
	UE_LOG(LogTemp, Warning, TEXT("%s was interacted by %s"), *GetName(), *InteractedBy->GetName());
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/NPCCharacter.h"

#include "GameModes/TestGameMode.h"
#include "UI/PlayerHUD.h"

ANPCCharacter::ANPCCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ANPCCharacter::OnInteract_Implementation(AActor* InteractedBy)
{
	ABaseCharacter* BaseCharacter = Cast<ABaseCharacter>(InteractedBy);
	if (!BaseCharacter)
	{
		return;
	}
	
	APlayerController* PlayerController = BaseCharacter->GetController<APlayerController>();
	if (!PlayerController)
	{
		return;
	}

	if (APlayerHUD* HUD = PlayerController->GetHUD<APlayerHUD>())
	{
		HUD->ShowSpawnWidget();
	}
}


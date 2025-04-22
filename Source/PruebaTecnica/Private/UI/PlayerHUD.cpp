// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUD.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/Character.h"
#include "GameModes/TestGameMode.h"
#include "UI/SpawnerWidget.h"

void APlayerHUD::ShowSpawnWidget()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);

	PlayerController->SetIgnoreMoveInput(true);
	PlayerController->bShowMouseCursor = true;
	PlayerController->SetInputMode(InputMode);
	
	SpawnWidget = CreateWidget<USpawnerWidget>(PlayerController, SpawnWidgetClass);
	SpawnWidget->OnWidgetClose.AddDynamic(this, &APlayerHUD::HideSpawnWidget);
	SpawnWidget->OnExecuteSpawn.AddDynamic(this, &APlayerHUD::OnSpawn);
	SpawnWidget->AddToViewport();
}

void APlayerHUD::HideSpawnWidget()
{
	if (!SpawnWidget)
	{
		return;
	}
	SpawnWidget->OnWidgetClose.RemoveDynamic(this, &APlayerHUD::HideSpawnWidget);
	SpawnWidget->OnExecuteSpawn.RemoveDynamic(this, &APlayerHUD::OnSpawn);
	SpawnWidget->RemoveFromParent();
	SpawnWidget = nullptr;


	PlayerController->SetIgnoreMoveInput(false);
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(FInputModeGameOnly());
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetOwner());
	GameMode = GetWorld()->GetAuthGameMode<ATestGameMode>();
}

void APlayerHUD::OnSpawn(int32 Amount, float Lifetime)
{
	if (Amount <= 0 || Lifetime <= 0)
	{
		return;
	}
	
	GameMode->SendSpawnMessage(Amount, Lifetime);
}

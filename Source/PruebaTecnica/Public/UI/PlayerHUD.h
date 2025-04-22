// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class ATestGameMode;
class USpawnerWidget;
/**
 * 
 */
UCLASS()
class PRUEBATECNICA_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ShowSpawnWidget();

	UFUNCTION(BlueprintCallable)
	void HideSpawnWidget();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSpawn(int32 Amount, float Lifetime);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> SpawnWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TObjectPtr<USpawnerWidget> SpawnWidget;

private:
	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY()
	ATestGameMode* GameMode;
};

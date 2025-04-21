// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpawnerWidget.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClose);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnExecuteSpawn, int32, Amount, float, Lifetime);

UCLASS()
class PRUEBATECNICA_API USpawnerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnClose OnWidgetClose;

	UPROPERTY(BlueprintAssignable)
	FOnExecuteSpawn OnExecuteSpawn;

protected:	
	UFUNCTION(BlueprintCallable)
	void ExecuteSpawn();

	UFUNCTION(BlueprintCallable)
	void OnClose();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmountToSpawn = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = 1.0, UIMin = 1.0))
	float Lifetime = 1.0f;
};

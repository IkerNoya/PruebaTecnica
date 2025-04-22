// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE()
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface to make actors interactable
 */
class PRUEBATECNICA_API IInteractionInterface
{
	GENERATED_BODY()

public:
	/** Functions that activates when actor is interacted by another one */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnInteract(AActor* InteractedBy);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "NPCCharacter.generated.h"

class USphereComponent;

UCLASS()
class PRUEBATECNICA_API ANPCCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ANPCCharacter();

protected:
	virtual void OnInteract_Implementation(AActor* InteractedBy) override;

};

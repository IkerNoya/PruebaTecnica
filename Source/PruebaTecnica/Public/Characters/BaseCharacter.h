// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/InteractionInterface.h"
#include "BaseCharacter.generated.h"

UCLASS()
class PRUEBATECNICA_API ABaseCharacter : public ACharacter, public IInteractionInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	void OnInteract_Implementation(AActor* InteractedBy) override;

protected:

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnInteractionSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnInteractionSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class USphereComponent* InteractionSphere;
};

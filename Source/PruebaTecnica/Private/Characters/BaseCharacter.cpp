// Fill out your copyright notice in the Description page of Project Settings.


#include "PruebaTecnica/Public/Characters/BaseCharacter.h"

#include "Components/SphereComponent.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetupAttachment(GetRootComponent());
	InteractionSphere->SetSphereRadius(180.0f);
}



void ABaseCharacter::OnInteract_Implementation(AActor* InteractedBy)
{
	IInteractionInterface::OnInteract_Implementation(InteractedBy);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	InteractionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABaseCharacter::OnInteractionSphereOverlap);
	InteractionSphere->OnComponentEndOverlap.AddDynamic(this, &ABaseCharacter::OnInteractionSphereOverlapEnd);
}

void ABaseCharacter::OnInteractionSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void ABaseCharacter::OnInteractionSphereOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

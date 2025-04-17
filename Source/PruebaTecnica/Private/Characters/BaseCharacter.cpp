// Fill out your copyright notice in the Description page of Project Settings.


#include "PruebaTecnica/Public/Characters/BaseCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"


ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(GetCapsuleComponent());
	SpringArmComponent->TargetArmLength = 400.0f;
	SpringArmComponent->bUsePawnControlRotation = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//Add mapping context to PlayerController
	if (APlayerController* PlayerController = Cast<APlayerController>(NewController))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}	
}

void ABaseCharacter::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MoveValue = InputActionValue.Get<FVector2D>();
	const FRotator RotationValue(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (!FMath::IsNearlyZero(MoveValue.X, 0.05f))
	{
		const FVector Direction = RotationValue.RotateVector(FVector::RightVector);
		AddMovementInput(Direction, MoveValue.X);
	}

	if (!FMath::IsNearlyZero(MoveValue.Y, 0.05f))
	{
		const FVector Direction = RotationValue.RotateVector(FVector::ForwardVector);
		AddMovementInput(Direction, MoveValue.Y);
	}
}

void ABaseCharacter::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookValue = InputActionValue.Get<FVector2D>();

	if (!FMath::IsNearlyZero(LookValue.X, 0.05f))
	{
		AddControllerYawInput(LookValue.X);
	}

	if (!FMath::IsNearlyZero(LookValue.Y, 0.05f))
	{
		AddControllerPitchInput(LookValue.Y);
	}
}

void ABaseCharacter::Interact()
{
	//TODO: Handle interaction
}

void ABaseCharacter::ToggleWalk(const FInputActionValue& InputActionValue)
{
	const bool bIsWalking = InputActionValue.Get<bool>();
	const float WalkSpeed = bIsWalking ? 250.0f : 500.0f;
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Move);
	
		EnhancedInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Look);
	
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Jump);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Completed, this, &ABaseCharacter::StopJumping);
	
		EnhancedInputComponent->BindAction(InteractInputAction, ETriggerEvent::Triggered, this, &ABaseCharacter::Interact);
	
		EnhancedInputComponent->BindAction(ToggleWalkInputAction, ETriggerEvent::Triggered, this, &ABaseCharacter::ToggleWalk);
	}
}


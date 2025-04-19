// Fill out your copyright notice in the Description page of Project Settings.


#include "PruebaTecnica/Public/Characters/PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"


APlayerCharacter::APlayerCharacter()
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

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::PossessedBy(AController* NewController)
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

void APlayerCharacter::OnInteract_Implementation()
{
	Super::OnInteract_Implementation();
}

void APlayerCharacter::Move(const FInputActionValue& InputActionValue)
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

void APlayerCharacter::Look(const FInputActionValue& InputActionValue)
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

void APlayerCharacter::Interact()
{
	//TODO: Handle interaction
}

void APlayerCharacter::ToggleWalk(const FInputActionValue& InputActionValue)
{
	const bool bIsWalking = InputActionValue.Get<bool>();
	const float CurrentSpeed = GetCharacterMovement()->MaxWalkSpeed;
	const float NewSpeed = bIsWalking ? 250.0f : 500.0f;
	GetCharacterMovement()->MaxWalkSpeed = NewSpeed;
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	
		EnhancedInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
	
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Jump);
		EnhancedInputComponent->BindAction(JumpInputAction, ETriggerEvent::Completed, this, &APlayerCharacter::StopJumping);
	
		EnhancedInputComponent->BindAction(InteractInputAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Interact);
	
		EnhancedInputComponent->BindAction(ToggleWalkInputAction, ETriggerEvent::Triggered, this, &APlayerCharacter::ToggleWalk);
	}
}


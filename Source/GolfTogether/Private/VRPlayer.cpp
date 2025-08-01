// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"

AVRPlayer::AVRPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AVRPlayer::BeginPlay()
{
	Super::BeginPlay();

}

void AVRPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

void AVRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Is controlling player
	if (IsLocallyControlled())
	{
		if (UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
		{
			//Setup input actions
			input->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &AVRPlayer::ProcessMovement);
			input->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &AVRPlayer::ProcessLooking);
		}
	}
}

void AVRPlayer::ProcessMovement(const FInputActionInstance& Instance)
{
	FVector2D InputValue = Instance.GetValue().Get<FVector2D>();
	FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();

	AddMovementInput(RightVector, InputValue.X);
	AddMovementInput(ForwardVector, InputValue.Y);
}

void AVRPlayer::ProcessLooking(const FInputActionInstance& Instance)
{
	FVector2D InputValue = Instance.GetValue().Get<FVector2D>();
	AddControllerYawInput(InputValue.X);
}
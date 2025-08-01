// Fill out your copyright notice in the Description page of Project Settings.


#include "NonVRPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"

ANonVRPlayer::ANonVRPlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANonVRPlayer::BeginPlay()
{
	Super::BeginPlay();

}

void ANonVRPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

void ANonVRPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANonVRPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Is controlling player
	if (IsLocallyControlled())
	{
		if (UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
		{
			//Setup input actions
			input->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &ANonVRPlayer::ProcessMovement);
			input->BindAction(LookAction.Get(), ETriggerEvent::Triggered, this, &ANonVRPlayer::ProcessLooking);
		}
	}	
}

void ANonVRPlayer::ProcessMovement(const FInputActionInstance& Instance)
{
	FVector2D InputValue = Instance.GetValue().Get<FVector2D>();
	FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();

	AddMovementInput(RightVector, InputValue.X);
	AddMovementInput(ForwardVector, InputValue.Y);
}

void ANonVRPlayer::ProcessLooking(const FInputActionInstance& Instance)
{
	FVector2D InputValue = Instance.GetValue().Get<FVector2D>();

	AddControllerPitchInput(-InputValue.Y);
	AddControllerYawInput(InputValue.X);
}
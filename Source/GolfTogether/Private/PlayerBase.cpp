// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize components
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera component"));
	CameraComponent->SetupAttachment(RootComponent);
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
	// Is controlling player
	if (IsLocallyControlled())
	{
		// Setup input mapping context
		if (APlayerController* controller = Cast<APlayerController>(GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSystem = controller->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (!InputMapping.IsNull())
				{
					InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 1);
				}
			}
		}
	}
}

void APlayerBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBase.h"
#include "InputAction.h"
#include "VRPlayer.generated.h"

class UInputComponent;

/**
 *
 */
UCLASS()
class GOLFTOGETHER_API AVRPlayer : public APlayerBase
{
	GENERATED_BODY()

	// Members
public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TSoftObjectPtr<UInputAction> MoveAction = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TSoftObjectPtr<UInputAction> LookAction = nullptr;

	// Methods
public:
	AVRPlayer();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	void ProcessMovement(const FInputActionInstance& Instance);
	void ProcessLooking(const FInputActionInstance& Instance);
};


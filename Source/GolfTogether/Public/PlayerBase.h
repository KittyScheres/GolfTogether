// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerBase.generated.h"

class UCameraComponent;
class UCapsuleComponent;
class UCharacterMovementComponent;
class UInputMappingContext;

UCLASS()
class GOLFTOGETHER_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

	// Components
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	// Members
public:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping = nullptr;

	// Methods
public:
	APlayerBase();

protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	
	virtual void Tick(float DeltaTime) override;
};

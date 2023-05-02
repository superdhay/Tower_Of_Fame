// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/GameplayStatics.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "../../Systems/LogicNodes/Gate.h"

#include "PlayerSpringArmComponent.h"

#include "Controllers/SPlayerController.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class TOWER_OF_FAME_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		FGate Gate = FGate(false);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPlayerSpringArmComponent* SpringArmComponent;


public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector GetDirectionToMove();
	void MoveToDirection();

	void LeftClickPressed();
	void LeftClickReleased();
	void ZoomIn();
	void ZoomOut();

	void SetUpSpringArm();
};

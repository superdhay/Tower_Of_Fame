// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../../../Systems/LogicNodes/Gate.h"

#include "../PlayerCharacter.h"

#include "SPlayerController.h"


#include "WorldPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OF_FAME_API AWorldPlayerController : public ASPlayerController
{
	GENERATED_BODY()
		
private:
	UPROPERTY(VisibleAnywhere)
		FGate Gate = FGate(false);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void LeftClickPressed() override;
	virtual void LeftClickReleased() override;

	FVector GetDirectionToMove();
	void MoveToDirection();
};

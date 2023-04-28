// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OF_FAME_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void LeftClickPressed(){}
	virtual void LeftClickReleased() {}
};

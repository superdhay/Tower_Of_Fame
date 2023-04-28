// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Math/UnrealMathUtility.h"

#include "GameFramework/SpringArmComponent.h"
#include "PlayerSpringArmComponent.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OF_FAME_API UPlayerSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

private:
	int MinArmLength = 200;
	int MaxArmLength = 800;

public:
	UPlayerSpringArmComponent();


	void SetUpSpringArm();

	void ZoomIn();
	void ZoomOut();

	float ClampZoom(float currentArmLenght);
};

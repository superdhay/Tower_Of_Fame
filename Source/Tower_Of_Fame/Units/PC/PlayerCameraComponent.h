// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "PlayerCameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_OF_FAME_API UPlayerCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
	

public:
	UPlayerCameraComponent();

	void SetUpCamera();
};

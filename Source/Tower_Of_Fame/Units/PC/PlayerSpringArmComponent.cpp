// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSpringArmComponent.h"

UPlayerSpringArmComponent::UPlayerSpringArmComponent()
{
	SetUpSpringArm();
}

void UPlayerSpringArmComponent::SetUpSpringArm()
{
	this->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.f));
	this->TargetArmLength = 800.0f;
	this->bInheritPitch = false;
	this->bInheritRoll = false;
	this->bInheritYaw = false;
	this->bDoCollisionTest = false;
}

void UPlayerSpringArmComponent::ZoomIn()
{
	this->TargetArmLength = ClampZoom(TargetArmLength + 20);
}

void UPlayerSpringArmComponent::ZoomOut()
{
	this->TargetArmLength = ClampZoom(TargetArmLength - 20);
}

float UPlayerSpringArmComponent::ClampZoom(float currentArmLenght)
{
	return FMath::Clamp(currentArmLenght, 200, 800);
}

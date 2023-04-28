// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPlayerController.h"

void AWorldPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Gate.IsOpen()) {
		MoveToDirection();
	}
	
}


void AWorldPlayerController::LeftClickPressed()
{
	Gate.Open();
}

void AWorldPlayerController::LeftClickReleased()
{
	Gate.Close();
	Cast<APlayerCharacter>(this->GetPawn())->GetCharacterMovement()->MaxWalkSpeed = 0;
}


FVector AWorldPlayerController::GetDirectionToMove() {
	FHitResult hit;
	this->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, hit);
	return hit.Location;
}

void AWorldPlayerController::MoveToDirection() {
	FVector moveDirection = GetDirectionToMove();
	FVector distance = moveDirection - GetPawn()->GetActorLocation();

	if (distance.Length() > 150) {
		Cast<APlayerCharacter>(this->GetPawn())->GetCharacterMovement()->MaxWalkSpeed = 600;
	}
	else {
		Cast<APlayerCharacter>(this->GetPawn())->GetCharacterMovement()->MaxWalkSpeed = 150;
	}

	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, moveDirection);
}
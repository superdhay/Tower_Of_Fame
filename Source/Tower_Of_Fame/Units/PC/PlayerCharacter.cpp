// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector APlayerCharacter::GetDirectionToMove() {
	auto cont = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FHitResult hit;
	cont->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, hit);
	return hit.Location;
}

void APlayerCharacter::MoveToDirection() {
	auto cont = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	FVector moveDirection = GetDirectionToMove();
	FVector distance = moveDirection - GetActorLocation();

	if (distance.Length() > 150) {
		GetCharacterMovement()->MaxWalkSpeed = 600;
	}
	else {
		GetCharacterMovement()->MaxWalkSpeed = 150;
	}

	UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, GetActorLocation());
}
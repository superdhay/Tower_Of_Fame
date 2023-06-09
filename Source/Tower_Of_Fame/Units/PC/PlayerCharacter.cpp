// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//SetUpSpringArm();
	
	SpringArmComponent = CreateDefaultSubobject<UPlayerSpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
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

	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &APlayerCharacter::LeftClickPressed);
	PlayerInputComponent->BindAction("LeftClick", IE_Released, this, &APlayerCharacter::LeftClickReleased);

	PlayerInputComponent->BindAction("Zoom Camera In", IE_Pressed, this, &APlayerCharacter::ZoomIn);
	PlayerInputComponent->BindAction("Zoom Camera Out", IE_Pressed, this, &APlayerCharacter::ZoomOut);
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

	UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, moveDirection);
}

void APlayerCharacter::LeftClickPressed() {
	Cast<ASPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->LeftClickPressed();
	Gate.Open();
}

void APlayerCharacter::LeftClickReleased() {
	Cast<ASPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))->LeftClickReleased();
}

void APlayerCharacter::ZoomIn() {
	SpringArmComponent->ZoomIn();
}

void APlayerCharacter::ZoomOut() {
	SpringArmComponent->ZoomOut();
}

void APlayerCharacter::SetUpSpringArm()
{
	
}

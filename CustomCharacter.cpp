// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACustomCharacter::ACustomCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting class variables of the Character movement component
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bIgnoreBaseRotation = true;
}

// Called when the game starts or when spawned
void ACustomCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACustomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ACustomCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ACustomCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ACustomCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ACustomCharacter::Turn);

	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ACustomCharacter::Jump);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Released, this, &ACustomCharacter::Jump);
	PlayerInputComponent->BindAction(FName("Crouch"), IE_Pressed, this, &ACustomCharacter::BeginCrouch);
	PlayerInputComponent->BindAction(FName("Crouch"), IE_Released, this, &ACustomCharacter::EndCrouch);
	PlayerInputComponent->BindAction(FName("Sprint"), IE_Pressed, this, &ACustomCharacter::BeginSprint);
	PlayerInputComponent->BindAction(FName("Sprint"), IE_Released, this, &ACustomCharacter::EndSprint);
}

// Character Directional Movement

void ACustomCharacter::MoveForward(const float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void ACustomCharacter::MoveRight(const float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}

void ACustomCharacter::LookUp(const float AxisVal)
{
	AddControllerPitchInput(AxisVal);
}

void ACustomCharacter::Turn(const float AxisVal)
{
	AddControllerYawInput(AxisVal);
}

// Character Action Movement

void ACustomCharacter::BeginSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void ACustomCharacter::EndSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 250.0f;
}

void ACustomCharacter::BeginCrouch()
{
	Crouch();
}

void ACustomCharacter::EndCrouch()
{
	UnCrouch();
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacter.generated.h"

UCLASS()
class RUNIFYOUCAN_API ACustomCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(const float AxisVal);
	void MoveRight(const float AxisVal);
	void LookUp(const float AxisVal);
	void Turn(const float AxisVal);

	void BeginSprint();
	void EndSprint();
	void BeginCrouch();
	void EndCrouch();
};
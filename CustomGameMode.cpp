// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomGameMode.h"

// Sets default values
ACustomGameMode::ACustomGameMode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACustomGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank) {
		// Move towards the player

		//Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire if any
		ControlledTank->Fire();
	}
}


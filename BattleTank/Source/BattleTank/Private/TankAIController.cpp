// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetControlledTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Error, TEXT("AI Controller can't find Player Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetControlledTank()) { 
		// Move towards the player

		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if any
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto TankAimingComponent = GetPawn()->FindComponentByClass< UTankAimingComponent>();
	if (!ensure(TankAimingComponent)) { return; }
		
	FoundAimingComponent(TankAimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetPawn())) { return; }

	auto TankAimingComponent = GetPawn()->FindComponentByClass< UTankAimingComponent>();
	if (!ensure(TankAimingComponent)) { return; }

	FVector HitLocation; //Out Parameter

	if(GetSightRayHitLocation(HitLocation))
	{
		// Tell controlled tank to aim at this point
		TankAimingComponent->AimAt(HitLocation);
	}
}

// Get world location of line trace through cresshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel co-ordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	// "De-project" the screen positon of a crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		// Line trace along that LookDirection, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const 
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false; // Line trace doen't succeed
}
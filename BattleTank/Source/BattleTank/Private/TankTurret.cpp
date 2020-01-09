// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the barrel right amount this frame
	// Give a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotate = RelativeRotation.Yaw + ElevationChange;

	SetRelativeRotation(FRotator(0, Rotate, 0));
}
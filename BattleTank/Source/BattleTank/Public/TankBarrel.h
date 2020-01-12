// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "BarrelProperty")
	float MaxDegreePerSecond = 10.0f; // Sensible value set

	UPROPERTY(EditDefaultsOnly, Category = "BarrelProperty")
	float MaxElevationDegree = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = "BarrelProperty")
	float MinElevationDegree = 0.0f;
};

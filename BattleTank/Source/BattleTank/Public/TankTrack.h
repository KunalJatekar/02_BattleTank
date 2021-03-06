// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
 * TankTrack is used to set maximum driving force, and to apply force to the Tank to move.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UTankTrack();

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float TrackMaxDrivingForce = 40000000; // Assume 40 tons tank and 1g acceleration

	// Set a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void DriveTrack(float CurrentThrottle);

	TArray<ASprungWheel*> GetWheels() const;
};

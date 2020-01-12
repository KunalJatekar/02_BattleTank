// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Component responsible for movement of the Tank.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveRotate(float Throw);

private:

	// Called from the pathfinding logic by AI Controller
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed);

	UTankTrack* LeftTrack = nullptr;

	UTankTrack* RightTrack = nullptr;

};

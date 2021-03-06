// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelevateSpeed)
{
	// Move barrel the right amount this frame
	// Given the max elevation speed, and the frame time
	RelevateSpeed = FMath::Clamp<float>(RelevateSpeed, -1, 1);
	float ElevationChange = RelevateSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	SetRelativeRotation(FRotator(FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees), 0, 0));
}

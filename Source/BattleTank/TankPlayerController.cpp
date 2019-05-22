// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No ControlledTank"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerControllers Tank is %s "), *GetControlledTank()->GetName());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

//	Get the pawn and put it in the Tank(Cast)
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) return;
	
	FVector HitLocation;
	// Get world location if line trace through cross hair
	UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	// if hits the landscape
		// tell the controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& Hitlocation) const
{
	// RayCast  
	// if we hit something return true
	// else return false
	return false;
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(TankAimingComponent)) { return; }
	FoundAimingComponent(TankAimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
}

// Move the turret towards the cross hair
void ATankPlayerController::AimTowardsCrossHair()
{
	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(TankAimingComponent)) { return; }
	
	FVector HitLocation;	// Out parameter to store the location when we hit something with the line trace
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);

	// if we hit something
	if (bGotHitLocation)
	{
		TankAimingComponent->AimAt(HitLocation);
	}
}

// Get world location of the line trace through cross hair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D Screenlocation(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(Screenlocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, HitLocation);
		
	}

	return false;
}

// Get the HitLocation of out HitResult
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult Hit;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
	FCollisionQueryParams QueryParams = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());
	
	// Ray-cast out to specified distance
	 if (GetWorld()->LineTraceSingleByChannel
		 (Hit,
		 StartLocation,
		 EndLocation,
		 ECollisionChannel::ECC_Visibility,
		 QueryParams)
		 )
			{
				HitLocation = Hit.Location;
				return true;
			}
	 HitLocation = FVector(0.0f);
	 return false;
}

// De-Project the screen position of the cross hair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // to be discarded, isn't needed for our purpose

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

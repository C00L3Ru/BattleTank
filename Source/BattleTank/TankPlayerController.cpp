// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

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
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
	// if hits the landscape
		// tell the controlled tank to aim at this point
}

// Get world location if line trace through cross hair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D Screenlocation(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(Screenlocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *LookDirection.ToString());
		return true;
	}
	return false;

// 	FVector PlayersViewPointLocation;
// 	FRotator PlayersViewPointRotation;
// 	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayersViewPointLocation, PlayersViewPointRotation);
// 
// 	// Calculate how far we can reach into the distance and draw a debug line to visualize this
// 	FVector LineTraceEnd = PlayersViewPointLocation + PlayersViewPointRotation.Vector() * 10000.f;
// 
// 	// Ray-cast out to specified distance
// 	FHitResult Hit;
// 	FCollisionQueryParams QueryParams = FCollisionQueryParams(FName(TEXT("")), false, GetOwner());
// 	if (GetWorld()->LineTraceSingleByObjectType(
// 			Hit,
// 			PlayersViewPointLocation,
// 			LineTraceEnd,
// 			FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
// 			QueryParams))
// 	{
// 
// 		HitLocation = Hit.Location;
// 		return true;
// 	}
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // to be discarded, isn't needed for our purpose

	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

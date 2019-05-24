// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AImAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FString OurTankName = GetOwner()->GetName();

	FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
		(this,
		LaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s "), *OurTankName, *AimDirection.ToString())
		MoveBarrelTowards(AimDirection);
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f Aim Solution found"), Time);
	}
	else
	{
		float Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f No Aim solution found"), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	 // Workout difference between current barrel rotation and AimDirection
	FRotator CurrentBarrelRotation = GetOwner()->GetActorForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaBarrelRotator = AimAsRotator - CurrentBarrelRotation;
	
	Barrel->Elevate(1);	// TODO Remove magic number
}

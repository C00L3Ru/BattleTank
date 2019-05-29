// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include <ConstructorHelpers.h>

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	static ConstructorHelpers::FClassFinder<AProjectile> Proj(TEXT("/Game/Tank/BP_Projectile"));
	if (Proj.Class)
	{
		ProjectileBlueprint = Proj.Class;
	}

	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet)
{
	Turret = TurretToSet;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; }

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
		MoveBarrelTowards(AimDirection);
	}
	else
	{
		float Time = GetWorld()->GetTimeSeconds();
	}
}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel) || !ensure(ProjectileBlueprint)) { return; }


	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;

	if (isReloaded)
	{
		FVector BarrelLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator BarrelRotation = Barrel->GetSocketRotation(FName("Projectile"));

		// Spawn a projectile at socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, BarrelLocation, BarrelRotation);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Barrel) || !ensure (Turret)) { return; }

	 // Workout difference between current barrel rotation and AimDirection
	FRotator CurrentBarrelRotation = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaBarrelRotator = AimAsRotator - CurrentBarrelRotation;
	
	Barrel->Elevate(DeltaBarrelRotator.Pitch);	// TODO Remove magic number
	Turret->RotateTurret(DeltaBarrelRotator.Yaw);
}


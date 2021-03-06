// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus:uint8
{
	Locked,
	Aiming,
	Reloading,
	OutOfAmmo
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	EFiringStatus GetFiringState() const;

protected:
	void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Firing)
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

public:	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Firing)
	int32 GetRoundsLeft() const;
	
private:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTime = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 10000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	int32 AmmoCount = 20;

	double LastFireTime = 0.f;
	FVector AimiDirection;
	bool bIsAimed;
};

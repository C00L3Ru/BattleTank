// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UNiagaraComponent;
class UStaticMeshComponent;
class URadialForceComponent;
class UNiagaraSystem;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	void LaunchProjectile(float LaunchSpeed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CollisionMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UNiagaraComponent* Blast = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UNiagaraComponent* ImpactBlast = nullptr;

	UPROPERTY(BlueprintReadWrite)
	UNiagaraSystem* BlastSystem = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float ProjectileDamage = 50.0f;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void TimerExpired();

	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* ExplosiveForce = nullptr;

	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
	float DestroyDelay = 3.0f;
};

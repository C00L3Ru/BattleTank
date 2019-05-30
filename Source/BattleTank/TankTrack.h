// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *	TankTrack will be used to set maximum driving force, and to apply forces to the Tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UTankTrack();
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetThrottle(float Throttle);

	void DriveTrack();

protected:
	void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float TankTrackMaxDrivingForce = 40000000.0f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void ApplySideWaysForce();

	float CurrentThrottle = 0.0f;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 *
 */

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()



protected:
	void BeginPlay() override;
	
public:
	void Tick(float DeltaTime)override;

private:
	UTankAimingComponent* TankAimingComponent = nullptr;
	
	APawn* AiControlledTank = nullptr;
	APawn* PlayerTank = nullptr;

	void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossedTankDeath();
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float AcceptanceRadius = 800.0f;

};


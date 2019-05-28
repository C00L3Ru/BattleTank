// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

public:
	void Tick(float DeltaTime)override;

private:
	UPROPERTY(EditAnywhere, Category = AiNavigation)
	float AcceptanceRadius = 900.0f;


};


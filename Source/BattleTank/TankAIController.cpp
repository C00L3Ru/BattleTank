// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetAiControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No ControlledTank"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AiPlayerControllers Tank is %s "), *GetAiControlledTank()->GetName());
}

ATank* ATankAIController::GetAiControlledTank()
{
	return Cast<ATank>(GetPawn());
}

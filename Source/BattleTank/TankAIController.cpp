// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!GetAiControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No AiControlledTank"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AiPlayerControllers Tank is %s "), *GetAiControlledTank()->GetName());

	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("No PlayerTank"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AiPlayerControllers Tank is %s "), *GetPlayerTank()->GetName());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetAiControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

ATank* ATankAIController::GetAiControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank)  return nullptr;
	return PlayerTank;
}

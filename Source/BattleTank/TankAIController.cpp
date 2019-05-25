// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("AI ticking"));
// 	auto AiControlledTank = Cast<ATank>(GetPawn());
// 	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
// 
// 	if (PlayerTank)
// 	{
// 		AiControlledTank->AimAt(PlayerTank->GetActorLocation());
// 		AiControlledTank->Fire();
// 	}
// 		UE_LOG(LogTemp, Warning, TEXT("No PlayerTank"));
}



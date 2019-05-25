// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	AiControlledTank = Cast<ATank>(GetPawn());

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AiControlledTank->AimAt(PlayerTank->GetActorLocation());

 	if (PlayerTank)
 	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found position is at %s"), *PlayerTank->GetActorLocation().ToString());
 		AiControlledTank->AimAt(PlayerTank->GetActorLocation());
 		AiControlledTank->Fire();
 	}
 	UE_LOG(LogTemp, Warning, TEXT("No PlayerTank"));
}




// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AiControlledTank = GetPawn();

	if (!ensure(PlayerTank && AiControlledTank)) { return; }
 	
	MoveToActor(PlayerTank, AcceptanceRadius);
 	TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
	// TODO Fix firing
	TankAimingComponent->Fire();
}

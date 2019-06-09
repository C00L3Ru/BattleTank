// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	AiControlledTank = GetPawn();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ensure(PlayerTank && AiControlledTank)) { return; }
 	
	MoveToActor(PlayerTank, AcceptanceRadius);
 	TankAimingComponent->AimAt(PlayerTank->GetActorLocation());
	if(TankAimingComponent->GetFiringState() != EFiringStatus::Locked)
	{
		TankAimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if(!ensure(PossessedTank)) { return; }
		
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}
}

void ATankAIController::OnPossedTankDeath()
{
	AiControlledTank->DetachFromControllerPendingDestroy();
	UE_LOG(LogTemp, Warning, TEXT("I'm Fucked"));
}

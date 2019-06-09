// Fill out your copyright notice in the Description page of Project Settings.


#include "SpringWheel.h"
#include <Components/StaticMeshComponent.h>
#include <PhysicsEngine/PhysicsConstraintComponent.h>


// Sets default values
ASpringWheel::ASpringWheel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PhysicsConsstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(FName("PhysicsConstraint"));
	

	Mass = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mass"));

	Wheel = CreateDefaultSubobject<UStaticMeshComponent>(FName("Wheel"));

	SetRootComponent(PhysicsConsstraint);

	Wheel->SetupAttachment(PhysicsConsstraint);

	Wheel->SetupAttachment(PhysicsConsstraint);
}

// Called when the game starts or when spawned
void ASpringWheel::BeginPlay()
{
	Super::BeginPlay();
	if (GetAttachParentActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Null"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Is Null"));
	}
}

// Called every frame
void ASpringWheel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <../Plugins/FX/Niagara/Source/Niagara/Public/NiagaraComponent.h>
#include <PhysicsEngine/RadialForceComponent.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/DamageType.h>


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComponent"));
	ProjectileMovementComponent->bAutoActivate = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("CollisionMesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);

	Blast = CreateDefaultSubobject<UNiagaraComponent>(FName("Blast"));
	Blast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);


	ImpactBlast = CreateDefaultSubobject<UNiagaraComponent>(FName("ImpactBlast"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ImpactBlast->bAutoActivate = false;

	ExplosiveForce = CreateDefaultSubobject<URadialForceComponent>(FName("ExplosiveForce"));
	ExplosiveForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	ExplosiveForce->FireImpulse();
	
	SetRootComponent(Blast);
	CollisionMesh->DestroyComponent(true);

	UGameplayStatics::ApplyRadialDamage(
		this,
		ProjectileDamage,
		GetActorLocation(),
		ExplosiveForce->Radius,
		UDamageType::StaticClass(),
		TArray<AActor*>()
		);

	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AProjectile::TimerExpired, DestroyDelay);
}


void AProjectile::TimerExpired()
{
	this->Destroy(true);
}

void AProjectile::LaunchProjectile(float LaunchSpeed)
{	
	ProjectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
	ProjectileMovementComponent->Activate();
}

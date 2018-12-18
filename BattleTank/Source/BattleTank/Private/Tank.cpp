// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Engine/GameEngine.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("MovementComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{
		LastFireTime = GetWorld()->GetTimeSeconds();

		FActorSpawnParameters SpawnInfo;
		FRotator myRot = Barrel->GetSocketRotation(FName("Projectile"));
		FVector myLoc = Barrel->GetSocketLocation(FName("Projectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluebrint, myLoc, myRot, SpawnInfo);
		Projectile->LaunchProjectile(LaunchSpeed);

	}
}


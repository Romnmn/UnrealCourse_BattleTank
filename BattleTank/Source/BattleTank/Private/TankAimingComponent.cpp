// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	/*auto OwnerName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is aiming on %s"),*OwnerName, *HitLocation.ToString());*/

	auto OwnerName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation();

	UE_LOG(LogTemp, Warning, TEXT("%s is aiming on %s from %s"), *OwnerName, *HitLocation.ToString(), *BarrelLocation.ToString());
}


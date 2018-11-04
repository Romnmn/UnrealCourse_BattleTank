// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"
#include "Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player C is not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player C is possesing a %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	AimTowardsCrosshair();
	
}

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	/*FHitResult OutHit;
	const FVector Start;
	const FVector End;

	const FCollisionQueryParams Params;
	const FCollisionResponseParams ResponseParam;

	GetWorld()->LineTraceSingleByChannel(
	(
		OutHit,        //result
		Start,    //start
		End, //end
		ECC_Visibility, //collision channel
		Params,
		ResponseParam
	);*/

	return false;
}





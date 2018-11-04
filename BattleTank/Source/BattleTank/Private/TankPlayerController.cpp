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
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//find the position of the crosshair on a screen
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	//translate the position to a point in the world 
	FVector WorldLocation;
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, WorldLocation, LookDirection))
	{
		//linetrace checking objects 
		GetLookVectorHitDirection(LookDirection, OutHitLocation);
		return true;
	}
	else { return false; }
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& WorldLocation, FVector& LookDirection) const
{
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection))
	{
		return true;
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitDirection(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult Hitresult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(Hitresult, StartLocation, EndLocation, ECC_Visibility))
	{
		HitLocation = Hitresult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}





// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI C hasn't found player tank"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("AI C has found the player tank : %s"), *(PlayerTank->GetName()));
	}

	GetPlayerTank();

}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerTank) { return nullptr; }
	else { return Cast<ATank>(PlayerTank); }

}



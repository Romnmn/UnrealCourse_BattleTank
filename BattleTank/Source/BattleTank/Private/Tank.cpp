// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	//CurrentHealth -= Damage;
	//UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentHealth);
	
	int DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;

	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank died"));
		OnDeath.Broadcast();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f %i"), DamageAmount, DamageToApply)
	}

	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = StartingHealth;
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Locked,
	Aiming,
	Reloading,
	OutOfAmmo
};


class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
	EFiringState FiringState = EFiringState::Reloading;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBluebrint;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankBarrel* TankBarrelToSet, UTankTurret* TankTurretToSet);

	void AimAt(FVector HitLocation);

	UTankAimingComponent();	

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void Fire();

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsLeft() const;

private:
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;

	float LastFireTime = 0;

	void MoveBarrelAndTurretTowards(FVector); //MoveBarrelTowards
	bool IsBarrelMoving();
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 1;
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	int RoundsLeft = 50;

	//test
	FVector AimDirection;

};

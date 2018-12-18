// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "Kismet/GameplayStatics.h"
//#include "TankBarrel.h"
//#include "TankTurret.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus : uint8
{
	Locked,
	Aiming,
	Reloading
};

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
	EFiringStatus FiringStatus = EFiringStatus::Reloading;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankBarrel* TankBarrelToSet, UTankTurret* TankTurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

	UTankAimingComponent();	

private:
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;

	void MoveBarrelAndTurretTowards(FVector); //MoveBarrelTowards
	
};

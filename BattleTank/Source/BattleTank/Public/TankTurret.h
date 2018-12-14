// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)/*, hidecategories = ("Collision")*/)
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretMesh(UStaticMesh * MeshToSet);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup) float MaxDegreesPerSecond = 25;
	UPROPERTY(EditAnywhere, Category = Setup) float MinRotationDegrees = -45;
	UPROPERTY(EditAnywhere, Category = Setup) float MaxRotationDegrees = 45;
	
};

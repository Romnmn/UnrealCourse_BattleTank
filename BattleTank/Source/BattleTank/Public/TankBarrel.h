// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 min, 1 max
	void Elevate(float RelativeSpeed);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelMesh(UStaticMesh * MeshToSet);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup) float MaxDegreesPerSecond = 10;

	UPROPERTY(EditDefaultsOnly, Category = Setup) float MinElevationDegrees = 0;

	UPROPERTY(EditDefaultsOnly, Category = Setup) float MaxElevationDegrees = 40;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent * AimCompRef);

private:
	UPROPERTY(EditDefaultsOnly) 
	float CrossHairXLocation = 0.5f, CrossHairYLocation = 0.3333f;
	
	UPROPERTY(EditDefaultsOnly) 
	float LineTraceRange = 1000000.f;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldLocation, FVector& LookDirection) const;
	bool GetLookVectorHitDirection(FVector LookDirection, FVector& HitLocation) const;
};
	
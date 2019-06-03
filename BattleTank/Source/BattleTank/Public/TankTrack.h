// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UTankTrack();
	virtual void BeginPlay() override;
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ApplySidewaysForce();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTrackMesh(UStaticMesh * MeshToSet);
	
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	void DriveTrack();

	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Projectile.generated.h"


UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float);

private:

	UFUNCTION()
	void OnHit	(UPrimitiveComponent* HitComponent, 
				AActor* OtherActor, UPrimitiveComponent* OtherComp, 
				FVector NormalImpulse, 
				const FHitResult& Hit);

	UFUNCTION()
	void Destroy();

	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CollisionMesh = nullptr;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* LaunchBlast = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	float DestroyDelay = 3;

};

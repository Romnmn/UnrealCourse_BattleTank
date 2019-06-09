// Daragan inc.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetConstraint();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	//UPROPERTY(VisibleAnywhere, Category = "Components")
	//UStaticMeshComponent* Mass;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Wheel;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent* MassWheelConstraint;

};

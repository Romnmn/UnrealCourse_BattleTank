// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h" //my
#include "SprungWheel.h" //Components/SceneComponent.cpp
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	//OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}

/*void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}*/

void UTankTrack::SetTrackMesh(UStaticMesh * MeshToSet)
{
	SetStaticMesh(MeshToSet);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("aaaaaaaaaaaa"));
	//DriveTrack();
	//ApplySidewaysForce();
	//CurrentThrottle = 0;
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / (FMath::Clamp<int>(Wheels.Num(), 1, Wheels.Num()+1));
	for(ASprungWheel * Wheel :Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}
TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	for (USceneComponent* Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);
		if (!SprungWheel) continue;

		ResultArray.Add(SprungWheel);

		//ResultArray.Add(Cast<ASprungWheel>(SpawnPointChild->GetSpawnedActor()));
	}

	return (ResultArray);
}
/*
void UTankTrack::ApplySidewaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//UE_LOG(LogTemp, Warning, TEXT("%f"), SlippageSpeed);

	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//F= m*a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}*/


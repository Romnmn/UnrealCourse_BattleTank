// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::SetTurretMesh(UStaticMesh * MeshToSet)
{
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Content/Tank/tank_fbx_Barrel.tank_fbx_Barrel'"));
	UStaticMesh* Asset = MeshAsset.Object;*/
	SetStaticMesh(MeshToSet);
}

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	auto Rotation = FMath::Clamp<float>(RawNewRotation, MinRotationDegrees, MaxRotationDegrees);

	SetRelativeRotation(FRotator(0, Rotation, 0));
}


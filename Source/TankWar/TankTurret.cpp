// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float RotationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;

	float RawNewElevation = GetRelativeRotation().Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}

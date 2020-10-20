// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	UE_LOG(LogTemp, Warning, TEXT("Relative Speed barrel %f"), RelativeSpeed);
	float ElevationChange = RelativeSpeed * MaxDegreePerSecond * GetWorld()->DeltaTimeSeconds;

	float RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	RawNewElevation = FMath::Clamp<float>(RawNewElevation,MinElevationDegrees,MaxElevationDegrees);
	SetRelativeRotation(FRotator(RawNewElevation, 0 , 0));

}


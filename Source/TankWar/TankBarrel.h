// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKWAR_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSecond = 20;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 30;

public:
	void Elevate(float DegreePerSecond);

};

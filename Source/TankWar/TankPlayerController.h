// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class TANKWAR_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BeginPlay() override;
	ATank* GetControlledTank() const;
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& HitLocation, FHitResult& HitObject) const;
	bool GetLookDirection(FVector2D& ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& Hitlocation, FHitResult& HitObject) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333;
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
	
};

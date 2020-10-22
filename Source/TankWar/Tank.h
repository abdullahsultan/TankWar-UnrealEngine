// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class TANKWAR_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//void AimAt(FVector HitLocation, FHitResult HitObject);
	void AimAt(FVector HitLocation);

	float ReloadTimeInSeconds = 3.0f;
	double LastFireTime = 0;


	UTankAimingComponent* TankAimingComponent = nullptr;
	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelRefrence(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretRefrence(UTankTurret* TurretToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;


};

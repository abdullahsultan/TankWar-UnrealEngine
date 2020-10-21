// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankTurret.h"
#include "TankBarrel.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/*void ATank::AimAt(FVector HitLocation, FHitResult HitObject)
{
	TankAimingComponent->AimAt(HitLocation,HitObject);
}*/

void ATank::AimAt(FVector HitLocation)
{
	if(TankAimingComponent)
		TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
}

void ATank::SetBarrelRefrence(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelRefrence(BarrelToSet);
}

void ATank::SetTurretRefrence(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretRefrence(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire in the hole"));
}


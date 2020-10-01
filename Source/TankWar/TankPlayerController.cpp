// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	ATank* T = GetControlledTank();
	if(T)
	{
		UE_LOG(LogTemp, Warning, TEXT("Posessed Pawn = %s"), *T->GetName());
	}

}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();

}



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	FVector HitLocation; FHitResult HitObject;
	GetSightRayHitLocation(HitLocation, HitObject);
	if (HitObject.GetActor())
		GetControlledTank()->AimAt(HitLocation);   //Sending hit information to Tank.cpp
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation, FHitResult& HitObject) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX,ViewportSizeY); //Get ViewPort(BP widget) size (In our case screen size)
	FVector2D ScreenLocation = FVector2D(ViewportSizeX* CrosshairXLocation, ViewportSizeY* CrosshairYLocation); //Getting location of AimPoint from screen size(actullay BP widget)
	 FVector LookdDirection;
	 if (GetLookDirection(ScreenLocation, LookdDirection))
	 {
		 GetLookVectorHitLocation(LookdDirection,HitLocation, HitObject);
	 }

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D& ScreenLocation, FVector& LookdDirection) const
{
	FVector CameraWorldPosition;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldPosition, LookdDirection); // Convert 2d position to 3d world space
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& Hitlocation, FHitResult& HitObject) const //Get Things we HIT
{
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitObject,
		Start,
		End,
		ECollisionChannel::ECC_Visibility
	))
	{
		Hitlocation = HitObject.Location;

		if(HitObject.GetActor())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Hit Object = %s"), *HitObject.GetActor()->GetName());
		}
		else
		{
			//UE_LOG(LogTemp, Warning, TEXT("No Object"));
		}

		return true;
	}
	Hitlocation = FVector(0);
	return false;
}


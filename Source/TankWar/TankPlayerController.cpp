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
	//UE_LOG(LogTemp, Warning, TEXT("Hit Loction : %s"), *HitLocation.ToString());
	GetControlledTank()->AimAt(HitLocation,HitObject);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation, FHitResult& HitObject) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX,ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX* CrosshairXLocation, ViewportSizeY* CrosshairYLocation);
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
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldPosition, LookdDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection,FVector& Hitlocation, FHitResult& HitObject) const
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


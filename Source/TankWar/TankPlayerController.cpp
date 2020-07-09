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


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


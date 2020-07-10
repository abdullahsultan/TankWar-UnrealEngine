// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* T = GetControlledTank();
	if (T)
	{
		UE_LOG(LogTemp, Warning, TEXT("Posessed AI Pawn = %s"), *T->GetName());
	}

	T = GetPlayerControlTank();
	if (T)
	{
		UE_LOG(LogTemp, Warning, TEXT("First Comntrolled Tank = %s"), *T->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerControlTank() const
{
	return Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn() );
}
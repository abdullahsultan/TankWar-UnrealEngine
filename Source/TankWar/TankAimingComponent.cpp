#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::SetBarrelRefrence(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
	UE_LOG(LogTemp, Warning, TEXT("Tank %s ::	Static Mesh Name :: %s"), *GetOwner()->GetName(),*Barrel->GetName());

}

void UTankAimingComponent::AimAt(FVector HitLocation, FHitResult HitObject)
{
	if (HitObject.GetActor())
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s Aiming At : %s : At Location %s"), *GetOwner()->GetName(), *HitObject.GetActor()->GetName(), *HitLocation.ToString());
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("NO Object Hitting"));
	}
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!HitLocation.IsZero())
	{
		//UE_LOG(LogTemp, Warning, TEXT("%s Aiming : At Location %s"), *GetOwner()->GetName(), *HitLocation.ToString());
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("NO Object Hitting"));
	}
}


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Kismet/GameplayStatics.h"

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


/*void UTankAimingComponent::AimAt(FVector HitLocation, FHitResult HitObject)
{
	if (HitObject.GetActor())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming At : %s : At Location %s"), *GetOwner()->GetName(), *HitObject.GetActor()->GetName(), *HitLocation.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO Object Hitting"));
	}
}*/

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//UE_LOG(LogTemp, Error, TEXT("DDDDDDDDDDDDD %s"), *HitLocation.ToString());
	FVector AimDirection;


	if (!Barrel) { return; }

	FVector OutLaunchVelocity(0); //Suggested Projectile Velicity by Function OUT prameter
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution)
		{
			AimDirection = OutLaunchVelocity.GetSafeNormal();
			//UE_LOG(LogTemp, Warning, TEXT("Tank %s :: Big Fun %s"), *GetOwner()->GetName(),*AimDirection.ToString());
			MoveBarrelTowards(AimDirection);
			//UE_LOG(LogTemp, Warning, TEXT("True"));
		}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Function not suggesting"));
	}	
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);

}


void UTankAimingComponent::SetBarrelRefrence(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
	//UE_LOG(LogTemp, Warning, TEXT("Tank %s ::	Static Mesh Name :: %s"), *GetOwner()->GetName(),*Barrel->GetName());
}

void UTankAimingComponent::SetTurretRefrence(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
	UE_LOG(LogTemp, Warning, TEXT("Tank %s ::	Static Mesh Name :: %s"), *GetOwner()->GetName(),*Turret->GetName());
}
// Copyright FLB Games.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h" // So we can implement on death

// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(PlayerTank && AimingComponent)) { return; }

	// TODO Move toward the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO: Check radius is in cm

	// Aim toward the player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//	Fire if ready
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	AimingComponent->Fire(); //TODO: limit the firing rate

}
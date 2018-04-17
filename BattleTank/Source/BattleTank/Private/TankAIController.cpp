// Copyright FLB Games.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
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
	AimingComponent->Fire(); //TODO: limit the firing rate

}
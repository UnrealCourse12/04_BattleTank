// Copyright FLB Games.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// How close can the AI tank get
	float AcceptanceRadius = 3000;
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel correct amount this frame

	// give a max elevation speed and frame time
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate Called at speed %f"), DegreesPerSecond);
}



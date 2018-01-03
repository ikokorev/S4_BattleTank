// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// Given a max rotation speed and the frame time
	//RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	if (RelativeSpeed > 0)
	{
		RelativeSpeed = 1;
	}
	else if (RelativeSpeed < 0)
	{
		RelativeSpeed = -1;
	}

	
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	//float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));

}




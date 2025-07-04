#include "AircraftState.h"
#include <cmath>
#include <algorithm>

AircraftState::AircraftState()
	: pitch(0.0), 
	  roll(0.0), 
	  heading(0.0), 
	  airspeed(120.0), 
	  altitude(2000.0), 
	  verticalSpeed(0.0), 
	  targetPitch(0.0), 
	  targetRoll(0.0)
{

}

void AircraftState::update(double dt)
{
	const double rate = 10.0;

	if (pitch < targetPitch)
	{
		pitch = std::min(pitch + rate * dt, targetPitch);
	}
	else if (pitch > targetPitch)
	{
		pitch = std::max(pitch - rate * dt, targetPitch);
	}

	if (roll < targetRoll)
	{
		roll = std::min(roll + rate * dt, targetRoll);
	}
	else if (roll > targetRoll)
	{
		roll = std::max(roll - rate * dt, targetRoll);
	}


	heading += 1.0 * dt;
	if (heading >= 360.0) heading -= 360.0;

	airspeed += 0.1 * std::cos(dt);
	altitude += verticalSpeed * dt / 60.0;
}

void AircraftState::setTargetPitch(double pitch)
{
	targetPitch = pitch;
}

void AircraftState::setTargetRoll(double roll)
{
	targetRoll = roll;
}

double AircraftState::getPitch() const { return pitch; }
double AircraftState::getRoll() const { return roll; }
double AircraftState::getHeading() const { return heading; }
double AircraftState::getAirspeed() const { return airspeed; }
double AircraftState::getAltitude() const { return altitude; }
double AircraftState::getVerticalSpeed() const { return verticalSpeed; }


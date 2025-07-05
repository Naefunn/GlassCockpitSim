#include "AircraftState.h"
#include <cmath>
#include <algorithm>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif // !M_PI


AircraftState::AircraftState()
	: pitch(0.0),
	roll(0.0),
	heading(0.0),
	airspeed(120.0),
	altitude(2000.0),
	verticalSpeed(0.0),
	targetPitch(0.0),
	targetRoll(0.0),
	thrustPercent(50.0) // thurst as a percentage
{

}

void AircraftState::update(double dt)
{
	// allows pitch and roll to be changed by user input

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

	// allows heading to be controlled by roll

	// convert degrees to rads
	double rollInRads = roll * M_PI / 180.0;
	const double turnRateGain = 30.0;
	double turnRate = turnRateGain * std::sin(rollInRads);


	heading += turnRate * dt;
	if (heading >= 360.0) heading -= 360.0;
	if (heading < 0.0) heading += 360.0;

	const double maxThrust = 20000.0;   // max of the engine in newtons
	const double mass = 5000.0;		// mass of aircraft
	const double dragCoeff = 0.02;

	double thrustForce = (thrustPercent / 100.0) * maxThrust;  // converts thrust setting from percentage to force
	double dragForce = dragCoeff * airspeed * airspeed;

	double netForce = thrustForce - dragForce;  // resultant force on aircraft
	double acceleration = netForce / mass;  // f = ma rearraged for acceleration

	//convert to meters per second

	airspeed += acceleration * dt * 1.94384;
	if (airspeed < 0) airspeed = 0;

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

void AircraftState::setThrust(double thrustPct)
{
	thrustPercent = std::clamp(thrustPct, 0.0, 100.0);
}

double AircraftState::getPitch() const { return pitch; }
double AircraftState::getRoll() const { return roll; }
double AircraftState::getHeading() const { return heading; }
double AircraftState::getAirspeed() const { return airspeed; }
double AircraftState::getAltitude() const { return altitude; }
double AircraftState::getVerticalSpeed() const { return verticalSpeed; }
double AircraftState::getThrust() const { return thrustPercent; }


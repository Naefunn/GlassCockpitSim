#pragma once

class AircraftState 
{
public:
	AircraftState ();

	void update(double dt);

	// getters

	double getPitch() const;
	double getRoll() const;
	double getHeading() const;	
	double getAirspeed() const;
	double getAltitude() const;
	double getVerticalSpeed() const;
	double getThrust() const;

	// setters 

	void setTargetPitch(double pitch);
	void setTargetRoll(double roll);
	void setThrust(double thrustPercent);




private:

	double pitch;			// degrees
	double roll;			// degrees
	double heading;			// degrees
	double airspeed;		// knots
	double altitude;		// feet
	double verticalSpeed;	// feet per minute
	double targetPitch;
	double targetRoll;
	double thrustPercent;


};



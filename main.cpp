#include <iostream>
#include <chrono>
#include <thread>
#include "AircraftState.h"

int main()
{
    AircraftState aircraft;

    double t = 0.0;
    const double dt = 0.1;
    
    double timeSinceLastPrompt = 0.0;
    double timeSinceLastPrint = 0.0;
    
    const double printInterval = 1.5;
    const double promptInterval = 10.0;

    while (true) 
    {
        aircraft.update(t);

        timeSinceLastPrint += dt;
        timeSinceLastPrompt += dt;

        if (timeSinceLastPrint >= printInterval)
        {
            std::cout << "Time: " << t << "s\n";
            std::cout << "Pitch: " << aircraft.getPitch() << " degrees\n";
            std::cout << "Roll: " << aircraft.getRoll() << " degrees\n";
            std::cout << "Heading: " << aircraft.getHeading() << " degrees\n";
            std::cout << "Airspeed: " << aircraft.getAirspeed() << " Knots\n";
            std::cout << "Altitude: " << aircraft.getAltitude() << " ft\n";
            std::cout << "-------------------------------\n";

            timeSinceLastPrint = 0.0;
        }

        if (timeSinceLastPrompt >= promptInterval)
        {
            double newPitch, newRoll;

            std::cout << "Enter new target pitch (-90 to 90): ";
            std::cin >> newPitch;
            aircraft.setTargetPitch(newPitch);

            std::cout << "Enter new target roll (-180 to 180): ";
            std::cin >> newRoll;
            aircraft.setTargetRoll(newRoll);

            timeSinceLastPrompt = 0.0;
        }

        

        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dt * 1000)));
        t += dt;

    }

    return 0;
}

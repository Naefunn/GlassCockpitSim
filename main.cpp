#include <iostream>
#include <chrono>
#include <thread>
#include "AircraftState.h"

int main()
{
    AircraftState aircraft;

    auto lastTime = std::chrono::steady_clock::now();
    auto startTime = std::chrono::steady_clock::now();
    
    double timeSinceLastPrompt = 0.0;
    double timeSinceLastPrint = 0.0;
    
    const double printInterval = 1.5;
    const double promptInterval = 10.0;

    while (true) 
    {

        auto now = std::chrono::steady_clock::now();
        
        std::chrono::duration<double> elapsed = now - lastTime;
        double dt = elapsed.count();
        lastTime = now;

        std::chrono::duration<double> elapsedSinceStart = now - startTime;
        double continuousTime = elapsedSinceStart.count();


        aircraft.update(dt);

        timeSinceLastPrint += dt;
        timeSinceLastPrompt += dt;

        if (timeSinceLastPrint >= printInterval)
        {
            std::cout << "Time: " << continuousTime << "s\n";
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
            double newPitch, newRoll, newThrust;

            std::cout << "Enter new target pitch (-90 to 90): ";
            std::cin >> newPitch;
            aircraft.setTargetPitch(newPitch);

            std::cout << "Enter new target roll (-180 to 180): ";
            std::cin >> newRoll;
            aircraft.setTargetRoll(newRoll);

            std::cout << "Enter new thrust percentage (0 to 100): ";
            std::cin >> newThrust;
            aircraft.setThrust(newThrust);

            timeSinceLastPrompt = 0.0;

            lastTime = std::chrono::steady_clock::now();
        }

        

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }

    return 0;
}

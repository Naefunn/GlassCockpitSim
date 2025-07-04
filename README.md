# AircraftState Simulation

A simple C++ console application simulating basic aircraft state parameters including pitch, roll, heading, airspeed, and altitude. The program updates these parameters over time and allows user input to control target pitch and roll.

## Features

- Continuous real-time simulation with timing control.
- Periodic output of aircraft state to console.
- User prompts every 10 seconds to input new target pitch and roll.
- Smooth updates using time delta (`dt`) for consistent behavior.

## How to Use

1. Clone the repository.
2. Build the project using your preferred C++ compiler.
3. Run the executable.
4. Every 10 seconds, you will be prompted to enter new target pitch and roll values.
5. The current state is printed every 1.5 seconds.

## Planned Enhancements

- Thrust and airbrake controls to simulate realistic airspeed changes.
- More comprehensive flight dynamics including drag, acceleration, and control inputs.

## Dependencies

- Standard C++17 or later compiler.
- No external dependencies.

## Example Output

``` 
Time: 10.5s
Pitch: 5.0 degrees
Roll: -10.0 degrees
Heading: 90.0 degrees
Airspeed: 150 knots
Altitude: 5000 ft
-------------------------------
Enter new target pitch (-90 to 90): 
Enter new target roll (-180 to 180):
```

---

Feel free to contribute or submit issues!

---

**Author:** Nathan Foster  
**License:** MIT

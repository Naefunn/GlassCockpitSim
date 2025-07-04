# Primary Flight Display (PFD) Visualization

A modern C++/Qt project demonstrating the principles of a **Primary Flight Display (PFD)** found in modern glass cockpits. This application visualizes aircraft attitude, heading, airspeed, and altitude data in real time. It uses a simulated aircraft state as a data source, providing a realistic test feed without external dependencies.

## Features

- **Aircraft State Simulator**  
  Simulates pitch, roll, heading, airspeed, and altitude, providing a live data stream for the display.

- **Planned Graphical PFD**  
  Using Qt to render a realistic artificial horizon, heading tape, and speed/altitude scales.

- **Real-Time Updates**  
  Smooth updates driven by time-delta calculations for consistent behavior regardless of user input or system load.

- **User-Controllable Targets**  
  Command simulated pitch and roll values to see realistic transitions and responsive display updates.

## Project Roadmap

✅ Phase 1 (complete):  
- Console-based AircraftState simulator with user input  
- Real-time timing and control

🚧 Phase 2 (in progress):  
- Build a Qt-based attitude indicator (artificial horizon)  
- Integrate aircraft state data with a graphical PFD

🚀 Phase 3 (planned):  
- Add airspeed and altitude tapes  
- Implement vertical speed indicator  
- Polish the display for a glass-cockpit experience

## How to Use

1. Clone this repository.  
2. Build the project using a C++17 or later compiler and Qt (for Phase 2 onward).  
3. Run the application:  
   - In console mode, you can enter pitch/roll targets and see textual updates.  
   - In PFD mode (coming soon), view a graphical flight display driven by the simulator.

## Dependencies

- C++17 or later  
- Qt 5 or Qt 6 (for graphical PFD, in progress)  

## Example Console Output

```text
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

## Contributing

Contributions and suggestions are welcome — especially around the graphical display design or avionics modeling. Please feel free to open issues or pull requests.

---

**Author:** Nathan Foster  
**License:** MIT

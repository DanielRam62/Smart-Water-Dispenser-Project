# Smart Water Dispenser Project

This project involves the design, simulation, and implementation of a **Smart Water Dispenser** system. The system provides the user with the ability to select the water temperature (hot, cold, or lukewarm) and dispense water accordingly. The project was realized in two stages: 
1. **Hardware-Only Implementation**: Built entirely with analog and digital components, simulated using Multisim.
2. **Arduino-Based Implementation**: A microcontroller-based solution utilizing Arduino for real-time temperature monitoring and user interaction.

## Project Overview

The Smart Water Dispenser system was developed to provide precise temperature control and user feedback during water dispensing. The system supports the following features:
- **Hot Water**: 50°C to 90°C
- **Cold Water**: 5°C to 10°C
- **Lukewarm Water**: 25°C to 35°C
- **Real-Time Temperature Display**: Displayed on an LCD
- **User-Selectable Cup Size**: Choose from 4s, 8s, or 15s cup sizes
- **Safety Features**: Includes overheating protection and overflow warning

### Implementation Approaches

#### 1. Hardware-Only Implementation

The first phase of the project was developed using analog and digital circuits without the aid of a microcontroller. This involved the following key components:

- **Temperature Control Circuit**: Operational amplifiers were used to manage the water temperature, ensuring the correct temperature range for hot and cold water.
- **One-Shot Timer Circuits**: Managed water dispensing times based on the selected cup size.
- **Logic Gates**: Controlled the flow of water based on the user’s input.
- **Safety Features**: Included feedback mechanisms for stopping the water flow in case of overflows or overheating.

The design and simulation of the circuit were carried out in **Multisim**, where the functionality of each component was tested. After simulation, the system was implemented on a breadboard for real-world testing, and a **PCB layout** was designed for future production.

#### 2. Arduino-Based Implementation

In the second phase, an Arduino microcontroller was used to enhance the functionality and interactivity of the system. This version introduced real-time monitoring, LCD display for user feedback, and more flexibility in controlling the water flow and temperature. Key components and features in this implementation:

- **Temperature Sensors (NTC)**: Two sensors were used to monitor the hot and cold water temperatures. These readings were processed by the Arduino to control the water heating and cooling systems.
- **LCD Display**: Displayed real-time water temperature, cup size selection, and operational status.
- **Buttons**: Allowed the user to choose the water type (hot/cold/lukewarm) and cup size.
- **Water Pumps**: Controlled by the Arduino based on the user’s selection, allowing for precise control over the water volume.
- **LED Warning System**: Alerted the user if there was an issue, such as an overflow or overheating.

The **Arduino code** can be found in `arduino_implementation/code.cpp`. It handles all user inputs, manages water temperature, and controls the water pumps based on the selected cup size and temperature.

## Hardware-Only Implementation Details

The hardware-based system was simulated using **Multisim** before implementation. Below are the details of the major components:

### Temperature Control Circuit:
- **Hot Water Control**: Operates between 50°C and 90°C using an operational amplifier to manage heating elements.
- **Cold Water Control**: Operates between 5°C and 10°C using an operational amplifier to manage cooling elements.
  
### One-Shot Timer Circuits:
- Controlled the dispensing duration for 4s, 8s, and 15s cup sizes, using capacitors and resistors for timing.

### PCB Design:
- A PCB layout was created for this system to ensure compact and reliable operation. The layout minimizes noise and optimizes power efficiency.

## Arduino-Based Implementation Details

The Arduino-based version provided enhanced functionality, real-time monitoring, and user interactivity. The key features are detailed below:

### Sensors and Components:
- **Temperature Sensors (NTC)**: Analog sensors connected to the Arduino for real-time temperature readings of both hot and cold water.
- **LCD Display**: A 16x2 LCD module displays temperature and prompts for user interaction.
- **Water Pumps**: Controlled by the Arduino based on user-selected water type and cup size.
- **LED Warning System**: A simple warning system that alerts the user to potential issues such as overheating or water overflow.

### Arduino Code:
The code, located in `arduino_implementation/code.cpp`, implements the following functionality:
- **Temperature Monitoring**: Continuously monitors the hot and cold water temperatures, ensuring they remain within the desired range.
- **Water Dispensing**: Controls the water flow based on the selected cup size and type of water (hot, cold, or lukewarm).
- **User Interaction**: Buttons allow users to select the type of water and the cup size, and the system provides feedback on the LCD.

## Simulation and Testing

The system was thoroughly tested in both simulation and real-world implementation. The following tests were conducted:
- **Temperature Regulation**: Verified that the system maintained the correct temperature ranges for both hot and cold water.
- **User Interface**: Ensured the LCD provided correct feedback and that the buttons operated as expected.
- **Water Dispensing**: Confirmed that the water pumps dispensed the correct amount of water based on the selected cup size.

### Media
- A video demonstration of the system in action is available in `media/system_video.mp4`.
- Images of the system setup and components can be found in `media/system_images.png`.

## Files

- `hardware_implementation/`: Contains the circuit schematics, simulation results, and PCB designs.
- `arduino_implementation/`: Contains the Arduino code and wiring diagrams.
- `docs/`: Contains the project summary and presentation.
- `media/`: Contains video and images showcasing the project in action.

## Conclusion

This project demonstrates the successful design and implementation of a Smart Water Dispenser system using both traditional hardware-based approaches and modern microcontroller-based techniques. The Arduino-based solution offers enhanced real-time control and user interaction, while the hardware-only version provides a solid foundation in analog and digital circuit design.

---

© 2023 Daniel Ram. Licensed under the MIT License.

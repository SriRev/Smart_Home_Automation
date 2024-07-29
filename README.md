# Smart_Home_Automation
## Overview

This project enables smart home automation using NodeMCU microcontrollers and Sinric Pro as a third-party application. The system is designed to work with 230V electrical systems, making it suitable for use in many countries worldwide.

## Features

- Control lights, fans, and other appliances remotely
- Voice control integration with popular smart assistants
- Customizable schedules and routines
- Mobile app for easy device management

## Hardware Requirements

- NodeMCU ESP8266 microcontroller
- Relay modules (compatible with 230V)
- Power supply (5V for NodeMCU)
- Jumper wires
- Electrical enclosure (for safety)

## Software Requirements

- Arduino IDE
- Sinric Pro library
- ESP8266 board support package
- Sinric Pro account (free tier available)

## Setup Instructions

1. Install the Arduino IDE and required libraries
2. Set up a Sinric Pro account and create virtual devices
3. Wire the NodeMCU and relay modules according to the provided schematics
4. Flash the NodeMCU with the project code
5. Configure Wi-Fi credentials and Sinric Pro API keys
6. Install the Sinric Pro mobile app and link your devices

## Safety Warnings

- This project involves working with mains voltage (230V)
- Only attempt this project if you have experience with electrical systems
- Always disconnect power before making any changes to the wiring
- Use appropriate safety equipment and follow local electrical codes

## Troubleshooting

- Ensure your NodeMCU is connected to a stable Wi-Fi network
- Check that your Sinric Pro API keys are correctly entered in the code
- Verify that your relay modules are properly connected and functioning

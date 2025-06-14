# LED Control Website (ESP32)

This project uses an ESP32 to create a simple web server that lets you control an LED from any device connected to the same Wi-Fi network.

## What it Does

- Connects to your local Wi-Fi
- Hosts a web page with two buttons: ON and OFF
- Toggles the onboard LED based on button clicks

## Components Used

- ESP32 Development Board
- LED (optional, if not using built-in one)
- Resistor (220Ω, if external LED is used)
- Breadboard & Jumper wires

## Circuit Diagram

![LED Circuit](led_control.png)

## Files

- `ledcontrol_website.ino` – Arduino sketch for the ESP32
- `led_control.png` – Circuit image (optional)

## Setup Instructions

1. Update your Wi-Fi credentials in the code:
   ```cpp
   const char* ssid = "YOUR_SSID";
   const char* password = "YOUR_PASSWORD";

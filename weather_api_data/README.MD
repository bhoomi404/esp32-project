# 🌦️ ESP32 Weather API Project

This project allows an **ESP32** to connect to Wi-Fi and fetch **real-time weather data** from the **OpenWeatherMap API**. The city name is entered via the **Serial Monitor**, and weather information like temperature, humidity, pressure, and description is displayed.

---

## 🚀 Features

- 📡 Connects to WiFi
- 🌐 Sends HTTP GET requests to OpenWeatherMap
- 📊 Displays temperature, humidity, weather condition, and pressure
- 🧠 Parses JSON using ArduinoJson library
- 🖥️ User inputs city name via Serial Monitor

---

## 🔧 Hardware Required

- ESP32 board
- USB cable
- Arduino IDE with ESP32 support installed

---

## 📦 Libraries Used

Install these via the Arduino Library Manager:

- [`WiFi.h`](https://www.arduino.cc/en/Reference/WiFi) – to connect to WiFi
- [`HTTPClient.h`](https://www.arduino.cc/en/Reference/HTTPClient) – to make HTTP requests
- [`ArduinoJson`](https://arduinojson.org/) – to parse JSON data

---

## 🧠 How It Works

1. Connects ESP32 to your WiFi.
2. Waits for user input (city name) via Serial Monitor.
3. Sends request to:  


## 💡 Face Detection Smart Light

**ESP32 + OpenCV + Python + pyttsx3**

This project combines computer vision and microcontroller control to detect human faces using a webcam and toggle a connected light (or relay) using an ESP32 board via serial communication. It also provides voice feedback using `pyttsx3` for accessibility.

---

### ✨ Features

* Turns light **ON** when a face is detected
* Turns light **OFF** if no face is seen for a set duration
* Provides **voice feedback**: “Face detected” / “No face detected”
* Real-time face detection using OpenCV
* USB serial communication with ESP32

---

### 🔧 Hardware Required

| Component                    | Quantity |
| ---------------------------- | -------- |
| ESP32 (Nano or Dev Module)   | 1        |
| LED (or Relay Module + Bulb) | 1        |
| Resistor (220Ω for LED)      | 1        |
| USB Cable                    | 1        |
| Computer with Webcam         | 1        |

---

### 🔌 Connections

| ESP32 Pin | Connects To               |
| --------- | ------------------------- |
| GPIO 20   | LED Anode or Relay IN     |
| GND       | LED Cathode / Relay GND   |
| 5V / 3.3V | Relay VCC (if applicable) |

---

### 📁 Folder Contents

| File                    | Purpose                                           |
| ----------------------- | ------------------------------------------------- |
| `face_detect_light.py`  | Python script for OpenCV detection + TTS + Serial |
| `ArduinoReceiver.ino`   | ESP32 code to control light via serial commands   |
| `requirements.txt`      | Python library dependencies                       |
| `demo.gif` *(optional)* | Demo animation of the working project             |

---

### 🚀 How to Run

#### 💻 On Python Side (PC)

1. Install dependencies:

   ```bash
   pip install opencv-python pyserial pyttsx3
   ```

2. Connect ESP32 to your PC and note the COM port (e.g., `COM10`)

3. Run the Python script:

   ```bash
   python face_detect_light.py
   ```

#### 🔁 On Arduino Side (ESP32)

1. Open `ArduinoReceiver.ino` in Arduino IDE
2. Select your ESP32 board (e.g., Arduino Nano ESP32)
3. Upload the code
4. Ensure the **baud rate is 115200**

---

### 🎬 Demo

![demo](demo.gif)

This setup turns on a light when a face is detected and switches it off after a delay when no face is found.

---

### 🔊 Voice Output

The `pyttsx3` engine provides voice cues:

* “Face detected”
* “No face detected”

This adds an accessibility layer for users who are visually impaired.

---

### 🧑‍💻 Author

Developed by [bhoomi404](https://github.com/bhoomi404)

---




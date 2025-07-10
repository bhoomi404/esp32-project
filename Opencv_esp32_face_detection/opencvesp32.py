import cv2
import serial
import time
import pyttsx3

# Initialize serial connection (adjust COM port as needed)
ser = serial.Serial('COM10', 115200)
time.sleep(2)  # Allow time for ESP32 to reset

# Initialize text-to-speech engine
engine = pyttsx3.init()
engine.setProperty('rate', 150)

# Load Haar cascade classifier for face detection
face_cascade = cv2.CascadeClassifier(
    cv2.data.haarcascades + 'haarcascade_frontalface_default.xml'
)

# Start camera feed
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Error: Could not access the camera.")
    exit()

# Face detection state
light_on = False
last_seen = time.time()
face_timeout = 5  # seconds before turning light off

def speak(text):
    engine.say(text)
    engine.runAndWait()

while True:
    ret, frame = cap.read()
    if not ret:
        print("Error: Failed to grab frame.")
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray, scaleFactor=1.3, minNeighbors=5)
    current_time = time.time()

    if len(faces) > 0:
        last_seen = current_time
        if not light_on:
            ser.write(b'1')  # Turn on light
            light_on = True
            print("[INFO] Face detected → Light ON")
            speak("Face detected")
    elif light_on and (current_time - last_seen > face_timeout):
        ser.write(b'0')  # Turn off light
        light_on = False
        print("[INFO] No face detected → Light OFF")
        speak("No face detected")

    # Draw face rectangles
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
        cv2.putText(frame, f"Face ({len(faces)})", (x, y - 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

    # Display the camera feed
    cv2.imshow("Face Detection - Press 'q' to exit", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Cleanup
cap.release()
cv2.destroyAllWindows()
ser.close()

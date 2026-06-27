# ESP32-CAM Wi-Fi Controlled Robot Car

An open-source project featuring a mobile robot car built around the **ESP32-CAM** board. The robot can be driven remotely via an interactive web interface that streams real-time live video and handles movement commands simultaneously.

---

Features:

Parallel Operation (Asynchronous Handling):** Thanks to the underlying FreeRTOS and dual-port server design architecture, you can view the live MJPEG video stream and send driving commands at the same exact time.
Real-time Video Streaming: Live low-latency video feed directly from the OV2640 camera module to your browser.
Modern Web UI: A clean interface featuring intuitive, colorful rectangular click control buttons.
Onboard Flashlight Control: Toggle the built-in bright LED directly from the web interface for night driving.
Modular Code Structure: Uses a custom `Car_motors` C++ class to cleanly separate low-level motor driver logic from the network protocol.

---

Hardware Pinout Configuration:

Based on the default configuration in `sketch_jun9a.ino`:

| **Right Motor (-)** | GPIO 12 |
| **Right Motor (+)** | GPIO 13 |
| **Left Motor (-)** | GPIO 14 |
| **Left Motor (+)** | GPIO 15 |
| **Onboard Flash LED** | GPIO 4 |

---

Installation & Setup:

1. Clone the Repository
Open your terminal or command prompt and run:
```
git clone https://github.com/deniska-design/ESP32_CAM_web_control.git
cd ESP32_CAM_web_control
```
2. Configure Wi-Fi Credentials
Open the sketch_jun9a.ino file in your Arduino IDE. Locate lines 14-15 and replace the placeholders with your actual Wi-Fi network name and password:

```
const char *ssid = "YOUR_WIFI_NAME";
const char *password = "YOUR_WIFI_PASSWORD";
```

5. Choose the right board

```
Tools -> board -> esp32 -> AI thinker ESP32-CAM
```

4. Upload the Code
Connect your ESP32-CAM board to your PC using an FTDI adapter or a dedicated USB-to-Serial shield.

Select ESP32 Wrover Module (or your specific ESP32-CAM board) in the Arduino IDE boards manager.

Make sure to enable PSRAM in the IDE settings.

Hit Upload.

5. Run and Control
Once uploaded, disconnect the programming pins and power up the car.

Open the Serial Monitor at 115200 baud rate to see the initialization logs.

Once connected to your Wi-Fi, the ESP32 will print its local IP address (e.g., 119.168.1.50).

Enter this IP address into any web browser on a device connected to the same network.

Control your robot using the on-screen UI buttons or check out the camera feed!

---

Execution:

https://github.com/user-attachments/assets/9668f4eb-28dd-4800-ba90-a4b1d604a477

---

License:
This project is open-source. Anyone is completely free to download, modify, use, and distribute this software for personal or educational purposes.

# Home Automation Using ESP32 & Blynk

A home automation system built with ESP32 and the Blynk IoT platform. Control appliances remotely using your smartphone. Features dynamic Wi-Fi provisioning, OTA firmware updates, and physical buttons/indicators for ease of use.

---

## ⚙️ Features

- Remote control of appliances via Blynk app using virtual pins **V0–V3**  
- Over The Air (OTA) firmware updates  
- Dynamic Wi-Fi provisioning (i.e. setup Wi-Fi via app or temporary AP)  
- Physical LED indicators to display device state  
- Reset button to clear saved credentials or reset config  

---

## 🛠 Components & Files

| File / Module | Purpose |
|---------------|---------|
| `Edgent_ESP32.ino` | Main sketch: initializes Blynk, sets up pins & handles widget callbacks |
| `BlynkEdgent.h` | Handles Blynk Edgent framework integrations (Wi-Fi, OTA, etc.) |
| `Settings.h` | Configuration (template ID, firmware version, pins, etc.) |
| `OTA.h` | Code for over-the-air update logic |
| `ResetButton.h` | Functionality to reset stored credentials via a button press |
| `Indicator.h` | LED indicators for device status (e.g. connected / disconnected) |
| `ConfigMode.h` / `ConfigStore.h` | Handling Wi-Fi setup & storing configuration to memory |
| `Console.h` | For serial console debugging / logs |

---

## 🔌 Hardware Setup

- **ESP32** development board  
- Relays connected to GPIO pins 15, 2, 4, 5 (controlled via virtual pins V0, V1, V2, V3 respectively)  
- LED indicator pin(s)  
- Reset button wired to a suitable pin for clearing stored credentials  

---

## 📲 How It Works

1. On first boot (or after reset), ESP32 starts in configuration mode or uses stored Wi-Fi credentials.  
2. Connect to Wi-Fi / provide credentials via Blynk Edgent.  
3. Once connected, the Blynk mobile app can control the relays via virtual pins (V0–V3).  
4. Physical LED(s) show connection / status.  
5. OTA updates allow firmware to be updated without physical access.  

---

## 🚀 Getting Started

1. Clone this repository to your local machine.  
2. Open `Edgent_ESP32.ino` in Arduino IDE / PlatformIO.  
3. In `Settings.h`, fill in your Blynk template ID, firmware version, and other credentials as needed.  
4. Connect your ESP32, upload the code.  
5. Set up the relays, buttons, indicator LED.  
6. Use the Blynk app (create or use existing template) to map virtual pins V0–V3 to switches/widgets.  

---

## 📋 Requirements

- ESP32 board  
- Blynk account + template configured  
- Relays, LED, button hardware  
- Arduino IDE (or other tooling)  
- Internet connection for OTA and Blynk communications  

---



## 📧 Contact / Issues

If you find any bugs or want new features, feel free to open an issue or submit a pull request.  
You can also reach me at: *sajinjr10root66@gmail.com*

---


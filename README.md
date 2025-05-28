# Smart Greenhouse Monitoring & Automation System with Bluetooth App Control
📖 Overview
This Smart Greenhouse System is built using an Arduino UNO and integrates multiple sensors to automatically monitor and manage a greenhouse environment. It displays real-time data on an LCD and communicates with a Bluetooth mobile app using the HC-06 module, allowing for remote monitoring and control.

🧰 Components Used
Component	Function
Arduino UNO	Microcontroller
DHT11	Temperature & Humidity Sensor
MQ135	Air Quality Sensor
Soil Moisture Sensor	Soil Wetness Detection
LiquidCrystal_I2C (20x4)	Data Display
HC-06 Bluetooth Module	Wireless communication with phone
Fan (Pin 3)	Turns on if temp/humidity too high
Pump (Pin 6)	Turns on if soil moisture is low
Power Source	5V Battery/USB

📟 Features
✅ Sensor Monitoring:
Temperature (°C)

Humidity (%)

Air Quality (PPM)

Soil Moisture (%)

✅ Automated Responses:
Fan ON if temp > 35°C or humidity > 95%

Exhaust ON if pollution > 60 PPM

Water Pump ON if soil moisture ≤ 60%

✅ User Interface:
Real-time display on 20x4 LCD

Live data streaming to Serial Monitor

Bluetooth mobile app for monitoring & override control

🔌 Pin Configuration

Pin	Connected Device
A0	Soil Moisture Sensor
A1	MQ135 Air Quality Sensor
D3	FAN/EXHAUST Output
D6	Water Pump Output
D7	DHT11 Sensor
TX/RX	HC-06 Bluetooth Module
I2C	20x4 LCD (SDA/SCL)

🧾 Serial Output Format

25.0 °C|60.0 %|45.0|70.0 %
📱 Bluetooth Mobile App Integration
🔧 Requirements:
Android device

HC-06 Bluetooth module

Bluetooth Terminal App or custom app (MIT App Inventor recommended)

🔌 Connecting HC-06:
VCC → 5V

GND → GND

TX → RX (Arduino)

RX → TX (Arduino) (Use voltage divider or level shifter if needed)


🔄 How It Works
Sensors collect environmental data every few seconds.

Data is:

Displayed on the LCD

Sent to the serial monitor/Bluetooth

Based on thresholds, outputs (fan, exhaust, pump) are activated automatically.

User can also override control using Bluetooth from their phone.

🚀 Future Enhancements
Add support for Blynk or MQTT (using ESP8266)

Add light or UV sensors

Create a custom Android app with better UI

Store readings in SD card or cloud

📸 Preview (LCD Output)

Temperature :  24.5
Humidity :     60.0
Pollution :    45.0
Soil Moisture: 65

📚 Summary
This project makes greenhouse monitoring smarter and more accessible through automatic actions and Bluetooth-based manual control. It’s ideal for:

Home gardens

Hydroponics setups

Educational IoT projects


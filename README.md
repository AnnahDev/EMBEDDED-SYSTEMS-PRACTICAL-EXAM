<h1 style="color:#0066cc;">🌡️ Temperature Monitoring Embedded System</h1>

<span style="color:#1f8f3f; font-weight:bold;">Student</span><br>
**Candidate Name:** `IZERE ANNA`

## 🔧 Project Title
**Temperature Monitoring Embedded System using Arduino UNO, LCD, Serial Communication and MQTT**

## 📌 Project Description
This project implements an embedded temperature monitoring system.

The Arduino Uno reads temperature data from an LM35 sensor, displays the value on a 16×2 LCD, and transmits the temperature to a PC using USB Serial Communication.

A Python application running on the PC receives the temperature values and publishes them to an MQTT broker hosted on a Virtual Private Server (VPS).

## 🎯 Objectives
The project demonstrates:

- ✅ Temperature sensing
- ✅ LCD interfacing
- ✅ Horizontal scrolling text
- ✅ Serial communication
- ✅ Python serial programming
- ✅ MQTT communication
- ✅ IoT data transmission

## 📁 Project Structure
```
examPra/
├── README.md
├── requirements.txt
├── arduino/
│   └── temperature_monitor.ino
└── pc_client/
    └── pc_monitor.py
```

## 🧠 System Architecture

<span style="color:#004b87; font-weight:bold;">Architecture diagram</span>

┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                             SYSTEM ARCHITECTURE DIAGRAM                                  │
└─────────────────────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                         │
│  ┌────────────────────────┐    ┌───────────────────┐    ┌──────────────────────────────┐   │
│  │                        │    │                   │    │                              │   │
│  │  Temperature Sensor    │───▶│   Arduino Uno     │────│  16x2 LCD Display            │   │
│  │      (LM35)            │    │      A0 input     │    │  Row 1: Candidate name       │   │
│  │                        │    │                   │    │  Row 2: Temperature value    │   │
│  │  VCC → 5V              │    │  RS → D12         │    │                              │   │
│  │  GND → GND             │    │  EN → D11         │    │                              │   │
│  │  OUT → A0              │    │  D4 → D5          │    │                              │   │
│  └────────────────────────┘    │  D5 → D4          │    └──────────────────────────────┘   │
│                                 │  D6 → D3          │                                         │
│                                 │  D7 → D2          │                                         │
│                                 └───────────────────┘                                         │
│                                           │                                                 │
│                                           │ USB Serial (9600 baud)                           │
│                                           ▼                                                 │
│                                 ┌───────────────────────────┐                               │
│                                 │                           │                               │
│                                 │     PC Client Program     │                               │
│                                 │     (Python with pyserial)│                               │
│                                 │                           │
│                                 │  - Read serial data       │                               │
│                                 │  - Display incoming value │                               │
│                                 │  - Publish to MQTT        │                               │
│                                 └───────────────────────────┘                               │
│                                           │                                                 │
│                                           │ MQTT Protocol                                   │
│                                           │ Topic: sensor/temperature/reading              │
│                                           ▼                                                 │
│                                 ┌───────────────────────────┐                               │
│                                 │                           │                               │
│                                 │      MQTT Broker (VPS)    │                               │
│                                 │   (Mosquitto / EMQX / etc)│                               │
│                                 │                           │
│                                 └───────────────────────────┘                               │
│                                           │                                                 │
│                                           │ MQTT Subscription                               │
│                                           ▼                                                 │
│                                 ┌───────────────────────────┐                               │
│                                 │                           │                               │
│                                 │    Remote Subscribers     │                               │
│                                 │   (Web client / IoT apps) │                               │
│                                 │                           │
│                                 └───────────────────────────┘                               │
│                                                                                         │
└─────────────────────────────────────────────────────────────────────────────────────────┘

## 🔌 Communication Channels

- **Serial communication:** `Arduino Uno USB Serial`
- **Example port:** `COM3` (Windows) / `/dev/ttyUSB0` (Linux)
- **Baud rate:** `9600`

- **MQTT topic:** `sensor/temperature/reading`
- **MQTT broker:** VPS hostname or IP
- **MQTT port:** `1883`

## 🔄 Data Flow
Temperature Sensor

↓

Arduino UNO

↓

LCD Display

↓

USB Serial

↓

Python Program

↓

MQTT

## 📺 LCD Display Output
- **First Row:** Candidate Name
- **Second Row:** `Temp: 28.5 C`

## 💻 Example Serial Output
- `28.50`
- `28.63`
- `28.71`

## 🌐 MQTT Configuration
- **Broker:** `YOUR VPS IP`
- **Port:** `1883`
- **Topic:** `sensor/temperature/reading`
- **Example payload:** `28.65`

## ✅ Expected Output
**LCD**
- `Anne Izere`
- `Temp:28.7 C`

**PC Console**
- `Temperature = 28.70 C`
- `Temperature = 28.81 C`
- `Temperature = 28.93 C`

**MQTT Broker**
- Topic: `sensor/temperature/reading`
- Payload: `28.70`

## 📎 Hardware Connections

**LM35 Temperature Sensor → Arduino Uno**

| LM35 Pin | Arduino Pin | Description |
|----------|-------------|-------------|
| VCC (Pin 1) | 5V | Power Supply |
| GND (Pin 3) | GND | Ground |
| OUT (Pin 2) | A0 | Analog input for temperature |

**16x2 LCD Display → Arduino Uno**

| LCD Pin | Arduino Pin | Description |
|---------|-------------|-------------|
| VSS (1) | GND | Ground |
| VDD (2) | 5V | Power Supply |
| V0 (3) | Potentiometer | Contrast adjustment |
| RS (4) | D12 | Register Select |
| RW (5) | GND | Write mode |
| EN (6) | D11 | Enable |
| D4 (11) | D5 | Data Bit 4 |
| D5 (12) | D4 | Data Bit 5 |
| D6 (13) | D3 | Data Bit 6 |
| D7 (14) | D2 | Data Bit 7 |
| A (15) | 5V + 220Ω | Backlight Anode |
| K (16) | GND | Backlight Cathode |



Data Flow
Temperature Sensor

↓

Arduino UNO

↓

LCD Display

↓

USB Serial

↓

Python Program

↓

MQTT 



LCD Display
First Row
Candidate Name

Second Row
Temp: 28.5 C


Serial Communication
Communication Medium

USB Serial
Baud Rate

9600
Example Data

28.50

28.63

28.71


MQTT Configuration
Broker

YOUR VPS IP
Port

1883
Topic

temperature/readings
Example Published Message

28.65




Expected Output
LCD

Anne Izere

Temp:28.7 C
PC Console
Temperature = 28.70 C
Temperature = 28.81 C
Temperature = 28.93 C

MQTT Broker
Topic:
temperature/readings
Payload:
28.70
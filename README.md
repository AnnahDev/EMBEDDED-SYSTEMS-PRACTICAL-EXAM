Temperature Monitoring Embedded System
Student
Candidate Name:
IZERE ANNA 


Project Title
Temperature Monitoring Embedded System using Arduino UNO, LCD, Serial Communication and MQTT


Project Description
This project implements an embedded temperature monitoring system.

The Arduino Uno reads temperature data from an LM35 sensor, displays the value on a 16×2 LCD, and transmits the temperature to a PC using USB Serial Communication.

A Python application running on the PC receives the temperature values and publishes them to an MQTT broker hosted on a Virtual Private Server (VPS).



Objectives

The project demonstrates:

Temperature sensing
LCD interfacing
Horizontal scrolling text
Serial communication
Python serial programming
MQTT communication
IoT data transmission




Hardware Used
Component	Purpose
Arduino Uno	Main controller
LM35 Temperature Sensor	Temperature measurement
16×2 LCD (I2C)	Display
USB Cable	Serial Communication
PC	Monitoring
MQTT Broker (VPS)	IoT Communication
Software Used
Arduino IDE

Python 3

VS Code (optional)

MQTT Broker

PySerial

Paho MQTT


System Architecture
┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                        EMBEDDED TEMPERATURE MONITORING SYSTEM                           │
│                              SYSTEM ARCHITECTURE DIAGRAM                                │
└─────────────────────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                         │
│  ┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐                     │
│  │                 │    │                 │    │                 │                     │
│  │   Temperature   │    │   Arduino Uno   │    │   16x2 LCD      │                     │
│  │   Sensor (LM35) │───▶│   Pin A0        │────│   Display       │                     │
│  │                 │    │                 │    │                 │                     │
│  │  - VCC → 5V     │    │  Pin 12 → RS    │    │  Row 1: Name    │                     │
│  │  - GND → GND    │    │  Pin 11 → EN    │    │  Row 2: Temp    │                     │
│  │  - OUT → A0     │    │  Pin 5  → D4    │    │                 │                     │
│  └─────────────────┘    │  Pin 4  → D5    │    └─────────────────┘                     │
│                         │  Pin 3  → D6    │                                             │
│                         │  Pin 2  → D7    │                                             │
│                         └─────────────────┘                                             │
│                                   │                                                     │
│                                   │ USB Serial                                          │
│                                   │ (9600 baud, 8N1)                                   │
│                                   ▼                                                     │
│                         ┌─────────────────────────────────────┐                        │
│                         │                                     │                        │
│                         │         PC CLIENT PROGRAM           │                        │
│                         │         (Python with pyserial)      │                        │
│                         │                                     │                        │
│                         │  ┌─────────────────────────────┐   │                        │
│                         │  │ 1. Read Serial Data         │   │                        │
│                         │  │ 2. Parse Temperature Value  │   │                        │
│                         │  │ 3. Display Real-time Data   │   │                        │
│                         │  │ 4. Publish to MQTT Broker   │   │                        │
│                         │  └─────────────────────────────┘   │                        │
│                         │                                     │                        │
│                         └─────────────────────────────────────┘                        │
│                                   │                                                     │
│                                   │ MQTT Protocol                                       │
│                                   │ Topic: sensors/temperature                          │
│                                   ▼                                                     │
│                         ┌─────────────────────────────────────┐                        │
│                         │                                     │                        │
│                         │         MQTT BROKER (VPS)           │                        │
│                         │         Mosquitto / EMQX            │                        │
│                         │                                     │                        │
│                         └─────────────────────────────────────┘                        │
│                                   │                                                     │
│                                   │ MQTT Subscription                                    │
│                                   ▼                                                     │
│                         ┌─────────────────────────────────────┐                        │
│                         │                                     │                        │
│                         │      REMOTE SUBSCRIBERS             │                        │
│                         │   (Other IoT Clients / Web Apps)    │                        │
│                         │                                     │                        │
│                         └─────────────────────────────────────┘                        │
│                                                                                         │
└─────────────────────────────────────────────────────────────────────────────────────────┘

                              COMMUNICATION PROTOCOLS
┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                         │
│  ┌───────────────────────┐    ┌──────────────────────────────────────────────────────┐ │
│  │  SERIAL COMMUNICATION │    │  MQTT COMMUNICATION                                  │ │
│  ├───────────────────────┤    ├──────────────────────────────────────────────────────┤ │
│  │  Interface: USB Serial│    │  Protocol: MQTT v3.1.1                               │ │
│  │  Baud Rate: 9600      │    │  Topic: sensors/temperature                          │ │
│  │  Data Bits: 8         │    │  QoS: 1                                             │ │
│  │  Stop Bits: 1         │    │  Port: 1883                                         │ │
│  │  Parity: None         │    │  Format: JSON                                        │ │
│  │  Flow Control: None   │    │  Payload: {"temperature": 25.5, "unit": "C"}        │ │
│  └───────────────────────┘    └──────────────────────────────────────────────────────┘ │
│                                                                                         │
└─────────────────────────────────────────────────────────────────────────────────────────┘

                               SYSTEM FLOW
┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                         │
│  Temperature → Analog Reading → ADC Conversion → Temperature Calculation → Display     │
│  Sensor      (A0)           (10-bit)        (°C = voltage * 100)    on LCD             │
│                                                                                         │
│                              ↓                                                         │
│                                                                                         │
│  Send via Serial → PC Reads → Parses → Displays → Publishes to MQTT → Remote Clients   │
│  (JSON Format)   Serial Port  Data     on Screen   Broker (VPS)    Subscribe            │
│                                                                                         │
└─────────────────────────────────────────────────────────────────────────────────────────┘

                               HARDWARE CONNECTIONS
┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                         │
│  LM35 Temperature Sensor → Arduino Uno:                                                │
│  ┌─────────────┬─────────────┬─────────────────────────────────────────────────────┐  │
│  │ LM35 Pin    │ Arduino Pin │ Description                                         │  │
│  ├─────────────┼─────────────┼─────────────────────────────────────────────────────┤  │
│  │ VCC (Pin 1) │ 5V          │ Power Supply                                        │  │
│  │ GND (Pin 3) │ GND         │ Ground Connection                                   │  │
│  │ OUT (Pin 2) │ A0          │ Analog Input for Temperature Reading                │  │
│  └─────────────┴─────────────┴─────────────────────────────────────────────────────┘  │
│                                                                                         │
│  16x2 LCD Display → Arduino Uno:                                                       │
│  ┌─────────────┬─────────────┬─────────────────────────────────────────────────────┐  │
│  │ LCD Pin     │ Arduino Pin │ Description                                         │  │
│  ├─────────────┼─────────────┼─────────────────────────────────────────────────────┤  │
│  │ VSS (1)     │ GND         │ Ground                                              │  │
│  │ VDD (2)     │ 5V          │ Power Supply                                        │  │
│  │ V0 (3)      │ Potentiometer│ Contrast Adjust (10k pot)                          │  │
│  │ RS (4)      │ Pin 12      │ Register Select                                     │  │
│  │ RW (5)      │ GND         │ Read/Write (GND = Write)                            │  │
│  │ EN (6)      │ Pin 11      │ Enable                                              │  │
│  │ D4 (11)     │ Pin 5       │ Data Bit 4                                          │  │
│  │ D5 (12)     │ Pin 4       │ Data Bit 5                                          │  │
│  │ D6 (13)     │ Pin 3       │ Data Bit 6                                          │  │
│  │ D7 (14)     │ Pin 2       │ Data Bit 7                                          │  │
│  │ A (15)      │ 5V + 220Ω   │ Backlight Anode (with resistor)                     │  │
│  │ K (16)      │ GND         │ Backlight Cathode                                   │  │
│  └─────────────┴─────────────┴─────────────────────────────────────────────────────┘  │
│                                                                                         │
└─────────────────────────────────────────────────────────────────────────────────────────┘



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
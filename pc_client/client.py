import serial
import time
import paho.mqtt.client as mqtt

# CONFIGURATION
SERIAL_PORT = 'COM5' \
''  # Change to '/dev/ttyACM0' on Linux/Mac or check Device Manager
BAUD_RATE = 9600
MQTT_BROKER = "broker.hivemq.com"  # Using a free public VPS broker for the practical test
MQTT_PORT = 1883
MQTT_TOPIC = "vps/candidate/temperature"

# Initialize MQTT Client
mqtt_client = mqtt.Client()

try:
    print(f"Connecting to MQTT Broker: {MQTT_BROKER}...")
    mqtt_client.connect(MQTT_BROKER, MQTT_PORT, 60)
    mqtt_client.loop_start()
    print("MQTT Connected successfully.")
except Exception as e:
    print(f"Failed to connect to MQTT: {e}")
    exit(1)

# Initialize Serial Connection
try:
    print(f"Opening Serial Port {SERIAL_PORT}...")
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    time.sleep(2)  # Wait for Arduino to reboot
    print("Serial connected. Awaiting data...")
except Exception as e:
    print(f"Serial Connection Error: {e}")
    exit(1)

# Main Loop
try:
    while True:
        if ser.in_waiting > 0:
            # Read line and decode
            raw_data = ser.readline().decode('utf-8').strip()
            
            if raw_data:
                try:
                    temp_val = float(raw_data)
                    timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
                    
                    # Display in Real Time
                    print(f"[{timestamp}] Incoming Temperature: {temp_val}°C")
                    
                    # Publish to MQTT Broker
                    payload = str(temp_val)
                    mqtt_client.publish(MQTT_TOPIC, payload, qos=1)
                    print(f" -> Published to topic '{MQTT_TOPIC}': {payload}")
                    
                except ValueError:
                    # Ignore corrupted line fragments on startup
                    pass
                    
        time.sleep(0.1)

except KeyboardInterrupt:
    print("\nShutting down client safely...")
finally:
    ser.close()
    mqtt_client.loop_stop()
    mqtt_client.disconnect()
    print("Resources released.")
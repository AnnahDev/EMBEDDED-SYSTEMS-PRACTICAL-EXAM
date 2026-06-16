#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize I2C LCD (Address 0x27 is standard for 16x2 screens)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int tempPin = A0;
const char candidateName[] = "IZERE ANNA";
const int displayWidth = 16;

unsigned long lastScrollMillis = 0;
unsigned long lastSendMillis = 0;
int scrollOffset = 0;
const unsigned long scrollInterval = 400; 
const unsigned long sendInterval = 1000;   

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  Serial.begin(9600);
  
  lcd.setCursor(0, 0);
  lcd.print("Temperature Sys");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();
}

float readTemperatureC() {
  int adc = analogRead(tempPin);
  float voltage = adc * (5.0 / 1023.0);
  float tempC = voltage * 100.0;
  return tempC;
}

void showCandidateName() {
  int nameLen = strlen(candidateName);

  if (nameLen <= displayWidth) {
    lcd.setCursor(0, 0);
    lcd.print(candidateName);
    for (int i = nameLen; i < displayWidth; i++) {
      lcd.print(' ');
    }
    return;
  }

  if (millis() - lastScrollMillis >= scrollInterval) {
    scrollOffset++;
    lastScrollMillis = millis();
  }

  String scrollText = String(candidateName) + "    ";
  int scrollLen = scrollText.length();
  if (scrollOffset >= scrollLen) {
    scrollOffset = 0;
  }

  String windowText = scrollText.substring(scrollOffset) + scrollText.substring(0, scrollOffset);
  windowText = windowText.substring(0, displayWidth);

  lcd.setCursor(0, 0);
  lcd.print(windowText);
}

void loop() {
  float temperature = readTemperatureC();
  showCandidateName();

  // Print to Local Hardware LCD Screen
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223); // Degree symbol
  lcd.print("C   ");

  // Stream raw cleanly to the Python serial link
  if (millis() - lastSendMillis >= sendInterval) {
    Serial.println(temperature, 1); 
    lastSendMillis = millis();
  }

  delay(50); 
}
#include <FrSky.h>

FrSky frsky;

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop() {
  if (Serial2.available()) {
    char c = Serial2.read();
    if (frsky.update(c)) { // frsky_update() returns 1 if a complete packet was successfully decoded, otherwise 0
      Serial.print("TX RSSI: ");
      Serial.println(frsky.getLink_up());
      Serial.print("Telemetry RSSI: ");
      Serial.println(frsky.getLink_dn());
      Serial.print("RX Voltage: ");
      Serial.println(frsky.getRX_a1()*0.0517647058824); // The internal sensor has a 4:1 divider, so the value is 0-13,2V in 255 steps or 0,052V per step
      Serial.print("A2 Voltage: ");
      Serial.println(frsky.getRX_a1()*0.0129411764706); // A2 without divider is 0-3,3V in 255 steps or 0,013V per step
    }
  }
}
  

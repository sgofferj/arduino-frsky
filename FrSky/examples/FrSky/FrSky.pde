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
    if (frsky.update(c)) {
      Serial.print("TX RSSI: ");
      Serial.println(frsky.getLink_up());
      Serial.print("Telemetry RSSI: ");
      Serial.println(frsky.getLink_dn());
      Serial.print("RX Voltage: ");
      Serial.println(frsky.getRX_a1()*0.0517647058824);
      Serial.print("A2 Voltage: ");
      Serial.println(frsky.getRX_a1()*0.0129411764706);
    }
  }
}
  

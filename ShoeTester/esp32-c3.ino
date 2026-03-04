#define RX_PIN 20
#define TX_PIN 5

void setup() {
  Serial.begin(9600);
  Serial1.begin(19200, SERIAL_8N1, RX_PIN, TX_PIN);

  Serial.println("ESP32 Shoe Tester Initialized");
}

void loop() {

  if (Serial1.available()) {

    String data = Serial1.readStringUntil('\n');
    data.trim();

    Serial.println("Raw Data: " + data);

    int commaIndex = data.indexOf(',');

    if (commaIndex > 0) {

      // ค่า measurement
      String shoeValue = data.substring(0, commaIndex);

      // ค่า status
      String statusValue = data.substring(commaIndex + 1);

      shoeValue.replace("\"", "");
      shoeValue.trim();

      statusValue.replace("\"", "");
      statusValue.trim();

      float shoe = shoeValue.toFloat();

      // JSON Output
      Serial.print("{\"shoe\":");
      Serial.print(shoe);
      Serial.print(",\"status\":\"");
      Serial.print(statusValue);
      Serial.println("\"}");
    }
  }
}

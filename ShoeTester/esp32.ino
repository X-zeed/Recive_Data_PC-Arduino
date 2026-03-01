#define RX_PIN 23
#define TX_PIN 22

void setup() {
  Serial.begin(9600);
  Serial2.begin(19200, SERIAL_8N1, RX_PIN, TX_PIN);

  Serial.println("ESP32 Shoe Tester Initialized");
}

void loop() {

  if (Serial2.available()) {

    String data = Serial2.readStringUntil('\n');  // อ่านทีละบรรทัด
    data.trim();  // ลบช่องว่างหัวท้าย

//    Serial.println("Raw Data: " + data);

    // แยกเอาค่าก่อนเครื่องหมาย comma
    int commaIndex = data.indexOf(',');

    if (commaIndex > 0) {

      String shoeValue = data.substring(0, commaIndex);

      shoeValue.replace("\"", "");  // ลบเครื่องหมาย "
      shoeValue.trim();             // ลบ space

      float shoe = shoeValue.toFloat();

      // แสดงผลแบบ JSON
      Serial.print("{\"shoe\":");
      Serial.print(shoe);
      Serial.println("}");
    }
  }
}

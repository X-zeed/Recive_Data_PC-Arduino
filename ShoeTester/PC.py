import serial
import json

PORT = "COM8"

ser = serial.Serial(PORT, 9600, timeout=1)

print("Connected to ESP32-C3...")

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode("utf-8").strip()

        try:
            # แปลง string เป็น JSON
            json_data = json.loads(data)

            # ดึงค่า
            shoe_value = json_data["shoe"]
            status_value = json_data["status"]

            print("Shoe Value:", shoe_value)
            print("Status:", status_value)
            print("------------------")

        except:
            # ถ้าไม่ใช่ JSON จะข้ามไป
            pass

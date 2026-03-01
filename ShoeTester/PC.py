import serial
import json

# เปลี่ยน COM ให้ตรงกับของคุณ
ser = serial.Serial("COM7", 9600, timeout=1)

print("Connected to ESP32...")

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode("utf-8").strip()
        
        try:
            # แปลง string เป็น JSON
            json_data = json.loads(data)
            
            # ดึงค่า shoe
            shoe_value = json_data["shoe"]
            
            print("Shoe Value:", shoe_value)

        except:
            # ถ้าไม่ใช่ JSON จะข้ามไป
            pass

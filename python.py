import serial

# เปลี่ยน COM ให้ตรงกับของคุณ
ser = serial.Serial("COM7", 9600, timeout=1)

print("Connected to ESP8266...")

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode("utf-8").strip()
        print("Received:", data)

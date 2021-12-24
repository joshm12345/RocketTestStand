import serial
import time
import csv
file_path = "/Users/joshmorrow/Desktop/rocket test stand/test1.csv"

ser = serial.Serial('/dev/cu.wchusbserial14230')
ser.flushInput()

while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        with open(file_path,"a") as f:
            writer = csv.writer(f,delimiter=",")
            writer.writerow([time.time(),decoded_bytes])
    except:
        break

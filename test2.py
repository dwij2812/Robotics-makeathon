import serial
import time
import requests
import json
import re
firebase_url = 'https://iot-data-d6cb8.firebaseio.com/'
#Connect to Serial Port for communication
ser = serial.Serial('COM11', 250000, timeout=0)
#Setup a loop to send Temperature values at fixed intervals
#in seconds


fixed_interval = 1
while 1:
  x = []
  try:
    #temperature value obtained from Arduino + DH11 Temp Sensor          
    temperature_c = ser.readline().decode('utf-8')
    x=re.split(" ",temperature_c)
    #current time and date
    time_hhmmss = time.strftime('%H:%M:%S')
    date_mmddyyyy = time.strftime('%d/%m/%Y')
    #current location name
    temperature_location = 'VIT-CHENNAI';
    #print (temperature_c + ',' + time_hhmmss + ',' + date_mmddyyyy + ',' + temperature_location)
     
  #insert record
    if(len(x)==4):
      data = {'date':date_mmddyyyy,'time':time_hhmmss,'value1':x[0],'value2':x[1],'value3':x[2],'value4':x[3]}
      result = requests.post(firebase_url + '/' + temperature_location + '/temperature.json', data=json.dumps(data))
      print ('Record inserted. Result Code = ' + str(result.status_code) + ',' + result.text)
      time.sleep(fixed_interval)
    else:
      print("bol na aunty aau kya")
    
  except IOError:
    print("chacha")
    print('Error! Something went wrong.')
    time.sleep(fixed_interval)

int sensorPin = 0;
double alpha = 0.75;
int period = 1500;
double change = 0.0;
double minval = 0.0;
#include <SimpleDHT.h>
int pinDHT11 = 3;
SimpleDHT11 dht11;
void setup ()
{
  Serial.begin (9600);
  pinMode(13, OUTPUT); // onboard LED
 digitalWrite(13, LOW); // turn off onboard LED
 pinMode(5, INPUT); // connect to Vibration Sensor S pin
}
void loop ()
{
    static double oldValue = 0;
    static double oldChange = 0;
 
    int rawValue = analogRead (sensorPin);
    double value = alpha * oldValue + (1 - alpha) * rawValue;
 
    byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  Serial.print (rawValue);
    Serial.print (",");
    Serial.println (value);
    oldValue = value;
    
  if (digitalRead(5) == LOW){
    digitalWrite(13, HIGH); // turn ON LED
  }
  else{
    digitalWrite(13, LOW);
  }
 
    delay (period);
}

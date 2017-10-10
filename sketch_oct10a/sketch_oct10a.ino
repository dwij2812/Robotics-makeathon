int sensorPin = 0;
double alpha = 0.75;
int period = 1000;
double change = 0.0;
double minval = 0.0;
#include <SimpleDHT.h>
int pinDHT11 = 3;
SimpleDHT11 dht11;
int inPin = 4;   // choose the input pin (for a pushbutton)
int val = 0;
void setup ()
{
  Serial.begin (250000);
  pinMode(13, OUTPUT); // onboard LED
 digitalWrite(13, LOW); // turn off onboard LED
 pinMode(4, INPUT);
 pinMode(5, INPUT); 
 
 delay(500);
}
void loop ()
{
  val = digitalRead(inPin);
  byte button=0;// read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    button=0;// turn LED OFF
  } else {
    button=1;// turn LED ON
  }
    static double oldValue = 0;
    static double oldChange = 0;
    byte temperature = 0;
    
 
    int rawValue = analogRead (sensorPin);
    int tilt=0;
    double value = alpha * oldValue + (1 - alpha) * rawValue;
 
    
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if (digitalRead(5) == LOW){
    digitalWrite(13, HIGH);
    tilt=1;
  }
  else{
    digitalWrite(13, LOW);
    tilt=0;
  }
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }
  //Serial.println(temperature,humidity,value,tilt);
    oldValue = value; 
  String thisString_1=String(temperature);
  String thisString_2=String(humidity);
  String thisString_3=String(value);
  String thisString_4=String(tilt);
  String thisString_5=String(button);
  Serial.println(thisString_1+" "+thisString_2+" "+thisString_3+" "+thisString_4+" "+thisString_5);
 delay (period);
}


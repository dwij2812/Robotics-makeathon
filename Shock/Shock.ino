/*********************************************************
Vibration Sensor Keys 002
Connections::
- on Sensor Board to Arduino Gnd
Middle pin on Sensor Board to Arduino 5 volts
S pin on Sensor Board to Arduino pin 5

*************************************************************/
void setup() {
 pinMode(13, OUTPUT); // onboard LED
 digitalWrite(13, LOW); // turn off onboard LED
 pinMode(5, INPUT); // connect to Vibration Sensor S pin
}


void loop() {
  if (digitalRead(5) == LOW){
    digitalWrite(13, HIGH); // turn ON LED
    delay(500);
  }
  else{
    digitalWrite(13, LOW);
  }
}

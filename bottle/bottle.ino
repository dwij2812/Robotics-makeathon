int val=0;
int in=2;
float volume=0;
int count=0;
void setup() {
  pinMode(2,INPUT);
  Serial.begin(9600);

}

void loop() {
  val=digitalRead(in);
  if(val==HIGH){
    count=count+1;
    delay(500);
    Serial.println("The sensor is ON now");
    }
   else{
    volume=22.85*count;
    count=0;
    if(0<int(volume)<=750){
    Serial.println(volume);
    delay(500);
    }
    else{
      Serial.println("The full bottle of 750 ml is drank!");
      }
    }

}

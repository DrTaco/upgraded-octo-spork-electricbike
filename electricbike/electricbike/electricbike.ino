#define buzzer 13
int outputValue = 0; 
int highConfirm = 0;
int lowConfirm = 0;
int armedState = 0;


void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  beep(3,100);
}

// the loop function runs over and over again forever
void loop() {
    int sensorValue = analogRead(A0);
    outputValue = abs(map(sensorValue, 420, 875, 0, 250));
    if (armedState != 1){
      if (outputValue == 250) highConfirm = 1;
      if (outputValue == 0 && highConfirm == 1) lowConfirm = 1;
      if (lowConfirm == 1 && highConfirm == 1) armedState = 1;
    }
    if (armedState == 1 && outputValue >= 5 && outputValue < 255) {
      Serial.println(outputValue); 
    }
    else {
      Serial.println(0);
    }
    
}

void beep(int amount, int del) {
  for (int i=0; i<amount; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(del); 
    digitalWrite(buzzer, LOW);
    delay(del); 
  }
}


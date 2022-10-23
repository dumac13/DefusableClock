//Pins for segments
int segApin = 2;
int segBpin = 3;
int segCpin = 4;
int segDpin = 5;
int segEpin = 6;
int segFpin = 7;
int segGpin = 8;
//pins for digits
int dig1pin = 9;
int dig2Pin = 10;
int dig3Pin = 11;
int dig4Pin = 12;

void setup() {
//Start serial monitor
  Serial.begin(9600);
  Serial.println(__FILE__); //Prints on serial monitor sketch name & local path
  delay(1000);
//Sets pins as OUTPUTs  
pinMode(segApin, OUTPUT);
pinMode(segBpin, OUTPUT);
pinMode(segCpin, OUTPUT);
pinMode(segDpin, OUTPUT);
pinMode(segEpin, OUTPUT);
pinMode(segFpin, OUTPUT);
pinMode(segGpin, OUTPUT);
pinMode(dig1pin, OUTPUT);
pinMode(dig2Pin, OUTPUT);
pinMode(dig3Pin, OUTPUT);
pinMode(dig4Pin, OUTPUT);

digitalWrite(segApin, HIGH);
digitalWrite(segBpin, HIGH);
digitalWrite(segCpin, HIGH);
digitalWrite(segDpin, HIGH);
digitalWrite(segEpin, HIGH);
digitalWrite(segFpin, HIGH);
digitalWrite(segGpin, HIGH);
digitalWrite(dig1pin, LOW);
digitalWrite(dig2pin, LOW);
digitalWrite(dig3pin, LOW);
digitalWrite(dig4pin, LOW);
}

void loop() {
  
digitalWrite(dig1pin, HIGH);

digitalWrite(segApin, LOW);
delay(1000);
digitalWrite(segApin, HIGH);
delay(1000);
digitalWrite(segBpin, LOW);
delay(1000);
digitalWrite(segBpin, HIGH);
delay(1000);
digitalWrite(segCpin, LOW);
delay(1000);
digitalWrite(segCpin, HIGH);
delay(1000);
digitalWrite(segDpin, LOW);
delay(1000);
digitalWrite(segDpin, HIGH);
delay(1000);
digitalWrite(segEpin, LOW);
delay(1000);
digitalWrite(segEpin, HIGH);
delay(1000);
digitalWrite(segFpin, LOW);
delay(1000);
digitalWrite(segFpin, HIGH);
delay(1000);
digitalWrite(segGpin, LOW);
delay(1000);
digitalWrite(segGpin, HIGH);
delay(1000);

delay(5);
/*digitalWrite(segApin, LOW);
Serial.println("A - LOW");
digitalWrite(segBpin, LOW);
digitalWrite(segCpin, LOW);
digitalWrite(segDpin, LOW);
digitalWrite(segEpin, LOW);
digitalWrite(segFpin, LOW);
digitalWrite(segGpin, LOW);
delay(1000);
*/
}

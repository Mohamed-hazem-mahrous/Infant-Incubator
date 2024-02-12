#include <DHT.h> 
#include <Wire.h>
#define DHTTYPE DHT11  

//////////////////////////////////////////////////   PINS   //////////////////////////////////////////////////

// buzzer
const int buzzerPin = 13;
// relay
const int relayPin = 9;
// dht
const int DHTPIN = A1;
// pulse
int PulseSensorPurplePin = 0;       
int LED13 = 13; 
int Signal;     
int Threshold =550; 
// color
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int redPW = 0;
int greenPW = 0;
int bluePW = 0;

DHT dht(DHTPIN, DHTTYPE);
//////////////////////////////////////////////////   SETUP   //////////////////////////////////////////////////

void setup() {

// color
  pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	digitalWrite(S0,HIGH);
	digitalWrite(S1,LOW);
	pinMode(sensorOut, INPUT);

// pulse
  pinMode(LED13,OUTPUT);

// relay 
  pinMode(relayPin, OUTPUT);

// buzzer
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  dht.begin();
}

//////////////////////////////////////////////////   LOOP   //////////////////////////////////////////////////

void loop()
{
// dht
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

// relay and buzzer
if (t <= 37) {
 digitalWrite(relayPin, LOW);
  tone(buzzerPin, 2000, 50);
 }
else {
 digitalWrite(relayPin, HIGH);
 }

// pulse
Signal = analogRead(PulseSensorPurplePin);
if(Signal > Threshold){       
digitalWrite(LED13,HIGH);
} else {
 digitalWrite(LED13,LOW);
}

// color
	redPW = getRedPW();
	greenPW = getGreenPW();
	bluePW = getBluePW();

// outputs
  Serial.print("Heart Rate:");
  Serial.print(Signal);     
  Serial.print(',');
  Serial.print("Temperature:");
  Serial.print(t);
  Serial.print(" *C");
  Serial.print(',');
  Serial.print("Humidity:");
  Serial.print(h);
  Serial.print(" %");
  Serial.print(',');
  Serial.print("Red PW:");
	Serial.print(redPW);
  Serial.print(',');
	Serial.print("Green PW:");
	Serial.print(greenPW);
  Serial.print(',');
	Serial.print("Blue PW:");
	Serial.println(bluePW);
  if (redPW < bluePW && greenPW < bluePW && redPW < 130 && greenPW < 130 ) {
		Serial.print(',');
    Serial.print("This is yellow");
      tone(buzzerPin, 50, 50);
    }
  Serial.println();


delay(10);
}

//////////////////////////////////////////////////   COLOR SENSOR FUNCTIONS   //////////////////////////////////////////////////

int getRedPW() {
	int PW;
	digitalWrite(S2,LOW);
	digitalWrite(S3,LOW);
	PW = pulseIn(sensorOut, LOW);
	return PW;
}

int getGreenPW() {
	int PW;
	digitalWrite(S2,HIGH);
	digitalWrite(S3,HIGH);
	PW = pulseIn(sensorOut, LOW);
	return PW;
}

int getBluePW() {
	int PW;
	digitalWrite(S2,LOW);
	digitalWrite(S3,HIGH);
	PW = pulseIn(sensorOut, LOW);
	return PW;
}
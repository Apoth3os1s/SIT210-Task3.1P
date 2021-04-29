//This includes the library which has the code to calculate and measure the temperature and humididty
#include "Adafruit_DHT.h"
//This deifines which pin the data will come from, from the DHT22 temp and humidity sensor
#define DHTPIN 2
//Defines which type of sensor i will be using
#define DHTTYPE DHT22		// DHT 22 (AM2302)


DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
	dht.begin();
}

void loop() 
{
// Waits 30 secounds before runnning the code again
	delay(30000);

// Reads temperature as Celsius
	float temp = dht.getTempCelcius();
//Uploads the value to the particle
    Particle.publish("temp", String(temp), PRIVATE);
}


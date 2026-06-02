#include <SoftwareSerial.h>
#include <SimpleDHT.h>

#define DHTPIN 2
#define RX_PIN 3
#define TX_PIN 1

SoftwareSerial mySerial(RX_PIN, TX_PIN);
SimpleDHT11 dht11;

void setup() {
  mySerial.begin(4800);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;

  mySerial.print("Reading sensor... \n");

  int err = dht11.read(DHTPIN, &temperature, &humidity, NULL);
  if (err != SimpleDHTErrSuccess) {
    mySerial.print("Error DHT: ");
    mySerial.println(err);
    delay(3000);
    return;
  }

  mySerial.print("Humidity: ");
  mySerial.print((int)humidity);
  mySerial.print("% | Temp: ");
  mySerial.print((int)temperature);
  mySerial.println(" C");

  delay(3000);
}



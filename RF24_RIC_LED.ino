#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   9
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL; // Definisce il canale di trasmissione
RF24 radio(CE_PIN, CSN_PIN); // Stabilisce la comunicazione
int ledpin1 = 3;
int ledpin2 = 4;
int ledpin3 = 5;
int ledpin4 = 6;
int ledpin5 = 7;
int ledpin6 = 8;
int datatoreceive[5];
void setup()  
{
  delay(1000);
  Serial.begin(9600);  
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  pinMode (ledpin1, OUTPUT);
  pinMode (ledpin2, OUTPUT);
  pinMode (ledpin3, OUTPUT);
  pinMode (ledpin4, OUTPUT);
  pinMode (ledpin5, OUTPUT);
  pinMode (ledpin6, OUTPUT);
  digitalWrite (ledpin1,LOW);
  digitalWrite (ledpin2,LOW);
  digitalWrite (ledpin3,LOW);
  digitalWrite (ledpin4,LOW);
  digitalWrite (ledpin5,LOW);
  digitalWrite (ledpin6,LOW);
}
void loop()  
{
  if ( radio.available() ){
    radio.read( datatoreceive, sizeof(datatoreceive) );
    Serial.println("datatoreceive :");
    Serial.println(datatoreceive[0]);
   
    if ((datatoreceive[0])==1) // avanti
    {
      digitalWrite (ledpin1,HIGH);
      Serial.println("datatoreceive :");
      Serial.println(datatoreceive[0]);
      delay (100);
      digitalWrite (ledpin1,LOW);
    
    }
    else
    {
      digitalWrite (ledpin1,LOW);
    }
    if ((datatoreceive[0])==2) // avanti piano
    {
      digitalWrite (ledpin2,HIGH);
      Serial.println("datatoreceive :");
      Serial.println(datatoreceive[0]);
      delay (100);
      digitalWrite (ledpin2,LOW);      
    }
    else
    {
      digitalWrite (ledpin2,LOW);
    }
    if ((datatoreceive[0])==3) // destra
    {
      digitalWrite (ledpin3,HIGH);
      Serial.println("datatoreceive :");
      Serial.println(datatoreceive[0]);
      delay (100);
      digitalWrite (ledpin3,LOW);
    }
    else
    {
      digitalWrite (ledpin3,LOW);
    }
    if ((datatoreceive[0])==4) // sinistra
    {
      digitalWrite (ledpin4,HIGH);
      Serial.println("datatoreceive :");
      Serial.println(datatoreceive[0]);
      delay (100);
      digitalWrite (ledpin4,LOW);
    }
    else
    {
      digitalWrite (ledpin4,LOW);
    }
    if ((datatoreceive[0])==5) // indietro
    {
      digitalWrite (ledpin5,HIGH);
      Serial.println("datatoreceive :");
      Serial.println(datatoreceive[0]);
      delay (100);
      digitalWrite (ledpin5,LOW);
    }
    else
    {
      digitalWrite (ledpin5,LOW);
    }
    if ((datatoreceive[0])==6) // abilita disabilita comandi a macchina
    {
      digitalWrite (ledpin6,HIGH);
      Serial.println("datatoreceive :");
      Serial.println(datatoreceive[0]);
      delay (100);
      digitalWrite (ledpin6,LOW);
    }
    else
    {
      digitalWrite (ledpin6,LOW);
    }    
  }
}

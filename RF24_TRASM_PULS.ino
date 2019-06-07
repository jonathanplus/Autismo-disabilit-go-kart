#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   9
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL; // Definisce il canale di trasmissione
RF24 radio(CE_PIN, CSN_PIN); // Stabilisce la comunicazione
int button0=A0;
int button1=A1;
int button2=A2;
int button3=A3;
int button4=A4;
int button5=A5;
int buttonstate0;
int buttonstate1;
int buttonstate2;
int buttonstate3;
int buttonstate4;
int buttonstate5;
int datatosend[5];
int ledPin1=3; // segnale radio on
int ledPin2=4; // telecomando acceso

void setup()  
{
  Serial.begin(9600);
  pinMode (button0, INPUT_PULLUP);
  pinMode (button1, INPUT_PULLUP);
  pinMode (button2, INPUT_PULLUP);
  pinMode (button3, INPUT_PULLUP);
  pinMode (button4, INPUT_PULLUP);
  pinMode (button5, INPUT_PULLUP);    
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode (ledPin1, OUTPUT);
  pinMode (ledPin2, OUTPUT);
  digitalWrite(ledPin2, HIGH);  
}
void loop()  
{
  buttonstate0 = digitalRead (button0);
  buttonstate1 = digitalRead (button1);
  buttonstate2 = digitalRead (button2);
  buttonstate3 = digitalRead (button3);
  buttonstate4 = digitalRead (button4);
  buttonstate5 = digitalRead (button5);
  if (buttonstate0 == LOW && buttonstate1 == HIGH && buttonstate2 == HIGH && buttonstate3 == HIGH && buttonstate4 == HIGH && buttonstate5 == HIGH) // avanti
  {
    datatosend[0] = 1;
    Serial.println("buttonState0 :");
    digitalWrite(ledPin1, HIGH);
    radio.write (datatosend, sizeof(datatosend)) ;
  }else{
    digitalWrite(ledPin1, LOW);
  }
  if (buttonstate1 == LOW && buttonstate0 == HIGH && buttonstate2 == HIGH && buttonstate3 == HIGH && buttonstate4 == HIGH && buttonstate5 == HIGH) // avanti piano
  {
    datatosend[0] = 2;
    Serial.println("buttonState1 :");
    digitalWrite(ledPin1, HIGH);  
    radio.write (datatosend, sizeof(datatosend)) ;
  }else{
      digitalWrite(ledPin1, LOW);
    }
  if (buttonstate2 == LOW && buttonstate1 == HIGH && buttonstate0 == HIGH && buttonstate3 == HIGH && buttonstate4 == HIGH && buttonstate5 == HIGH) // destra
  {
    datatosend[0] = 3;
    Serial.println("buttonState2 :");
    digitalWrite(ledPin1, HIGH);
    radio.write (datatosend, sizeof(datatosend)) ;
  }else{
    digitalWrite(ledPin1, LOW);
    }
  if (buttonstate3 == LOW && buttonstate1 == HIGH && buttonstate2 == HIGH && buttonstate0 == HIGH && buttonstate4 == HIGH && buttonstate5 == HIGH) // sinistra
  {
    datatosend[0] = 4;
    Serial.println("buttonState3 :");
    digitalWrite(ledPin1, HIGH);
    radio.write (datatosend, sizeof(datatosend)) ;
  }else{
    digitalWrite(ledPin1, LOW);
    }
  if (buttonstate4 == LOW && buttonstate1 == HIGH && buttonstate2 == HIGH && buttonstate3 == HIGH && buttonstate0 == HIGH && buttonstate5 == HIGH) // indietro
  {
    datatosend[0] = 5;
    Serial.println("buttonState4 :");
    digitalWrite(ledPin1, HIGH);
    radio.write (datatosend, sizeof(datatosend)) ;
  }else{
    digitalWrite(ledPin1, LOW);
    }  
  if (buttonstate5 == LOW && buttonstate1 == HIGH && buttonstate2 == HIGH && buttonstate3 == HIGH && buttonstate4 == HIGH && buttonstate0 == HIGH) // comandi a macchina abilitati e disabilitati
  {
    datatosend[0] = 6;
    Serial.println("buttonState5 :");
    digitalWrite(ledPin1, HIGH);
    radio.write (datatosend, sizeof(datatosend)) ;
 }else{
    digitalWrite(ledPin1, LOW);
  }

}

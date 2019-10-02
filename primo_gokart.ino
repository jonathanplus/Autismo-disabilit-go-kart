int canale[6] = {A0,A1,A2,A3,A4,A5}; // segnali ricevitore arduino uno r3
int statoCanale[6]; // lettura stato segnali ricevitore arduino uno r3
int rele[9] = {3,4,5,6,7,8,9,10,11}; // comandi rele
int pulsanteKart[3] = {A6,A7,A8}; // pulsanti go kart
int pulsanteStato[3]; // lettura pulsanti go kart
int telecomando = HIGH; // comandi da ricevitore
int manuale = LOW; // comandi da go kart

void setup(){
  Serial.begin(9600);
  
  for ( int i = 0;i < 6; i++){ // segnali ricevitore arduino uno r3 input
   pinMode(canale[i], INPUT_PULLUP); 
    }
  for ( int i = 0;i < 6; i++){ // lettura stato segnali ricevitore arduino uno r3 = 0
    statoCanale[i] = 0;
    }
  for ( int i = 0;i < 9; i++){ // comandi rele output
   pinMode(rele[i], OUTPUT); 
    }
  for ( int i = 0;i < 9; i++){ // comandi rele = high
    digitalWrite(rele[i], HIGH); 
    }
  for ( int i = 0;i < 3; i++){ // lettura pulsanti go kart input
   pinMode(pulsanteKart[i], INPUT_PULLUP); 
    }
  for ( int i = 0;i < 3; i++){ // lettura pulsanti go kart = 0 FORSE UN PROBLEMA
    pulsanteStato[i] = 1; 
    } 
  }
void loop(){
  statoCanale[0] = digitalRead(canale[0]);
  Serial.print("(statoCanale[0] :");
  Serial.println(statoCanale[0]);
  statoCanale[1] = digitalRead(canale[1]);
  Serial.print("(statoCanale[1] :");
  Serial.println(statoCanale[1]);
  statoCanale[2] = digitalRead(canale[2]);
  Serial.print("(statoCanale[2] :");
  Serial.println(statoCanale[2]);
  statoCanale[3] = digitalRead(canale[3]);
  Serial.print("(statoCanale[3] :");
  Serial.println(statoCanale[3]);
  statoCanale[4] = digitalRead(canale[4]);
  Serial.print("(statoCanale[4] :");
  Serial.println(statoCanale[4]);
  statoCanale[5] = digitalRead(canale[5]);
  Serial.print("(statoCanale[5] :");
  Serial.println(statoCanale[5]);
  pulsanteStato[0] = digitalRead(pulsanteKart[0]);
  Serial.print("(pulsanteStato[0] :");
  Serial.println(pulsanteStato[0]);
  pulsanteStato[1] = digitalRead(pulsanteKart[1]);
  Serial.print("(pulsanteStato[1] :");
  Serial.println(pulsanteStato[1]);
  pulsanteStato[2] = digitalRead(pulsanteKart[2]);
  Serial.print("(pulsanteStato[2] :");
  Serial.println(pulsanteStato[2]);  

  if (statoCanale[5] == LOW){ // abilita e disabilita i comandi go kart con inizio telecomando
    telecomando = HIGH - telecomando;
    manuale = HIGH - manuale;
    Serial.print("telecomando :");
    Serial.println(telecomando);
    Serial.print("manuale :");
    Serial.println(manuale);
    delay (3000);
    }
  if (telecomando == HIGH){ 
    if (statoCanale[0] == LOW){ // avanti
      Serial.println("AVANTI");
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);
      digitalWrite(rele[8], HIGH);      
      digitalWrite(rele[0], LOW);
      digitalWrite(rele[1], LOW);
      digitalWrite(rele[2], LOW);
      digitalWrite(rele[3], LOW);      
      }
    if (statoCanale[1] == LOW ){  // avanti piano
      Serial.println("AVANTI PIANO");
      digitalWrite(rele[1], HIGH);
      digitalWrite(rele[2], HIGH);     
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);
      digitalWrite(rele[0], LOW);
      digitalWrite(rele[8], LOW);
      digitalWrite(rele[3], LOW);            
    }
    if (statoCanale[2] == LOW ){  //destra
      Serial.println("DESTRA");
      digitalWrite(rele[2], HIGH);
      digitalWrite(rele[3], HIGH);
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);
      digitalWrite(rele[8], HIGH); 
      digitalWrite(rele[0], LOW);
      digitalWrite(rele[1], LOW);      
      }
    if (statoCanale[3] == LOW ){ // sinistra
      Serial.println("SINISTRA");
      digitalWrite(rele[0], HIGH);
      digitalWrite(rele[1], HIGH);
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);
      digitalWrite(rele[8], HIGH);      
      digitalWrite(rele[2], LOW);
      digitalWrite(rele[3], LOW);       
    }
    if (statoCanale[4] == LOW ){ // indietro
      Serial.println("INDIETRO");    
      digitalWrite(rele[0], HIGH);
      digitalWrite(rele[1], HIGH);
      digitalWrite(rele[2], HIGH);
      digitalWrite(rele[3], HIGH);
      digitalWrite(rele[8], HIGH);          
      digitalWrite(rele[4], LOW);
      digitalWrite(rele[5], LOW);
      digitalWrite(rele[6], LOW);
      digitalWrite(rele[7], LOW);    
    }
    if (statoCanale[0] == HIGH  && statoCanale[1] == HIGH  && statoCanale[2] == HIGH  && statoCanale[3] == HIGH  && statoCanale[4] == HIGH ){ // nessun segnale
      Serial.println("FERMO");
      digitalWrite(rele[0], HIGH);
      digitalWrite(rele[1], HIGH);
      digitalWrite(rele[2], HIGH);
      digitalWrite(rele[3], HIGH);     
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);
      digitalWrite(rele[8], HIGH);    
    }
  } 
  if (manuale == HIGH){ 
    if (pulsanteStato[0] == LOW &&  pulsanteStato[1] == HIGH &&  pulsanteStato[2] == HIGH){ // avanti
      Serial.println("AVANTI PULS");
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);      
      digitalWrite(rele[0], LOW);
      digitalWrite(rele[1], LOW);
      digitalWrite(rele[2], LOW);
      digitalWrite(rele[3], LOW);      
      }
    if (pulsanteStato[1] == LOW &&  pulsanteStato[0] == LOW &&  pulsanteStato[2] == HIGH){  //destra
      Serial.println("DESTRA PULS");
      digitalWrite(rele[2], HIGH);
      digitalWrite(rele[3], HIGH);
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH); 
      digitalWrite(rele[0], LOW);
      digitalWrite(rele[1], LOW);      
      }
    if (pulsanteStato[2] == LOW &&  pulsanteStato[1] == HIGH &&  pulsanteStato[0] == LOW){ // sinistra
      Serial.println("SINISTRA PULS");
      digitalWrite(rele[0], HIGH);
      digitalWrite(rele[1], HIGH);
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);      
      digitalWrite(rele[2], LOW);
      digitalWrite(rele[3], LOW);       
    }
    if (pulsanteStato[0] == LOW &&  pulsanteStato[1] == LOW &&  pulsanteStato[2] == LOW){ // indietro
      Serial.println("INDIETRO PULS");
      digitalWrite(rele[0], HIGH);
      digitalWrite(rele[1], HIGH);
      digitalWrite(rele[2], HIGH);
      digitalWrite(rele[3], HIGH);          
      digitalWrite(rele[4], LOW);
      digitalWrite(rele[5], LOW);
      digitalWrite(rele[6], LOW);
      digitalWrite(rele[7], LOW);    
    }
    if (pulsanteStato[0] == HIGH && pulsanteStato[1] == HIGH   && pulsanteStato[2] == HIGH){ // fermo
      Serial.println("FERMO PULS");
      digitalWrite(rele[0], HIGH);
      digitalWrite(rele[1], HIGH);
      digitalWrite(rele[2], HIGH);
      digitalWrite(rele[3], HIGH);
      digitalWrite(rele[4], HIGH);
      digitalWrite(rele[5], HIGH);
      digitalWrite(rele[6], HIGH);
      digitalWrite(rele[7], HIGH);              
      }
}
delay (30); 
}   

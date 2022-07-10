// Controle remoto
#include <IRremote.hpp>
int RECV_PIN = 4;  
float armazenavalor;  
IRrecv irrecv(RECV_PIN);  
decode_results results;  

//RECEPTOR IR
#define ligar 0xF7C03F
#define desligar 0xF740BF
#define brilhomenos 0xF7807F
#define brilhomais 0xF700FF
#define vermelho 0xF720DF
#define verde 0xF7A05F
#define azul 0xF7609F
#define branco 0xF7E01F
#define flash 0xF7D02F
#define strobe 0xF7F00F
#define smooth 0xF7E817
#define laranjamais 0xF710EF
#define laranjamenos 0xF730CF
#define verde 0xF7906F
#define azulclaro 0xF7B04F
#define azulmais 0xF750AF
#define roxo 0xF7708F
#define spotmais 0xF708F7
#define spotmenos 0xF728D7
#define spoton 0xF7A857
#define spotoff 0xF76897

//Transistor e Relé

int rele = 6;
int transistor = 9;
int brilho = 0;

void setup() {
  
  pinMode(rele, OUTPUT);
  pinMode(transistor, OUTPUT);
  
  irrecv.enableIRIn();
  Serial.begin(9600);  

}

void loop() {

  //Recebe os dados do controle remoto
  if (irrecv.decode(&results))
  {
    switch (results.value) {
      case ligar: digitalWrite(rele, HIGH); break;
      case desligar: digitalWrite(rele, LOW); break;
      case brilhomais: brilho = brilho + 20; analogWrite(transistor, brilho); break;
      case brilhomenos: brilho = brilho - 20; analogWrite(transistor, brilho); break;
      case vermelho: analogWrite(transistor, 255); break;
      case azul: analogWrite(transistor, 0); break;
      case laranjamenos: digitalWrite(13,HIGH); break;
      case laranjamais: digitalWrite(13,LOW); break;
    }
    irrecv.resume();

  }

}

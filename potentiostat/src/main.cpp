#include <Arduino.h>

//Bibliotecas ESP8266 e Firebase.
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 
//Iniciações do banco de dados Firebase.
#define FIREBASE_HOST "potentiostat-2a3f2-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyB807m67aV902ej85wE5At-4ma3JEunQvA"
#define WIFI_SSID "*****"                         //Rede do usuário
#define WIFI_PASSWORD "*****"                     //Senha do usuário

#define resposta A0
char inicia = 'n';
int tempo;

void setup() {
  // put your setup code here, to run once:
  pinMode(resposta, INPUT);

  Serial.begin(115200);                                 // Para Monitor Serial

  //Rotina pra conectar ao wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  //Serial.print("conectando");
  while (WiFi.status() != WL_CONNECTED) {
  //Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());
 
  //Iniciar Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(inicia =='s'){

    tempo = millis();                          //Tempo de execução do experimento

    float tensao = analogRead(resposta);
    Firebase.pushFloat("Tensao", tensao);      // Envia tensão para o Firebase
    float corrente = (tensao-5)/10000;         // Acha a corrente a partir da divisão entre 
    Firebase.pushFloat("Corrente", corrente);  // Envia tensão para o Firebase

    if(tempo > 10000){                          //Para o experimento após 10 segundos
      inicia = Firebase.setChar("Iniciar", 'n');
    }

  }
}
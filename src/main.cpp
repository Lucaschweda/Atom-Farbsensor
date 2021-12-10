#include <Arduino.h>

const int s0 = 8;

const int s1 = 9;

const int s2 = 12;

const int s3 = 11;

const int out = 10;

int roteLED = 2;

int grueneLED = 3;

int blaueLED = 4;

int rot = 0;

int gruen = 0;

int blau = 0;

void setup()

{

Serial.begin(9600); //Serielle Kommunikation starten

pinMode(s0, OUTPUT); //Die Kontakte des Farbsensors werden als Output oder...

pinMode(s1, OUTPUT); // (Warum als Output? Die Frequenzwerte (s0-s3) sollen im

pinMode(s2, OUTPUT); // seriellen Monitor ausgegeben werden.)

pinMode(s3, OUTPUT);

pinMode(out, INPUT); // ...Input festgelegt

pinMode(roteLED, OUTPUT); //Die LEDs werden als Output festgelegt

pinMode(grueneLED, OUTPUT);

pinMode(blaueLED, OUTPUT);

digitalWrite(s0, HIGH); //Die vier weißen LEDs am Farbsensor sollen leuchten

digitalWrite(s1, HIGH);

}
void color() //Hier werden die Werte vom Farbsensor ausgelesen und unter den

//entsprechenden Variablen gespeichert

{

digitalWrite(s2, LOW);
digitalWrite(s3, LOW);
rot = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
digitalWrite(s3, HIGH);
blau = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
digitalWrite(s2, HIGH);

gruen = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

}

void loop()

{

color();//Diese Funktion wird am Ende des Codes festgelegt (s.“void color();“)

if((rot + gruen + blau) > 45 && rot < 60 && gruen < 39 && blau < 45 && (rot - gruen) > 7){
    Serial.print("Gruen");
}

Serial.print(" Wert Rot: "); //Auf dem seriellen Monitor soll jeweils „Wert“

Serial.print(rot, DEC); //mit der entsprechenden Farbe angezeigt

Serial.print(" Wert Gruen: ");//werden und dahinter der Wert, welcher in der

Serial.print(gruen, DEC); //void color(); Funktion ausgelesen wurde.

Serial.print(" Wert Blau: ");

Serial.println(blau, DEC);








}

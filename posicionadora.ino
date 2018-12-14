#include <LiquidCrystal.h>
LiquidCrystal lcd (8, 9, 4, 5, 6, 7);
void motor();
void retorno();
int cantidad_ini=10;
int sel=0;
int cont_1 = 0;
int cont_2 = 0;
int sentido= 0;
int distancia=0;
int velocidad=600;
int base = 700; //MODIFICAR
int recorrido;
int pasos;
int conv=50;//factor de conversión de distancia a pasos
void setup() {
  Serial.begin (9600);
  lcd.begin (16, 2);
}
void loop() {
  lcd.clear ();
  while (sel==0){
  int sensor = analogRead (A0);
  int select = sensor > 635 && sensor < 645;
  int up = sensor > 95 && sensor < 105;
  int down = sensor > 250 && sensor < 260;
  int left = sensor > 400 && sensor < 415;
  int rigth = sensor <= 5;
  lcd.setCursor (0, 0);
  lcd.print ("CANTIDAD");
  lcd.setCursor (0, 1);
  lcd.print (cont_1);
    if (up){
      cont_1++;
      delay(200);

      }
    else if (down){
    cont_1--;
    delay(200);
      }
      //delay (100);
    else if (select){
      sel++;
      lcd.clear ();
      delay(200);
  }
}
  while (sel==1){
  int sensor = analogRead (A0);
  int select = sensor > 635 && sensor < 645;
  int up = sensor > 95 && sensor < 105;
  int down = sensor > 250 && sensor < 260;
  int left = sensor > 400 && sensor < 415;
  int rigth = sensor <= 5;
  lcd.setCursor (0, 0);
  lcd.print ("DISTANCIA");
  lcd.setCursor (0, 1);
  lcd.print (cont_2);
    if (up){
      delay(200);
      cont_2++;

      }
    else if (down){
      delay(200);
      cont_2--;
      }
      //delay (100);
    else if (select){
      sel++;
      lcd.clear ();
      delay(100);
    }


}
while (sel==2){
int sensor = analogRead (A0);
int select = sensor > 635 && sensor < 645;
int up = sensor > 95 && sensor < 105;
int down = sensor > 250 && sensor < 260;
int left = sensor > 400 && sensor < 415;
int rigth = sensor <= 5;
lcd.setCursor (0, 0);
lcd.print ("PROCESO...");
while (estado==0){
  retorno(1);
  int inicio=digitalRead(25);
  if (inicio=1){
    estado++;
  }
}
while (estado==1){
  cantidad=(cantidad_ini-cont_1)*conv
  recorrido=recorrido_total-
  motor(cantidad);
  delay(200);
  //servomotor
  delay(200);
  motor(recorrido)
}
}
}

void motor(int variable){
  distancia=0;
 while(distancia <= variable) {
 digitalWrite(29, HIGH);
 delayMicroseconds(velocidad); // delay define la Velocidad o tiempo entre pasos
 digitalWrite(29, LOW);
 delayMicroseconds(velocidad); // delay de X milisegundos
 digitalWrite(28, LOW);
 distancia++;
}
}
void retorno(int variable){
 distancia = 0;
 while(distancia <= variable) {
 digitalWrite(29, HIGH);
 delayMicroseconds(600); // delay define la Velocidad o tiempo entre pasos
 digitalWrite(29, LOW);
 delayMicroseconds(600); // delay de X milisegundos
 digitalWrite(28, HIGH);
 distancia = distancia+1;
}
}

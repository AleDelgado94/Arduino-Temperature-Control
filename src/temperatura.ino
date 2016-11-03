#include <LiquidCrystal.h>


int analogPin = 1;
int pwd = 6;
int subir = 9;
int bajar = 10;
float val = 0;
float val_ventilador = 0;
float error;
float temp_deseada = 0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(8,2);
  pinMode(pwd, OUTPUT);
  pinMode(subir, INPUT);
  pinMode(bajar, INPUT);
  

}

float controlador(float valor_real, float valor_deseado) {
  float error = 0;
  error = valor_real - valor_deseado;
  //Serial.print("El valor de comando error: ");
  //Serial.println(error);
  return error;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  
  
    
  val = (val*5)/1024;
  
  Serial.print("La temperatura es de: ");
  Serial.println(val * 10);



  //PULSADORES
  //Subir temperatura: digital port  9
  //Bajar temperatura: digital port 10

  if(digitalRead(subir)){
    temp_deseada++;
  }
  if(digitalRead(bajar) && temp_deseada > 0){
    temp_deseada--;
  }

  //Temperatura real
  lcd.setCursor(0,0);
  lcd.print("Tr: ");
  lcd.setCursor(3,0);
  lcd.print(val*10);



  //Temperatura deseada
  lcd.setCursor(0,1);
  lcd.print("Td: ");
  lcd.setCursor(3,1);
  lcd.print(temp_deseada);
  
  //Controlador Proporcional

  float comando = 20*controlador(val*10, temp_deseada);

  //Serial.print("El valor de comando es: ");
  //Serial.println(comando);

  if(comando > 255)
    comando = 255;
  else if(comando < 0)
    comando = 0;  

  Serial.print("El valor de comando es: ");
  Serial.println(comando);
    

  float comando_apl = 255 - comando;

   

  Serial.print("El valor de comando aplicado es: ");
  Serial.println(comando_apl);
  
  analogWrite(pwd, comando_apl);
  
  
  

}

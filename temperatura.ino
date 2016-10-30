
int analogPin = 1;
int pwd = 5;
float val = 0;
float val_ventilador = 0;
float error;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwd, OUTPUT);

}

float controlador(float valor_real) {
  float error = 0;
  float deseado = 23;
  error = valor_real - deseado;
  Serial.print("El valor de comando error: ");
  Serial.println(error);
  return error;
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
    
  val = (val*5)/1024;
  
  Serial.print("La temperatura es de: ");
  Serial.println(val * 10);

  //Controlador Proporcional

  float comando = 20*controlador(val*10);

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

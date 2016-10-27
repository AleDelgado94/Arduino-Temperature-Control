
int analogPin = 1;
float val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);

  val = (val*5)/1024;
  
  Serial.print("La temperatura es de: ");
  Serial.println(val * 10);
  

}

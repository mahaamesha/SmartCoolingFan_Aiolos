/*
 *Temperature sensor to pin A3
 
 *1,2 enable and 3,4 enable L293D to pin 9
 *Input 1 to pin 13
 *input 2 to pin 12
 *input 3 to pin 11
 *input 4 to pin 10
 
 *Supply voltage (4x3.7)V
 *Lewatkan L7805 dulu, lalu ke pin Raw
*/


//Deklarasi Variabel
float suhu = 0;
int pinTemp = 3;
int pinEn = 9;
byte speed; // range 0-255


void setup() {
  Serial.begin(9600);
  pinMode(pinTemp, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(pinEn, OUTPUT);
  
  //Menyalakan motor dengan sinyal PWM
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
}

void loop() {
  suhu = ( analogRead(pinTemp)/1024.0 )*500;  //ubah ke celcius
  delay(1000);
  Serial.print(suhu);
  Serial.println(" Celcius");
  
  //Mengatur kecepatan motor
  speed = map(suhu, 0, 100, 0, 255);
  Serial.print("speed: ");
  
  
  if ((suhu < 30) || (suhu > 80))
  {
    Serial.println("0");
    analogWrite(pinEn, 0);
  }
  else
  {
    Serial.println(speed);
    analogWrite(pinEn, speed+100);
  }
}
 

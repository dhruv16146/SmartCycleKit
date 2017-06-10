#define R1echoPin 4 // Echo Pin
#define R1trigPin 3 // Trigger Pin
long R1duration, R1distance;
unsigned int valx, valy, i, cc, ac;

void adxl()
{
  valx=0;
    for(i=0;i<100;i++)
    {
      valx += analogRead(A0);
      //delay(1)
    }
    valx = valx/100;
 //Serial.println(valx);   
 if(valx>350)
 {
  Serial.print("0");
 }
 else if(valx<300)
 {
  Serial.print("4");
 }
 
 else
 {
  Serial.print("1");
  delay(500);
  Serial.print("5");
 }
 
 
}

void R1_ultrasonic()
{
 //long R1duration, R1distance; 
 digitalWrite(R1trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(R1trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(R1trigPin, LOW);
 R1duration = pulseIn(R1echoPin, HIGH);
 R1distance = (R1duration/2) / 29.1;
 //Serial.println(R1distance);
 if(R1distance<30) // taken the distance in centimeter
 {
  Serial.print("2");
 }
 else if(R1distance>30)
 {
  Serial.print("3");
 }
} 



void setup()
{
  Serial.begin(9600);
// Initialize the IO and ISR
pinMode(R1trigPin, OUTPUT);pinMode(R1echoPin, INPUT);

}

void loop()
{
R1_ultrasonic();
delay(500);
adxl();
delay(500);
}



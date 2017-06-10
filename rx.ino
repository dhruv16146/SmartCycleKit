int Lled = 5; 
int Rled = 7;
int Sled = 6;
char buf;
void setup()
{
Serial.begin(9600);
Serial.println("Hello");
pinMode(Lled,OUTPUT);
pinMode(Rled,OUTPUT);
pinMode(Sled,OUTPUT);
digitalWrite(Lled,HIGH);//checking start
digitalWrite(Rled,HIGH);
digitalWrite(Sled,HIGH);
delay(1000);
digitalWrite(Lled,LOW);
digitalWrite(Rled,LOW);
digitalWrite(Sled,LOW);

}
void loop()
{
if (Serial.available() > 0) 
{  
buf= Serial.read();
if(buf=='0')
{
  digitalWrite(Lled,HIGH);
 //Serial.print("0");
}
else if(buf=='1')
{
  digitalWrite(Lled,LOW);
  //Serial.print("1");
}
else if(buf=='2')
{
  digitalWrite(Sled,HIGH);
}
else if(buf=='3')
{
  digitalWrite(Sled,LOW);
}
else if(buf=='4')
{
  digitalWrite(Rled,HIGH);
}
else if(buf=='5')
{
  digitalWrite(Rled,LOW);
}

}
}

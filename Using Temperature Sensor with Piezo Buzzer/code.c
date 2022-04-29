const int redled=5;
const int greenled=3;
const int orangeled=4;
const int Buzzer=2;
float temp;
void setup()
{
pinMode(A0, INPUT);
pinMode(redled, OUTPUT);
pinMode(orangeled, OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(Buzzer, OUTPUT);
Serial.begin(9600);
}
void loop()
{
temp = analogRead(A0); //Reading temprature
temp =((temp*5)/1024);
temp = (temp-0.5)*100;
Serial.print("Temperature = ");
Serial.println(temp);
if (temp <= 15) //Setting condition for red led
{
digitalWrite(redled, HIGH);
digitalWrite(orangeled, LOW);
digitalWrite(greenled, LOW);
tone(Buzzer, HIGH);
delay(1000);
}
if (temp >15 && temp <= 35)//Setting condition for orange led
{
digitalWrite(redled, LOW);
digitalWrite(orangeled, HIGH);
digitalWrite(greenled, LOW);
noTone(Buzzer);
delay(1000);
}
if (temp > 35) //Setting condition for green led
{
digitalWrite(redled, LOW);
digitalWrite(orangeled, LOW);
digitalWrite(greenled, HIGH);
noTone(Buzzer);
delay(1000);
}
}

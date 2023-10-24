#include <Servo.h>
#include <LiquidCrystal_I2C.h>
Servo myservo;
Servo servo;
// create servo object to control a servo
// twelve servo objects can be created on most boards

 
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;   // maximum sensor value


int servopos1 = 90;
int servopos2 = 90;
int east=0;
int west=0;
int sensorValue1;
int sensorValue2;
int error;
LiquidCrystal_I2C lcd(0X20,16, 2);
void setup() {
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
  servo.attach(10);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  while (millis() < 5000) {
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);
// record the maximum sensor value
 if (sensorValue1 > sensorMax) {
  sensorMax = sensorValue1;
}
// record the minimum sensor value
 if (sensorValue1 < sensorMin) {
  sensorMin = sensorValue1;
}
}
 if (sensorValue2 > sensorMax) {
  sensorMax = sensorValue2;
}
// record the minimum sensor value
 if (sensorValue2 < sensorMin) {
  sensorMin = sensorValue2;
}
  
  lcd.init();
  lcd.backlight();
}
void loop() { 
  sensorValue1 = analogRead(A0);

  sensorValue2 = analogRead(A1);

  if (sensorValue1 < 350 && sensorValue2 < 350)

  {

    while (servopos1 <= 150)

    {

      servopos1++;

      myservo.write(servopos1);

      delay(100);

    }
    while (servopos2 >= 30)

    {

      servopos2++;

      servo.write(servopos2);

      delay(100);

    }
    

  }

  error = sensorValue1 - sensorValue2;

  if (error > 15)

  {

    if (servopos1 <= 150)

    {

      servopos1++;

      myservo.write(servopos1);

    }
    if (servopos2 >= 30)

    {

      servopos2--;

      servo.write(servopos2);

    }

  }

  else if (error < -15)

  {

    if (servopos1 > 20)

    {

      servopos1--;

      myservo.write(servopos1);

    }
    if (servopos2 < 160)

    {

      servopos2++;

      servo.write(servopos2);

    }

  }
  lcd.setCursor(3, 0);
  lcd.print(myservo.read());
  lcd.setCursor(7,0);
  lcd.print("degrees");
  lcd.setCursor(3,1);
  lcd.print("from east");



  delay(100);


 // waits 15ms for the ser
}
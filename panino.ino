#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Encoder.h>

// set the LCD address to 0x20 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
LiquidCrystal_I2C lcd(0x27,20,4,8);  // Set the LCD I2C address

 const int limitSwitchA = 7;    //set limitSwitchA pin
 const int limitSwitchB = 8;    //set limitSwitchB pin
 const int encoderButton = 4;   //set Encoder Z button
 const int joyPin1 = A0;        //set joystick analog Pin 2
 const int joyPin2 = A1;        //set joystick analog Pin 1
 const int ledPinA = 5;
 const int ledPinB = 6;
 const int ledPinC = 9;
 const int ledPinD = 11;

 Encoder knobEncoder(2, 3);

 int encoderButtonValue = 0;
 int Xvalue = 0;               //stored value of Joystick X axys
 int Yvalue = 0;               //stored value of Joystick Y axys
 int motorEnable = 13;         // for reducing static coil current!


void setup() {

  pinMode (encoderButton, INPUT);
  pinMode (motorEnable, OUTPUT);
  pinMode (limitSwitchA, INPUT);
  pinMode (limitSwitchB, INPUT);
  pinMode (ledPinA, OUTPUT);
  pinMode (ledPinB, OUTPUT);
  pinMode (ledPinC, OUTPUT);
  pinMode (ledPinD, OUTPUT);


  Serial.begin(9600);      // Used to type in characters
  lcd.begin();
  //lcd.begin(20, 4);        // initialize the lcd for 20 chars 4 lines and turn on backlight
  lcd.backlight();
  lcd.setCursor(0, 0);     // writes welcome screen and waits some seconds
  lcd.print("Nerduino Slider MKI");
  delay(200);
  lcd.setCursor(0, 1);
  lcd.print("by Strelok & Navras");
  delay(200);
  lcd.setCursor(0, 2);
  lcd.print("Rotary Push Encoder");
  delay(200);
  lcd.setCursor(0, 3);
  lcd.print("version 1.0");
  delay(2000);
  lcd.clear();

}

void loop() {


/*
  Xvalue = analogRead(joyPin1);       //Reading Joystick X axis

  if(Xvalue < 10) {
    lcd.setCursor(0, 0);
    lcd.print("X: ");
    lcd.setCursor(5, 0);
    lcd.print(Xvalue);
    lcd.print("    ");
  }
  if(10 < Xvalue < 100) {
    lcd.setCursor(0, 0);
    lcd.print("X: ");
    lcd.setCursor(4, 0);
    lcd.print(Xvalue);
    lcd.print("   ");
  }
  if(100 < Xvalue < 1000) {
    lcd.setCursor(0, 0);
    lcd.print("X: ");
    lcd.setCursor(3, 0);
    lcd.print(Xvalue);
    lcd.print("    ");
  }
  if(Xvalue > 1000) {
    lcd.setCursor(0, 0);
    lcd.print("X: ");
    lcd.setCursor(3, 0);
    lcd.print(Xvalue);
    lcd.print("    ");
  }

  delay(100);                         //Delay between reading Analog Pins

  Yvalue = analogRead(joyPin2);       //Reading Joystick Y axis

  if(Yvalue < 10) {
    lcd.setCursor(0, 1);
    lcd.print("Y: ");
    lcd.setCursor(5, 1);
    lcd.print(Yvalue);
    lcd.print("    ");
  }
  if(10 < Yvalue < 100) {
    lcd.setCursor(0, 1);
    lcd.print("Y: ");
    lcd.setCursor(4, 1);
    lcd.print(Yvalue);
    lcd.print("    ");
  }
  if(100 < Yvalue < 1000) {
    lcd.setCursor(0, 1);
    lcd.print("Y: ");
    lcd.setCursor(3, 1);
    lcd.print(Yvalue);
    lcd.print("    ");
  }
  if(Xvalue > 1000) {
    lcd.setCursor(0, 1);
    lcd.print("Y: ");
    lcd.setCursor(3, 1);
    lcd.print(Yvalue);
    lcd.print("    ");
  }*/

  long encoderValue = knobEncoder.read();
  Serial.println(encoderValue);
  //if (hogiaselezionatolamodalita)
switch ((abs(encoderValue)/4)%3) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Mode: AUTO     ");
      break;
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Mode: MANUAL   ");
      encoderButtonValue = digitalRead(encoderButton);    //Reading if the encoder Z button is pressed
        if (encoderButtonValue == LOW) {         // check if the input is LOW (button pressed)

      }
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Mode: TIMELAPSE");
      break;
  }

 }

/*


// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == LOW) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}*/




#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,9,10,11,12);//rs,e,d4,d5,d6,d7
const int buttonPin = 2;// sensor input from remote 
const int c = 7;// sensor input from close sensor (green)
const int o = 8;// sensor input from open sensor (blue)
const int ff = 5;// relay 1 to turn on motor in forward condition
const int rr = 6;// relay 2 to turn on motor in revese condition
int s = 1;
void setup()
{
pinMode(c, INPUT_PULLUP);
pinMode(o, INPUT_PULLUP);
pinMode(buttonPin, INPUT_PULLUP);
pinMode(ff, OUTPUT);  //relay 1 to turn on motor in forward condition
pinMode(rr, OUTPUT);  //relay 2 to turn on motor in revesed condition   
 lcd.begin(16, 2);
      Serial.begin(9600);
      lcd.setCursor(0,0);
       lcd.print(" Kalsi Robotics ");
       lcd.setCursor(0,1);
       lcd.print("Mob.07696468978 ");
       delay(1000);
}

void loop() 
{
motor_stop();
lcd.setCursor(0,0);
lcd.print(" Kalsi Robotics ");
lcd.setCursor(0,1);
lcd.print("Mob.07696468978 ");
Serial.println("NO Input      ");
if (digitalRead(buttonPin)== LOW)
         {
          delay(500);
                    Serial.println("  ................ entering    ");
             
                    Serial.println("                 entered    ");
                    
                    if(digitalRead(o) == LOW) 
                    {
                     goclose(); 
                    }
                    else if(digitalRead(c) == LOW) 
                    {
                    goopen();  
                    }
                    else // (digitalRead(o) == LOW && digitalRead(c) == LOW) 
                    {
                     goclose(); 
                    }                    
         }
}


void goclose()
{
  start:
  while(digitalRead(c)!= LOW)
  {
       lcd.setCursor(0,0);
       lcd.print(" Kalsi Robotics ");
       lcd.setCursor(0,1);
       lcd.print("     CLOSING    ");
    Serial.println("             Closing    ");
    motor_run("FORWARD");
  if (digitalRead(buttonPin) == LOW)
         {
         delay(300);
          while(1)
          {
            motor_stop();
           lcd.setCursor(0,1);
       lcd.print("      STOP      ");
        if (digitalRead(buttonPin) == LOW)
         {
          delay(300);
          goto start;
          
          }
          
          }
         }
 
        }
  }


  
void goopen()
{
  start:
  while(digitalRead(o)!= LOW)
  {
       lcd.setCursor(0,0);
       lcd.print(" Kalsi Robotics ");
       lcd.setCursor(0,1);
       lcd.print("     OPENING    ");
    Serial.println(".............Opening    ");
    motor_run("BACKWARD");
    if (digitalRead(buttonPin) == LOW)
         {
         delay(300);
          while(1)
          {
            motor_stop();
           lcd.setCursor(0,1);
       lcd.print("      stop     ");
        if (digitalRead(buttonPin) == LOW)
         {
          delay(300);
          goto start;
          
          }
          
          }
         }
   
   
  }
}


void motor_run(String dir)
{
  if (dir == "BACKWARD")
  {
   Serial.println("backward");
    digitalWrite (rr, HIGH);
    delay(100);
    digitalWrite (ff, HIGH);
  }
  else if (dir == "FORWARD")
  {
    Serial.println("forward");
    digitalWrite (rr, LOW);
    digitalWrite (ff, HIGH);
  }
}

void motor_stop()
{
    digitalWrite (ff, LOW);
    delay(10);
    digitalWrite (rr, LOW);
}
  

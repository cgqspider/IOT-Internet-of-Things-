/*
------------------------------------------------------------------------
                            ConfusedWalrus
------------------------------------------------------------------------
*/

String voice;
#define relay1 2    //Connect relay1 to pin 2
#define relay2 3    //Connect relay2 to pin 3
void setup()
{
  Serial.begin(9600);            //Set rate for communicating with phone
  pinMode(relay1, OUTPUT);       //Set relay1 as an output
  pinMode(relay2, OUTPUT);       //Set relay2 as an output
  digitalWrite(relay1, HIGH);     //Switch relay1 off
  digitalWrite(relay2, HIGH);     //Swtich relay2 off
  pinMode(13,OUTPUT);
}
void loop()
{
   Serial.print(" " );
  Serial.println(1);
  delay(500);
  
  while(Serial.available())    //Check if there are available bytes to read
  {
    delay(10);                 //Delay to make it stable
    char c = Serial.read();    //Conduct a serial read
    if (c == '#'){
      break;                   //Stop the loop once # is detected after a word
    }
    voice += c;                //Means voice = voice + c
  }
    if (voice.length() >0)
    {
      Serial.println(voice);
      if(voice == "*switch on"){
        switchon();
        
      }               //Initiate function switchon if voice is switch on
 else if(voice == "*jarvis please on the system" || voice=="1"){
          switchon();
      }  

        else if(voice == "*jarvis please of the system"){
        switchoff();
      } 
      
      else if(voice == "*switch off" || voice=="0"){
        switchoff();
      }               //Initiate function switchoff if voice is switch off
      else if(voice == "*lamp on"){   
//You can replace 'lamp on' with anything you want...same applies to others
        digitalWrite(relay1, LOW);
      }
      else if(voice == "*lamp off"){
        digitalWrite(relay1, HIGH);
      }
      else if(voice == "*kettle on"){
        digitalWrite(relay2, LOW);
      }
      else if(voice == "*kettle off"){
        digitalWrite(relay2, HIGH);
      }
      voice="";
    }
}
void switchon()               //Function for turning on relays
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}
void switchoff()              //Function for turning on relays
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
}

/*

You can add any function you want depending on how many devices you have hooked up.
For example you could have a function called 'cinema' which would dim the lights and
turn the TV on. You can have as many as you have pins on your arduino.
For my relay 'LOW' turns off and 'HIGH' turns on
The outline to follow is this:
   
   void ......()
   {
     digitalWrite(...., LOW/HIGH);
     digitalWrite(...., LOW/HIGH);
   }
   
*/

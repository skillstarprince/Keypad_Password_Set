#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char pass[] = "0#00";
char key1;
char key2;
char key3;
char key4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}  };

byte rowPins[ROWS] =  {11,10,9,8};//connect to the row pinouts of the keypad
byte colPins[COLS] =  {4,5,6,7};//connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   Serial.begin(9600);
   pinMode(13,OUTPUT);
}  
void loop(){
  char key = keypad.getKey();
  
   if (key){
   Serial.println(key);
  // key1 = keypad.waitForKey();
   if(key1==pass[0])
   {
    key2 = keypad.waitForKey();
    if(key2==pass[1])
     {
      key3 = keypad.waitForKey();
      if(key3==pass[2])
       {
        key4 = keypad.waitForKey();
        if(key4==pass[3])
          {
           digitalWrite(13,HIGH);
           delay(1000);
        }
       }
     }
   }
 }
       else
    {
     digitalWrite(13,LOW);
     delay(1000); 
  }
} 

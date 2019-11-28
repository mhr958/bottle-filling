#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int pulse=650;
//#include <Stepper.h>
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  10;      // the number of the LED pin
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
/*void stepper(bool direction , int steps)
{
  for(int i=0; i<steps ; i++)
  {
  digitalWrite(11,direction);
  digitalWrite(9,1);
  delayMicroseconds(pulse);
  digitalWrite(9,0);
  delayMicroseconds(pulse);
  }
}*/
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//const int stepsPerRevolution = 200; 
//Stepper myStepper(stepsPerRevolution, 8,9, 10, 11);
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("Hello!");
  delay(2000);
  lcd.clear();
  lcd.print("Enter an integar");
  //lcd.print("initialozing...");
  delay(2000);
  Serial.begin(9600);
  //myStepper.setSpeed(100);
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}
int flag=0;
int p=0;
int m=0;
int n;
int i=0;
void loop() {
//  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print("no.of bottle ");
  char key = keypad.getKey();
  
  if (key){
    n=int(key)-48;
    lcd.clear();
    lcd.print("bottle ");
    lcd.print(n);
    //Serial.println(key);
    //Serial.print("\n");
    //Serial.print(n);
    p++;
  }
  if(n<5){
  if (p>=1){
  /*myStepper.step(-stepsPerRevolution); 
  delay(5000);*/
  lcd.clear();
  lcd.print("Initializing....");
  buttonState = digitalRead(buttonPin);
  if(buttonState==LOW)
  {
         digitalWrite(11,LOW);
         int U; 
         for(U=0;U<800;U++)
         {
             digitalWrite(9,HIGH);
             delayMicroseconds(pulse);
             digitalWrite(9,LOW);
             delayMicroseconds(pulse);
         }
         /*stepper(0,800);//// stepper(direction 1 or 0, steps number)
         delay(2000);*/
  }
  if (buttonState == HIGH) {
    //Serial.print("LED IS ON");
    digitalWrite(ledPin, HIGH);
    delay(1000);
    while(i<n)
    {
       //lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("no.of bottle ");
       lcd.print(i+1);
       m=m+1;
       if(m>0){
           digitalWrite(13,HIGH);
           Serial.print(m);
           delay(1500);
           digitalWrite(13,LOW);
           m=0;
           digitalWrite(11,HIGH);
           float x;
           //int A=3;
           //int b=50;
           for(x=0;x<800;x++){
           digitalWrite(9,HIGH);
           delayMicroseconds(pulse);
           digitalWrite(9,LOW);
           delayMicroseconds(pulse);
           /*stepper(1,800);//// stepper(direction 1 or 0, steps number)
           delay(2000);*/
           }
           delay(1000);
       }
       //Serial.print("no.of bottle ");
       //Serial.print(i);
       i++;
      // delay(4000);
       if(i== n)
       {
         // goto End;
          lcd.clear();
          lcd.print("task complete");
          lcd.setCursor(1,1);
          lcd.print("thank you");
          delay(20000);
       }
    
    }
  } 
  else {
                              // turn LED off:
    //Serial.print("LED IS OFF");
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  }
  }
  else {
    lcd.clear();
    lcd.print("INVALID");
  }
}
  /*End:
    lcd.clear();
    lcd.print("task complete");
    lcd.setCursor(1,1);
    lcd.print("thank you");
    delay(20000);*/

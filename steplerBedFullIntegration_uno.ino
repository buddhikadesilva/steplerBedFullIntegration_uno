#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
//byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the kpd
//byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the kpd
byte rowPins[ROWS] = {9,8,7,6}; //Rows 0 to 3
byte colPins[COLS]= {5,4,3,2}; //Columns 0 to 3

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;
String msg;

int dirPin = 53; // nozzle R
int stepPin = 52; // nozzle R
int stepsPerRevolution = 5500;
int sspeed = 900;

int dirPinT = 48; //tap2 R
int stepPinT = 49; //tap2 R
int stepsPerRevolutionT = 2100;
int sspeedT = 450;

int dirPinT2 = 50; //12 tap1 R
int stepPinT2 = 51; //13 tap1 R
int stepsPerRevolutionT2 = 2100;
int sspeedT2 = 450;
//800 for full cycle

int nRelay1 = 44; // R
int nRelay2 = 43; // R


int nLswitch = 46; //S up R
int nRswitch = 47; //S down R


int dirPinL = 22; // nozzle L
int stepPinL = 23; // nozzle L
int stepsPerRevolutionL = 5500;
int sspeedL = 900;

int dirPinTL = 26; //tap2 L
int stepPinTL = 27; //tap2 L
int stepsPerRevolutionTL = 2100;
int sspeedTL = 450;

int dirPinT2L = 24; //12 tap1 L
int stepPinT2L = 25; //13 tap1 L
int stepsPerRevolutionT2L = 2100;
int sspeedT2L = 450;
//800 for full cycle

int nRelay1L = 30; // L
int nRelay2L = 31; // L


int nLswitchL = 28; //S up L
int nRswitchL = 29; //S down L

boolean start = false;
boolean endm = false;

boolean start1 = false;
boolean endm1 = false;
boolean endm2 = false;
boolean StepEndm1 = false;
boolean StepEndm2 = false;

char Incoming_value = 0; //Variable for storing Incoming_value


boolean x = true;
void setup() {
  Serial.begin(9600);

    loopCount = 0;
    startTime = millis();
    msg = "";
    
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  pinMode(stepPinT, OUTPUT);
  pinMode(dirPinT, OUTPUT);
  //
  pinMode(stepPinT2, OUTPUT);
  pinMode(dirPinT2, OUTPUT);
  // Set the spinning direction CW/CCW:
  digitalWrite(dirPin, LOW);
  digitalWrite(dirPinT, LOW);
  digitalWrite(dirPinT2, LOW);
  //high -> forward

  //from nozzle solo
  pinMode(nRelay1, OUTPUT);
  pinMode(nRelay2, OUTPUT);
  pinMode(nLswitch, INPUT);
  pinMode(nRswitch, INPUT);

  digitalWrite(nRelay1, HIGH);
  digitalWrite(nRelay2, HIGH);


    pinMode(stepPinL, OUTPUT);
  pinMode(dirPinL, OUTPUT);

  pinMode(stepPinTL, OUTPUT);
  pinMode(dirPinTL, OUTPUT);
  //
  pinMode(stepPinT2L, OUTPUT);
  pinMode(dirPinT2L, OUTPUT);
  // Set the spinning direction CW/CCW:
  digitalWrite(dirPinL, LOW);
  digitalWrite(dirPinTL, LOW);
  digitalWrite(dirPinT2L, LOW);
  //high -> forward

  //from nozzle solo
  pinMode(nRelay1L, OUTPUT);
  pinMode(nRelay2L, OUTPUT);
  pinMode(nLswitchL, INPUT);
  pinMode(nRswitchL, INPUT);

  digitalWrite(nRelay1L, HIGH);
  digitalWrite(nRelay2L, HIGH);
}
void loop() {

 loopCount++;
    if ( (millis()-startTime)>5000 ) {
        Serial.print("Average loops per second = ");
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                    checkp(i);



                    
                break;
                    case HOLD:
                    msg = " HOLD.";
                    //checkp(i);
                break;
                    case RELEASED:
                    msg = " RELEASED.";
                    checkh(i);
                break;
                    case IDLE:
                    msg = " IDLE.";
                }
                Serial.print("Key ");
                Serial.print(kpd.key[i].kchar);
                Serial.println(msg);
            }
        }
    }















  ////////////////////////////////////////////////////////////////////
  // These four lines result in 1 step:
  if (Serial.available() > 0)
  {
    Incoming_value = Serial.read(); //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value); //Print Value of Incoming_value in Serial monitor
    Serial.print("\n"); //New line
     if (Incoming_value == '2') {
       stepper(stepPin, dirPin, 0, sspeed, 5500); // p o
      }
 if (Incoming_value == '3') {
   stepper(stepPin, dirPin, 1, sspeed, 5500); // p o
  }

   if (Incoming_value == '7') {

   n(1);
  delay(1000);
    n(3);
  }

   if (Incoming_value == '8') {
   //stepper(stepPin, dirPin, 1, sspeed, 200); // p o
    n(2);
   delay(1000);
     n(3);
  }


     if (Incoming_value == '4') {
   //stepper(stepPin, dirPin, 1, sspeed, 200); // p o
     stepper(stepPinT, dirPinT, 0, sspeedT, 100);
  }

     if (Incoming_value == '5') {
   //stepper(stepPin, dirPin, 1, sspeed, 200); // p o
    stepper(stepPinT, dirPinT, 1, sspeedT, 100);
  }





     
    if (Incoming_value == '1') {
    //  delay(5000);
core();
    }
  }
}

void stepper(int stepPin, int dirPin, boolean dir, int sspeed, int stepsPerRevolution) { //dir true ->forward
  digitalWrite(dirPin, dir);
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(sspeed);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(sspeed);
  }
  delay(1000);

}


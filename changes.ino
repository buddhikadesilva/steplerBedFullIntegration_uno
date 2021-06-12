void newNozzleUp(){
  //Serial.println("started piston - open");
          stepper(stepPin, dirPin, 1, sspeed, stepsPerRevolution); // p o
       //   Serial.println(" piston - opened");
          delay(2000);
  }

  void newNozzleUpNoDelay(){
  //Serial.println("started piston - open");
          stepper(stepPin, dirPin, 1, sspeed, stepsPerRevolution); // p o
       //   Serial.println(" piston - opened");
        //  delay(2000);
  }

void newPistonBack(){
 //Serial.println("visited nozzle Dowan Area");
          if (!digitalRead(nLswitch)) {
            start1 = true;
            Serial.println(" piston back triggered");
          }

          while (start1) {
            Serial.println("looking for forward sensor..");
            n(1);

            if (!digitalRead(nRswitch))  {
              Serial.println("forward sensor Found..");
              n(3);
              start1 = false;
             // endm1 = true;
            }


          }
  }

  void newNozzleDown(){
      // Serial.println("Piston going to close");
          delay(2000);
          stepper(stepPin, dirPin, 0, sspeed, stepsPerRevolution); //p c
      //    Serial.println("Piston closed");
          delay(2000);
  }

    void newNozzleDownNoDelay(){
      // Serial.println("Piston going to close");
         // delay(2000);
          stepper(stepPin, dirPin, 0, sspeed, stepsPerRevolution); //p c
      //    Serial.println("Piston closed");
         // delay(2000);
  }

  void newPistonForward(){
            if (!digitalRead(nRswitch)) { //nL up
            start = true;
            Serial.println(" nozzle sensor forward triggered");
          }

          while (start) {
            Serial.println("looking for back sensor..");
            n(2);

            if (!digitalRead(nLswitch)) { //nR down
              Serial.println("Found back sensor..");
              n(3);
              start = false;
             // endm = true;
            }


          }
  }

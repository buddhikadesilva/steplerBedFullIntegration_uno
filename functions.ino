void n(int dir,int nRelay1,int nRelay2) {
//  count++;
  if (dir == 1) {
    digitalWrite(nRelay1, HIGH);// turn relay 1 ON
    digitalWrite(nRelay2, LOW);// turn relay 2 OFF
    Serial.println("Rotating in CCW");
  }

  if (dir == 2) {
    digitalWrite(nRelay1, LOW);// turn relay 1 ON
    digitalWrite(nRelay2, HIGH);// turn relay 2 OFF
    Serial.println("Rotating in CW");
  }

  if (dir == 3) {
    // count--;
    digitalWrite(nRelay1, HIGH);// turn relay 1 ON
    digitalWrite(nRelay2, HIGH);// turn relay 2 OFF
    Serial.println("stop");
  }

}

void checkp(int i){
        if(kpd.key[i].kchar=='1'){
                 //      digitalWrite(34, LOW);
                 //     digitalWrite(35, LOW);
                     //   stepper(stepPinTap1, dirPinTap1, 0, sspeed, 100);
                      x=true;
                     core();
                      }
                            if(kpd.key[i].kchar=='2'){
//                              x=true;
//                              core();
                  //     digitalWrite(24, LOW);
                  //    digitalWrite(25, LOW);
                    //    stepper(stepPinTap1, dirPinTap1, 1, sspeed, 100);
                      }
                            if(kpd.key[i].kchar=='3'){
                     //  digitalWrite(26, LOW);
                    //  digitalWrite(27, LOW);
                    //  stepper(stepPinPiston, dirPinPiston, 0, sspeed, 9800);
                      }
                            if(kpd.key[i].kchar=='4'){
                      // digitalWrite(28, LOW);
                     // digitalWrite(29, LOW);
                     // stepper(stepPinPiston, dirPinPiston, 1, sspeed, 9800);
                      }
                            if(kpd.key[i].kchar=='5'){
                              refresh();
                     ///  digitalWrite(30, LOW);
                    //  digitalWrite(31, LOW);
                     //  stepper(stepPinTap1, dirPinTap1, 0, sspeed, 100);
                      }
                            if(kpd.key[i].kchar=='6'){
                              while(1){
                                newNozzleUpNoDelay(stepPin,dirPin,sspeed,stepsPerRevolution);//newNozzleUpNoDelay(int stepPin,int dirPin, int sspeed,int stepsPerRevolution){
                                delay(1000);
                                newNozzleDownNoDelay(stepPin,dirPin,sspeed,stepsPerRevolution); //newNozzleUpNoDelay(int stepPin,int dirPin, int sspeed,int stepsPerRevolution){
                                delay(2000);
                                }
                    //   digitalWrite(32, LOW);
                    ////  digitalWrite(33, LOW);
                     //  stepper(stepPinTap1, dirPinTap1, 1, sspeed, 100);
                      }

  
  }


void checkh(int i){
        if(kpd.key[i].kchar=='1'){
                     //  digitalWrite(34, HIGH);
                     // digitalWrite(35, HIGH);
             //          stepper(stepPin, dirPin, 0, sspeed, 5);
                      }
                            if(kpd.key[i].kchar=='2'){
                     //  digitalWrite(24, HIGH);
                     // digitalWrite(25, HIGH);
//                       stepper(stepPin, dirPin, 1, sspeed, 5);
                      }
                            if(kpd.key[i].kchar=='3'){
//                       digitalWrite(26, HIGH);
//                      digitalWrite(27, HIGH);
                      
                      }
                            if(kpd.key[i].kchar=='4'){
//                       digitalWrite(28, HIGH);
//                      digitalWrite(29, HIGH);
                      
                      }
                            if(kpd.key[i].kchar=='5'){
//                       digitalWrite(30, HIGH);
//                      digitalWrite(31, HIGH);
                      
                      }
                            if(kpd.key[i].kchar=='6'){
//                       digitalWrite(32, HIGH);
//                      digitalWrite(33, HIGH);
                      
                      }

  
  }

void core(int machine,int nozzleEnb, int tapEnb,int tap2Enb, int stepPinT,int dirPinT,int sspeedT,int stepsPerRevolutionT,int stepPinT2,int dirPinT2,int sspeedT2,int stepsPerRevolutionT2,int nLswitch,int nRswitch,int nRelay1,int nRelay2,int stepPin,int dirPin,int sspeed,int stepsPerRevolution){
        if (x) {
        if (StepEndm1 == false) {
         // Serial.println("started tap1 open");
          stepper(stepPinT, dirPinT, 0, sspeedT, stepsPerRevolutionT,tapEnb); //t o///////////////1
      //    Serial.println(" tap1 - opened");
          delay(100);

          //Serial.println("started piston - open");
newPistonForward(nLswitch,nRswitch,nRelay1,nRelay2);/////////////////////////////////////////////////////////////////////////2 //newPistonForward(int nLswitch,int nRswitch)
//Serial.println(" piston - opened");
//          Serial.println("started piston - open");
//          stepper(stepPin, dirPin, 1, sspeed, stepsPerRevolution); // p o
//          Serial.println(" piston - opened");
          delay(100);

          //Serial.println(" tap1 - start to close");
          stepper(stepPinT, dirPinT, 1, sspeedT, stepsPerRevolutionT,tapEnb); //t c////////////////3
          //Serial.println(" tap1 - closed");
          delay(100);

          //Serial.println(" tap2 - start to open");
        //  stepper(stepPinT2, dirPinT2, 1, sspeedT2, stepsPerRevolutionT2); //t o/////////////4
        newNozzleUp(stepPin,dirPin,sspeed,stepsPerRevolution,nozzleEnb);  //newNozzleUp(int stepPin,int dirPin, int sspeed,int stepsPerRevolution){
          //Serial.println(" tap2 - open");
          delay(100);
          StepEndm1 = true;
        }
        //N o
        if (StepEndm1 == true && endm == false) {
         // Serial.println(" Nozzle going to up");
       //   newNozzleUp();//////////////////////////////////////////////////////////////////////5
//       if(machine==1){
  stepper(stepPinT2, dirPinT2, 0, sspeedT2, stepsPerRevolutionT2,tap2Enb);
////       }else{
//           stepper(stepPinT2, dirPinT2, 1, sspeedT2, stepsPerRevolutionT2,tap2Enb);
//   //    }
     
        //  Serial.println(" Nozzle upped");
          endm = true;
//          if (!digitalRead(nRswitch)) { //nL up
//            start = true;
//            Serial.println(" nozzle sensor down triggered");
//          }
//
//          while (start) {
//            Serial.println("looking for Up sensor..");
//            n(2);
//
//            if (!digitalRead(nLswitch)) { //nR down
//              Serial.println("Found Up sensor..");
//              n(3);
//              start = false;
//              endm = true;
//            }
//
//
//          }
        }
// up to this okay - nozzleup done

        if (endm == true && StepEndm2 == false) {
        //    stepper(stepPinT2, dirPinT2, 0, sspeedT2, stepsPerRevolutionT2); //t2 o///////////


            
          //Serial.println("Piston going to close");
          delay(200);

newPistonBack(nLswitch,nRswitch,nRelay1,nRelay2);/////////////newPistonBack(int nLswitch,int nRswitch,int nRelay1,int nRelay2){
          
//          stepper(stepPin, dirPin, 0, sspeed, stepsPerRevolution); //p c
        //  Serial.println("Piston closed");
          delay(100);
          StepEndm2 = true;
        }
        //N c
        if (StepEndm2 == true && endm1 == false) {
  //Serial.println("visited nozzle Dowan Area");
    //Serial.println("visited nozzle Dowan Area");
    //      newNozzleDown();///////////////////////////////////////////////////////////////////////7
//    if(machine==1){
  stepper(stepPinT2, dirPinT2, 1, sspeedT2, stepsPerRevolutionT2,tap2Enb);
//    }else{
 // stepper(stepPinT2, dirPinT2, 0, sspeedT2, stepsPerRevolutionT2,tap2Enb);
 //   }
  
          endm1 = true;
        
//          if (!digitalRead(nLswitch)) {
//            start1 = true;
//            Serial.println(" nozzle sensor Up triggered");
//          }
//
//          while (start1) {
//            Serial.println("looking for Down sensor..");
//            n(1);
//
//            if (!digitalRead(nRswitch))  {
//              Serial.println("Down sensor Found..");
//              n(3);
//              start1 = false;
//              endm1 = true;
//            }
//
//
//          }
        }
        //Serial.println("Tap2 stared to Close..");
        delay(100);
if(endm1 ==true && endm2==false){
  // stepper(stepPinT2, dirPinT2, 0, sspeedT2, stepsPerRevolutionT2); //t2 c///////////////////////////8
  newNozzleDown(stepPin,dirPin,sspeed,stepsPerRevolution,nozzleEnb);//newNozzleDown(int stepPin,int dirPin, int sspeed,int stepsPerRevolution)
        //Serial.println("Tap2 Closed.");
        endm2=true;
        x = true;
         start = false;
 endm = false;

 start1 = false;
 endm1 = false;
 endm2 = false;
 StepEndm1 = false;
 StepEndm2 = false;
  }
       
      }
  
  
  }

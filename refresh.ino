void refresh(){
  
    stepper(stepPinT, dirPinT, 0, sspeedT, stepsPerRevolutionT); //t o///////////////1
  
       stepper(stepPinT2, dirPinT2, 1, sspeedT2, stepsPerRevolutionT2);
       newNozzleUp(stepPin,dirPin,sspeed,stepsPerRevolution); //newNozzleUp(int stepPin,int dirPin, int sspeed,int stepsPerRevolution)
while(1){
   newPistonForward(nLswitch,nRswitch,nRelay1,nRelay2);
       newPistonBack(nLswitch,nRswitch,nRelay1,nRelay2);//newPistonBack(int nLswitch,int nRswitch)
       delay(2000);
  }
      
  
  }

void refresh(){
  
    stepper(stepPinT, dirPinT, 0, sspeedT, stepsPerRevolutionT); //t o///////////////1
  
       stepper(stepPinT2, dirPinT2, 1, sspeedT2, stepsPerRevolutionT2);
       newNozzleUp();
while(1){
   newPistonForward();
       newPistonBack();
       delay(2000);
  }
      
  
  }

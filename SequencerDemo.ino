/*
Demo App for the Corvette Engineering 24 channel EL Sequencer. 
This sketch shows how to run a series of EL patterns, AKA sequence.
It runs through 5 sequences and then repeats. 
NextSequence() returns false when all the sequence have been run. This is the time to switch sequences or change timing etc
The number of patterns in a sequence and the number of sequences is only limited by memory, and we have a LOT of memory
Currently uint8_t are used to count steps and patterns, change to uint16_t if you need more.

sequences are in sequence.h and should be the only file you need to make changes to in most cases
*/

#include "sequencer.h"

void setup()
{
  SetupIO();

  Serial.begin(115200);

  pinMode(BUTTON_ONE, INPUT_PULLUP);
  pinMode(BUTTON_TWO, INPUT_PULLUP);

  Serial.print("EL Sequencer Start\n");

  //all on
  AllOn();

 }

void loop() 
{
  static int state = 0;

  switch(state)
  {
    case 0:
    {
      //if button one pressed while in default case
      //we come back here.
      //So wait for user to release the button
      //before waiting for waiting for next button press
      while(digitalRead(BUTTON_ONE) == LOW);

      Serial.print("Button Not pressed 0\n");
      
      state++;
    }
    break;

    case 1:
    {
      //wait for button press
      while(digitalRead(BUTTON_ONE) == HIGH);

      Serial.print("Button pressed 1\n");

      AllOff();

      state++;
    }
    break;

    case 2:
    {
      while(digitalRead(BUTTON_TWO) == HIGH);

      Serial.print("Button pressed 2\n");

      AllOn();

      delay(1000);
      state++; //run default case after this
    }
    break;

    default:
    {
      NextSequence(); //Run the sequence
      delay(200); //How long till we change patterns

      Serial.print("ee Seq\n");

      if(digitalRead(BUTTON_ONE) == LOW)
      {
        state = 0;
      }
    }

  }
}

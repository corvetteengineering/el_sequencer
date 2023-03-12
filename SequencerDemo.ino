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
 }

void loop() 
{
  NextSequence(); //Run the sequence
  delay(200); //How long till we change patterns
}

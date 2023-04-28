
#include <inttypes.h>
#include <Arduino.h>
#include "sequencer.h"
#include "sequences.h"

static uint8_t thisseq = 0;

//this array maps the Arduino pins to the EL sequencer channels
static uint8_t ELPinMap[] = 
{
//PORT D       port C       PORT A        PORT B                   port A    
//4, 5, 6, 7,  0, 1, 6, 7   7, 6, 5, 4    7, 6, 5, 4, 3, 2, 1, 0   0, 1, 2, 3   port pins
//1, 2, 3, 4,  5, 6, 7, 8,  9, 10,11,12,  13,14,15,16,17,18,19,20, 21,22,23,24  EL outputs
  12,13,14,15, 16,17,22,23, 31,30,29,28,  0, 1, 2, 3, 4, 5, 6, 7,  24,25,26,27  //Arduino pin numbers
};

//setup the IO for the sequencer
void SetupIO()
{
  DDRA = 0xFF;
  DDRB = 0xFF;
  DDRC = B11000011;
  DDRD = 0xF0; //B11110000;
}

//Writes all 24 channels of a pattern too the IO
static void SetPattern(const SequenceStruct_t *seq, uint16_t step)
{
  uint32_t pat = ((uint32_t)(seq->data[step]) <<16 | ((uint32_t)(seq->data[step+1])<<8) | (uint32_t)(seq->data[step+2]) );

  for(int i=0; i<24; i++)
  {
    digitalWrite(ELPinMap[i], (pat & 1));
    pat >>= 1;
  }
}

/*
Runs the sequences in the order listed in the Sequence sarray in sequences.h
*/
bool NextSequence()
{
  bool ret = true;
  static uint8_t Step = 0;

  //

  SetPattern(&Sequences[thisseq], Step);
  Step += 3;

  if(Step >= Sequences[thisseq].size) 
  {
    thisseq++;
    Step = 0;

    if(thisseq >= sizeof(Sequences) / sizeof(Sequences[0]))
    {
      thisseq = 0;
      ret = false;
    }
  }
  return ret;
}

void AllOff(void)
{
  for(int i=0; i<24; i++)
  {
    digitalWrite(ELPinMap[i], 0);
  }
}

void AllOn(void)
{
  for(int i=0; i<24; i++)
  {
    digitalWrite(ELPinMap[i], 1);
  }
}

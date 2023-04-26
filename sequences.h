
/*
Here lie sequences. A sequence is a list of EL light patterns. 
you can have up to 256 different sequences.
A sequence can have up to 255 patterns since we use a uint8_t to count which pattern we are using within each sequence.
The reason to use multiple sequences is so you can use the same sequence
 more than once, otherwise just make one big pattern
*/
//85 rows max per sequence, due to using a uint8_t for array size
static uint8_t SequenceStartup[][3] =
{
  {0,0,0},
  {0,0,B00000001},
  {0,0,B00000010},
  {0,0,B00000100},
  {0,0,B00001000},
  {0,0,B00010000},
  {0,0,B00100000},
  {0,0,B01000000},
  {0,0,B10000000},
  {0,B00000001,0},
  {0,B00000010,0},
  {0,B00000100,0},
  {0,B00001000,0},
  {0,B00010000,0},
  {0,B00100000,0},
  {0,B01000000,0},
  {0,B10000000,0},
  {B00000001,0,0},
  {B00000010,0,0},
  {B00000100,0,0},
  {B00001000,0,0},
  {B00010000,0,0},
  {B00100000,0,0},
  {B01000000,0,0},
  {B10000000,0,0},
};

static uint8_t SequenceOne[][3] =
{
  {0,0,0},
  {0,0,0XFF},
  {0,0,0XFF},
  {0,0XFF,0},
  {0,0XFF,0},
  {0XFF,0,0},
  {0XFF,0,0},
};

static uint8_t SequenceTwo[][3] =
{
  {0XFF,0XFF,0XFF},
  {0XF0,0XF0,0XF0},
  {0X0F,0X0F,0X0F},
  {0,0XFF,0XFF},
  {0XFF,0,0XFF},
  {0,0,0XFF},
};

static uint8_t SequenceThree[][3] =
{
  {0XFF,0XFF,0XFF},
  {0XFF,0XFF,0XFF},
  {0XFF,0XFF,0XFF},
  {0,0,0},
  {0,0,0},
  {0XFF,0XFF,0XFF},
  {0XFF,0XFF,0XFF},
  {0XFF,0XFF,0XFF},
};

static uint8_t SequenceShutdown[][3] =
{
  {0XFF,0XFF,0XFF},
  {B01111111,0XFF,0XFF},
  {B00111111,0XFF,0XFF},
  {B00011111,0XFF,0XFF},
  {B00001111,0XFF,0XFF},
  {B00000111,0XFF,0XFF},
  {B00000011,0XFF,0XFF},
  {B00000001,0XFF,0XFF},
  {B00000000,0XFF,0XFF},
  
  {0,B01111111,0XFF},
  {0,B00111111,0XFF},
  {0,B00011111,0XFF},
  {0,B00001111,0XFF},
  {0,B00000111,0XFF},
  {0,B00000011,0XFF},
  {0,B00000001,0XFF},
  {0,B00000000,0XFF},
  
  {0,0,B01111111},
  {0,0,B00111111},
  {0,0,B00011111},
  {0,0,B00001111},
  {0,0,B00000111},
  {0,0,B00000011},
  {0,0,B00000001},
  {0,0,B00000000}
};

/*
list your sequences here in the order you want to run them
*/
static SequenceStruct_t Sequences[]=
{
  MAKE_SEQUENCE(SequenceStartup),
  MAKE_SEQUENCE(SequenceOne),
  MAKE_SEQUENCE(SequenceTwo),
  MAKE_SEQUENCE(SequenceThree),
  MAKE_SEQUENCE(SequenceOne),
  MAKE_SEQUENCE(SequenceShutdown),
};
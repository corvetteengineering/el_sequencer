
#define MAKE_SEQUENCE(p) {(uint8_t*)&p, sizeof(p) }

//button 2, PD2
#define BUTTON_ONE 10

//button 3, PD3
#define BUTTON_TWO 11

//Need a way to keep track of aequence sizes
typedef struct
{
   uint8_t *data;
   uint8_t size;
}SequenceStruct_t;

//Function prototypes
void SetupIO();
bool NextSequence();

void AllOff(void);
void AllOn(void);
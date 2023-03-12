
#define MAKE_SEQUENCE(p) {(uint8_t*)&p, sizeof(p) }

//Need a way to keep track of aequence sizes
typedef struct
{
   uint8_t *data;
   size_t size;
}SequenceStruct_t;

//Function prototypes
void SetupIO();
bool NextSequence();
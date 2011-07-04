/*Macros that deal with explicity memory addresses*/
/*gets a pointer to where we want to save(address) and put save in there*/
#define memstore(address,save) { \
unsigned int *ctrlstore = (unsigned int *) address; \
*ctrlstore = save;}

/*gets a pointer to where we want to load from and save that position value to load.*/
#define memload(address,load) { \
unsigned int *ctrlstore = (unsigned int *) address; \
load = *ctrlstore;}

/*I/O MAP, make sure these are the same as defined on the mips implementation*/
#define MAPPED_INPUT0 0x00000000
#define MAPPED_INPUT1 0x00000004
#define MAPPED_INPUT2 0x00000008
#define MAPPED_INPUT3 0x0000000C
#define MAPPED_OUTPUT0 0x00000010
#define MAPPED_OUTPUT1 0x00000014
#define MAPPED_OUTPUT2 0x00000018
#define MAPPED_OUTPUT3 0x0000001C

/*not sure what these are, just use memstore(ADDR_STOP,0); before returning from main to halt the cpu.*/
#define ADDR_IO       0x00009000
#define ADDR_STOP     0x7FFFFFFC
#define ADDR_QUICK    0x00003F00

/*NOC STUFF STARTS HERE*/
/*struct that represents a noc style message*/
typedef struct nocMsg_struct{
	int x_dest;
	int y_dest;
	int x_src;
	int y_src;
	int size;
	int pointer;	
} nocMsg;

enum {X_DEST, Y_DEST, X_SRC, Y_SRC, SIZE, POINTER};
/*
Uses the dma to send a message through the NOC.
Blocks the processor until the dma get's all the data from the memory,
If nocSend has returned it DOESN'T mean that the message got to the destiny, just that the DMA has readed everything it needed from the memory.
*/
int nocSend(nocMsg msg);

int nocRec(int addr);

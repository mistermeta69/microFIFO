#ifndef _MicroFIFO
#define _MicroFIFO
#include <stdint.h>
// FIFO inline functions
#define pushq(Q,V) (Q.b[Q.t++ & Q.mask]=(V))
#define popq(Q) (Q.b[Q.h++ & Q.mask])
#define peekq(Q) (Q.b[Q.h & Q.mask])
//predicate
#define emptyq(Q) ((Q.mask &(Q.h))==(Q.mask &(Q.t)))
//predicate
#define fullq(Q) ((((Q.mask&(Q.t))-(Q.mask&(Q.h)))&Q.mask)==Q.mask)


//Queue
#define gQBITS 0x07
#define gQSIZE ((1 << gQBITS)) //must be pwr of 2
#define gQMASK ((gQSIZE - 1))   //size mask

typedef volatile struct {
    uint8_t h;     //head
    uint8_t t;     //tail
    uint8_t mask;
    uint8_t b[gQSIZE];  //buffer - type can be anything
} gQ;

// Example:
//  gQ gpibSndQ = {0,0,gQMASK};     //gpib snd queue / rs232 rcv queue
//
#endif
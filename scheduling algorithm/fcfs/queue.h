#ifndef  _INCLUDED_QUEUE_
#define _INCLUDED_QUEUE_
#include<stdint.h>
#define MAX_QUEUE_LEN 32



typedef struct _queue_ Queue;
typedef struct _process_ Process;

struct _queue_
{
uint32_t size;

uint32_t count;
uint32_t head;
uint32_t tail;



Process* q[MAX_QUEUE_LEN];

};

struct _process_
{
int bursttime;
int arrivaltime;
int finishtime;
int waitingtime;
int turnaroundtime;
int processid;
int totalbursttime;


};

Queue queue_new(uint32_t size);
Queue* queue_add_head(Queue *q,Process *process);
Queue* queue_remove(Queue *q);
uint32_t queue_full(Queue *q);
uint32_t queue_empty(Queue *q);


#endif






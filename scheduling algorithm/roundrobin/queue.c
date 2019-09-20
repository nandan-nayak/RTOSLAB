#include<assert.h>
#include<stddef.h>
#include "queue.h"

Queue queue_new(uint32_t size)
{
size=(size>0 && size<MAX_QUEUE_LEN) ? size : MAX_QUEUE_LEN;
Queue s={size,0,0,0,{0}};
return s;

}






Queue* queue_add_head(Queue *q,Process *process)
{


if(q->count<q->size)
{
q->q[q->tail]=process;
q->tail=(q->tail+1)%q->size;
++q->count;


}


return q;

}

Queue* queue_remove(Queue *q)
{

if(q->count>0)
{
q->head=(q->head+1)%q->size;
q->count--;

}


return q;
}



Process* queue_top(Queue *q)
{
if(q->count==0)
return NULL;
else
return q->q[q->head];


}






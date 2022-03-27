// priority_queue.h //
// define priority queue header using heap. //

#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "heap.h"

typedef H_DATA PQ_DATA;
typedef HEAP PQUEUE;

void PQ_Init(PQUEUE* pq, Func_React priority_comp);
int PQ_isEmpty(PQUEUE* pq);
void PQ_Insert(PQUEUE* pq, PQ_DATA data);
PQ_DATA PQ_Delete(PQUEUE* pq);

#endif

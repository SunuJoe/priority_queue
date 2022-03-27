// Func_priority_queue.c //

#include "heap.h"
#include "priority_queue.h"

void PQ_Init(PQUEUE* pq, Func_React priority_comp)
{
  Init(pq, priority_comp);
}

int PQ_isEmpty(PQUEUE* pq)
{
  return isEmpty(pq);  
}

void PQ_Insert(PQUEUE* pq, PQ_DATA data)
{
  Insert(pq, data);
}

PQ_DATA PQ_Delete(PQUEUE* pq)
{
  return Delete(pq);
}

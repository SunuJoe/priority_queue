// pq_main.c //
// gcc pq_main.c Func_priority_queue.c Func_heap.c -o pq_main

#include <stdio.h>
#include <string.h>
#include "priority_queue.h"

int Compare(PQ_DATA p1, PQ_DATA p2); 

int main(int argc, char* argv[])
{
  PQUEUE queue;
  PQ_DATA val1;
  int i;

  PQ_Init(&queue, Compare);

  PQ_Insert(&queue, "ABCDE");
  PQ_Insert(&queue, "ABC");
  PQ_Insert(&queue, "ABCD");

  for(i=0; i<3; i++)
  {
    printf("%s\n", queue.heapArr[i+1]);
  }
  
  while(!PQ_isEmpty(&queue))
  {
    printf("%s\n", PQ_Delete(&queue));
  }

  return 0;
}

int Compare(PQ_DATA p1, PQ_DATA p2)
{
  int len1, len2;
  len1 = strlen(p1);
  len2 = strlen(p2);
  return len1-len2;
}


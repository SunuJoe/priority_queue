// heap.h //
// Define header of basic heap using array. //

#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define LEN 100

typedef char* H_DATA;

typedef int (*Func_React)(H_DATA data1, H_DATA data2);
typedef struct __heap
{
  int num_of_data;
  Func_React comp;
  H_DATA heapArr[LEN];
} HEAP;

void Init(HEAP* hp, Func_React priority_comp);
int isEmpty(HEAP* hp);
void Insert(HEAP* hp, H_DATA data);
H_DATA Delete(HEAP* hp);

#endif

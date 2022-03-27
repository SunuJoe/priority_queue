// Func_heap.c //
// Define Function of heap using Array. //

#include "heap.h"

void Init(HEAP* hp, Func_React priority_comp)
{
  hp->num_of_data = 0;
  hp->comp = priority_comp;
}

int isEmpty(HEAP* hp)
{
  if(hp->num_of_data == 0)
    return TRUE;
  else
    return FALSE;
}

int getParentIdx(int idx)
{
  return idx/2;
}

int getLeftChildIdx(int idx)
{
  return idx*2;
}

int getRightChildIdx(int idx)
{
  return (idx*2)+1;
}

int getChildPriorityIdx(HEAP* hp, int idx)
{
  if(getLeftChildIdx(idx) > hp->num_of_data)
    return 0;
  else if(getLeftChildIdx(idx) == hp->num_of_data)
    return getLeftChildIdx(idx);
  else
  {
    if(hp->comp(hp->heapArr[getLeftChildIdx(idx)], hp->heapArr[getRightChildIdx(idx)]) <= 0)
    {
      return getLeftChildIdx(idx);
    }
    else
      return getRightChildIdx(idx);
  }
}

void Insert(HEAP* hp, H_DATA data)
{
  int lastIdx = hp->num_of_data+1;

  while(lastIdx != 1)
  {
    if(hp->comp(data, hp->heapArr[getParentIdx(lastIdx)]) < 0)
    {
      hp->heapArr[lastIdx] = hp->heapArr[getParentIdx(lastIdx)];
      lastIdx = getParentIdx(lastIdx);
    }
    else
      break;
  }

  hp->heapArr[lastIdx] = data;
  hp->num_of_data += 1;
}

H_DATA Delete(HEAP* hp)
{
  int lastIdx = 1;
  H_DATA lastnode = hp->heapArr[hp->num_of_data];
  H_DATA temp = hp->heapArr[1];

  int childIdx;

  while((childIdx = getChildPriorityIdx(hp, lastIdx)))
  {
    if(hp->comp(lastnode, hp->heapArr[childIdx]) <= 0)
      break;
    else
    {
      hp->heapArr[lastIdx] = hp->heapArr[childIdx];
      lastIdx = childIdx;
    }
  }
  hp->heapArr[lastIdx] = lastnode;
  hp->num_of_data -= 1;
  return temp;
}

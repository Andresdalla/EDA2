
#pragma once
#include "ColaPrioridad.cpp"

template <class E, class P>
struct MinHeapPair
{
  E fst;
  P snd;

  MinHeapPair(E fst, P snd)
  {
    this.fst = fst;
    this.snd = snd;
  }
};

template <class E, class P>
class MinHeap : ColaPrioridad<E, P>
{
private:
  MinHeapPair<E, P> **heap;
  // cantidad de elementos en el heap
  int heapSize;
  // tamanio del array
  int heapLength;

  void swap(int a, int b)
  {
    MinHeapPair<E, P> *aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
  }

  bool parentIsGreater(P child, P parent)
  {
    return parent > child;
  }

public:
  void push(E element, P priority) override
  {
    heapSize++;
    if (heapLength <= heapSize)
    {
      MinHeapPair **newHeap = new MinHeapPair *[heapLength * 2];
      for (int i = 1; i < heapLength; i++)
      {
        newHeap[i] = heap[i];
      }
      heap = newHeap;
      heapLength = heapLength * 2;
    }

    MinHeapPair<E, P> *pair = new MinHeapPair<E, P>(element, priority);
    heap[heapSize] = pair;

    siftUp(heapSize);
  }

  void siftUp(int pos)
  {
    
    int parentPos = pos / 2;
    if (parentPos < 1)
    {
      return;
    }

    MinHeapPair<E, P> *parent = heap[parentPos];
    MinHeapPair<E, P> *node = heap[pos];

    if (parentIsGreater(node->snd, parent->snd))
    {
      swap(pos, parentPos);
      siftUp(parentPos);
    }
  }
  
  void siftDown(int pos)
  {
    MinHeapPair<E, P> *nodo = heap[pos];
    int leftSonPos = pos * 2;
    int rightSonPos = pos * 2 + 1;
    MinHeapPair<E, P> *leftSon = heap[leftSonPos];
    MinHeapPair<E, P> *rightSon = heap[rightSonPos];
    if(leftSonPos <= this->heapSize)
    {
      if(rightSonPos <= this->heapSize)
      {
        if(nodo->fst >leftSon->fst)
        {
          swap(pos,leftSonPos);
          siftDown(leftSonPos); 
        }
      }
      else
      {
        int hijo = leftSonPos;
        if(leftSon->fst > rightSon->fst)
        {
          hijo = rightSonPos;
        }
        MinHeapPair<E, P> *nodoHijo = heap[hijo];
        if(nodo->fst > nodoHijo->fst)
        {
          swap(pos,hijo);
          siftDown(hijo);
        }
      }
    }
    
  }
  E pop() override
  {
    MinHeapPair<E, P> *ret = heap[1];
    heap[1] = heap[this->heapSize]:
    heap[this->heapSize] = nullptr;
    siftDown(1);
    this->heapSize--;
  }

  E top() override
  {
    return this->heap[1];
  }

  bool isEmpty() override
  {
    return this->heapSize() == 0;
  }

  int size() override
  {
    return this->heapSize();
  }
};

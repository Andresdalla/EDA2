#pragma once
#include "ColaPrioridadExtendida.cpp"

template <class E, class P>
struct MaxHeapPair
{
  E fst;
  P snd;

  MaxHeapPair(E fst, P snd) : fst(fst), snd(snd) {}
};

template <class E, class P>
class MaxHeap : public ColaPrioridad<E, P>
{
private:
  MaxHeapPair<E, P> **heap;
  int heapSize;
  int heapLength;

  void swap(int a, int b)
  {
    MaxHeapPair<E, P> *aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
  }

  bool parentIsLesser(int child, int parent)
  {
    return heap[parent]->snd < heap[child]->snd;
  }

public:
  MaxHeap()
  {
    heap = new MaxHeapPair<E, P>*[1];
    heapSize = 0;
    heapLength = 1;
  }

  void push(E element, P priority) override
  {
    if (heapSize + 1 >= heapLength)
    {
      MaxHeapPair<E, P> **newHeap = new MaxHeapPair<E, P>*[heapLength * 2];
      for (int i = 0; i < heapSize; i++)
      {
        newHeap[i] = heap[i];
      }
      delete[] heap;
      heap = newHeap;
      heapLength *= 2;
    }

    MaxHeapPair<E, P> *pair = new MaxHeapPair<E, P>(element, priority);
    heap[heapSize] = pair;
    heapSize++;

    int current = heapSize - 1;
    while (current > 0 && parentIsLesser(current, (current - 1) / 2))
    {
      swap(current, (current - 1) / 2);
      current = (current - 1) / 2;
    }
  }

  void siftDown(int pos)
  {
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int largest = pos;

    if (left < heapSize && heap[left]->snd > heap[largest]->snd)
      largest = left;

    if (right < heapSize && heap[right]->snd > heap[largest]->snd)
      largest = right;

    if (largest != pos)
    {
      swap(pos, largest);
      siftDown(largest);
    }
  }

  E pop() override
  {
    if (heapSize == 0)
      throw std::out_of_range("Heap is empty");

    MaxHeapPair<E, P> *root = heap[0];
    E rootElement = root->fst;
    delete root;

    heap[0] = heap[heapSize - 1];
    heapSize--;
    siftDown(0);

    return rootElement;
  }

  E top() override
  {
    if (heapSize == 0)
      throw std::out_of_range("Heap is empty");

    return heap[0]->fst;
  }

  bool isEmpty() override
  {
    return heapSize == 0;
  }

  int size() override
  {
    return heapSize;
  }
  void eliminar(K key)
  {
    return 0;
  }
  
  void modificarPrioridad(K key, V value)
  {
    return 0;
  }
};
#pragma once
#include "ColaPrioridad.cpp"

template <class E, class P>
struct MinHeapPair
{
  E fst;
  P snd;

  MinHeapPair(E fst, P snd) : fst(fst), snd(snd) {}
};

template <class E, class P>
class MinHeap : public ColaPrioridad<E, P>
{
private:
  MinHeapPair<E, P> **heap;
  int heapSize;
  int heapLength;

  void swap(int a, int b)
  {
    MinHeapPair<E, P> *aux = heap[a];
    heap[a] = heap[b];
    heap[b] = aux;
  }

  bool parentIsGreater(int child, int parent)
  {
    return heap[parent]->snd > heap[child]->snd;
  }

public:
  MinHeap()
  {
    heap = new MinHeapPair<E, P>*[1];
    heapSize = 0;
    heapLength = 1;
  }

  void push(E element, P priority) override
  {
    if (heapSize + 1 >= heapLength)
    {
      MinHeapPair<E, P> **newHeap = new MinHeapPair<E, P>*[heapLength * 2];
      for (int i = 0; i < heapSize; i++)
      {
        newHeap[i] = heap[i];
      }
      delete[] heap;
      heap = newHeap;
      heapLength *= 2;
    }

    MinHeapPair<E, P> *pair = new MinHeapPair<E, P>(element, priority);
    heap[heapSize] = pair;
    heapSize++;

    int current = heapSize - 1;
    while (current > 0 && parentIsGreater(current, (current - 1) / 2))
    {
      swap(current, (current - 1) / 2);
      current = (current - 1) / 2;
    }
  }

  void siftDown(int pos)
  {
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int smallest = pos;

    if (left < heapSize && heap[left]->snd < heap[smallest]->snd)
      smallest = left;

    if (right < heapSize && heap[right]->snd < heap[smallest]->snd)
      smallest = right;

    if (smallest != pos)
    {
      swap(pos, smallest);
      siftDown(smallest);
    }
  }

  E pop() override
  {
    if (heapSize == 0)
      throw std::out_of_range("Heap is empty");

    MinHeapPair<E, P> *root = heap[0];
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
};
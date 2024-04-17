#pragma once

#include "lfu_cache.cpp"
#include "../Cola_de_prioridad/MinHeap.cpp"
#include "../Cola_de_prioridad/MaxHeapExtendido.cpp"

template<class K,class V>
class lfuImp : public lfu_cache<K, V> {
private:
    bool *arr;
    MinHeap<K, int> *heap;
    struct lfuImp
    {
        /* data */
    };
    
public:
    lfuImp(int size) {
        arr = new bool[size];
        for(int i = 0;i<size;i++)
        {
            arr[i] = false;
        }
        heap = new MaxHeap<K, int>();
    }

    void set(K key, V value) override {
        //primero insertamos en el array
        arr[key] = true;
        //luego insertamos en el heap
        if(this->exists(key))
        {
            this->heap->modificarPrioridad(key, 0);
        }else if(!this->exists(key))
        {
            this->heap->push(key,0);
        }else if(this->heap->size() == this->heap->heapLength)
        {
            this->heap->heapSize--;
            this->heap->push(key,value);            
        }
    }

    V get(K key) override {
        this->heap->
        //

    }
    
    bool exists(K key) override {
        if(this->arr[key] == false){
            return false;
        }
    }
};
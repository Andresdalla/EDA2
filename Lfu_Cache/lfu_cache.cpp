#pragma once
template<class K,class V>

class lfu_cache {
    virtual bool exists(K key) = 0;
    virtual get(K key) = 0;
    virtual void set(K key, V value) = 0;
};    
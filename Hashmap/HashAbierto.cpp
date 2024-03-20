#include "Map.cpp"
#include "HashFunc/hashFunc.cpp"

template<class K, class V>
class HashAbierto : public map<K,V>
{
public:
    HashAbierto(hashFunc<k> func, int expectedSize)
    {
        this->func = func
    }        
};


#pragma once
template<class K,class V>

class ColaPrioridadExtendida: public ColaPrioridad{
    virtual eliminar(K key) = 0;
    virtual modificarPrioridad(K key, V value) = 0;
    virtual V get(K key) = 0;
};  
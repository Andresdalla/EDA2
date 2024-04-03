template<class K, class V>
class Map :public iterable<pair<K,V>>{
    public:
    //Metodos y funciones basicas del TAD
    //Virtual es para que se pueda reescribir
    //El igualado a 0 lo hacemos para que cuando se use la clase, se tenga
    //que definir si o si
    virtual bool has(K key) = 0;
    virtual V remove(K key) = 0;
    virtual void set (K key, V value) = 0;
    virtual void remove(K key) = 0;
    virtual int size() = 0;
};

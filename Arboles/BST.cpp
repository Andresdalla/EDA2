template<class T>
class BTS{
    public:
    //Metodos y funciones basicas del TAD
    //Virtual es para que se pueda reescribir
    //El igualado a 0 lo hacemos para que cuando se use la clase, se tenga
    //que definir si o si
    virtual void insert(T data) = 0;
    virtual void remove(T data) = 0;
    virtual bool contains(T data) = 0;
    virtual int height(T data) = 0;
    virtual int size(T data) = 0;
};
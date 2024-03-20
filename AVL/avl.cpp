#include "BST.cpp"
template<class T>

struct AVLNode{
    T data;
    AVLNode <T>* left;
    AVLNode <T>* right;
    int height = 1;

    AVLNode(T data){
        this->data = data;
    }
};

template<class T>

class AVL :public BST<T>{
private:

    AVLNode<T> * root = nullptr;
    
    int elements = 0;

    int max(int a, int b){
        if(a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }

    int nodeHeight()
    {
        if(node == nullptr)
        {
            return 0;
        }
        else
        {
            return this->root->height;
        }
    }

    int balanceFactor(AVLNode<T> * node)
    {
        return nodeHeight(node->left) - nodeHeight(node->right); 
    }

    AVLNode<T>* insertNode(AVLNode<T>* node, T data){
        //primer caso: arbol de altura 1
        if(node == nullptr)
        {
            this->elements++;
            return new AVLNode<T>(data);
        }
        //else
        if(node->data == data)
        {
            return node;
        }
        //else
        if(data > node->data)
        {
            node->right = insertNode(node->right,data);
        }
        else
        {
            node->left = insertNode(node->lelft,data);
        }
        node->height = 1 + max(nodeHeight(node->left),nodeHeight(node->right));
        //Hasta ahora la insersion es igual que un avl.
        //faltaria balancearlo. Lo hacemos en base al factor de balance
        int bF = balanceFactor(node);
        if(bF > 1)
        {
            //desbalanceado a la izquierda
            int bFLeft = balanceFactor(node->left);
            if(bFLeft > 0)
            {
                return rightRotation(node);
            } else if (bFLeft < 0 )
            {
                return leftRightRotation(node);
            }
        }
        if(bF < -1)
        {
            //desbalanceado a la derecha
            int bFRight = balanceFactor(node->right);
            if(bFRight > 0)
            {
                leftRotation(node);
            } else if (bFRight < 0 )
            {
                rightLeftRotation(node);
            }
        }
        return node;
    }
    
    AVLNode<T>* leftRotation(AVLNode<T>* node){
        AVLNode<T>* z = node;
        AVLNode<T>* y = node->right;
        
        z->right = y->left;
        y->left = z;

        z->height = 1 + max(nodeHeight(z->left),nodeHeight(z->right));
        y->height = 1 + max(nodeHeight(y->left),nodeHeight(y->right));
        return y;
    }
    
    AVLNode<T>* rightRotation(AVLNode<T>* node){
        AVLNode<T>* z = node;
        AVLNode<T>* y = node->left;
        
        z->left = y->right;
        y->right = z;

        z->height = 1 + max(nodeHeight(z->right),nodeHeight(z->left));
        y->height = 1 + max(nodeHeight(y->right),nodeHeight(y->left));
        return y;
    }
    AVLNode<T>* leftRightRotation(AVLNode<T>* node){
        //En teoria primero le aplicaria una rotacion izaquierda al hijo del nodo desbalanceado 
        // y luego le aplicaria una rotacion derecha al nodo desbalanceado en sí
        leftRotation(node->left);
        return rightRotation(node);
    }
    
    AVLNode<T>* rightLeftRotation(AVLNode<T>* node){
        //En teoria primero le aplicaria una rotacion izaquierda al hijo del nodo desbalanceado 
        // y luego le aplicaria una rotacion derecha al nodo desbalanceado en sí
        rightRotation(node->right);
        return leftRotation(node);
    }    
public:
    int height() override
    {
        if(this->root == nullptr){
            return 0;
        }
        else
        {
            return this->root->height;
        }
    }
    
    int size() override
    {
        if(this->root == nullptr)
        {
            return 0
        }
        else
        {
            return (size(this->root->left) + size(this->root->left) + 1) 
        }
    }

    void insert(T data) override
    {
        this->root = insertNode(this->root, nullptr);
    }

    // quedan por hacer el contains y el remove
};
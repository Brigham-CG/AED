#include <iostream>

using namespace std;

template <class T>

class Node
{
    public:
        T dato;
        Node<T> *next;
        Node<T> *before;
        Node(T datoIN, Node<T>* nextIN=nullptr, Node <T> *beforeIN = nullptr): dato(datoIN), next(nextIN), before(beforeIN){}
};

template <class T>
class List
{
    Node<T> *HEAD = nullptr;
    
    public:

        bool find(T x, Node<T> *&ptr )
        {

            Node <T> *ptrB = nullptr;

            for(ptr = HEAD; ptr && ptr->dato <= x; ptrB = ptr, ptr = ptr->next)
            {
                if(ptr->dato == x)
                {
                    ptr = ptrB;
                    return true;
                }
            }
        
            ptr = ptrB;
            return false;
        }

        void ins(T x)
        {
            Node <T> *ptr;

            if(!find(x, ptr))
            {   
                if(!ptr)
                {
                    // primer elemento
                    if(HEAD)
                    {
                        // elemento al inicio
                        
                        Node <T> *t = HEAD;
                        HEAD = new Node<T> (x, t);
                    }
                    else{
                        // lista vacia 
                        HEAD = new Node<T>(x);
                    }
                }
                else{

                    // desde el segundo al ultimo

                    Node <T> *t = new Node<T>(x, ptr->next);
                    ptr->next = t;
                }
            }
        }

        void rem(T x)
        {
            Node <T> * ptr;

            if(find(x, ptr))
            {
                if(!ptr)
                {
                    // primer elemento
                    Node<T> *t = HEAD;
                    HEAD = HEAD->next;
                    delete t;
                }
                else{
                
                    // desde el segundo al ultimo
                    Node<T> *t = ptr->next;
                    ptr->next = ptr->next->next;
                    delete t;
                }
            }
        }

        void print()
        {
            cout << "HEAD -> ";
            for (Node<T> *ptr = HEAD; ptr; ptr = ptr->next)
            {   
                cout << ptr->dato << " -> ";
            }
            cout << "NULL\n";
        }

        ~List()
        {
            cout << "\nList deleted!\n";
            while(HEAD)
            {   
                Node<T> *ptr = HEAD; 
                HEAD = HEAD->next;
                delete ptr;
            }
        }
};

int main()
{  
    List<int> a;
    a.ins(1);
    a.ins(3);
    a.ins(4);
    a.ins(6);
    a.ins(2);
    a.ins(5);
    a.ins(0);
    a.ins(-1);
    a.ins(10);
    a.ins(-1);
    a.ins(10);
    a.print();
    a.rem(1);
    a.rem(-1);
    a.rem(10);
    a.print();
}
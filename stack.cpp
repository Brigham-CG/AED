#include <iostream>

using namespace std;

template <class T>
class Nodo{

    public:
        T dato = 0;
        Nodo *next;
        Nodo(T datoIn, Nodo *nextIn = nullptr): dato(datoIn), next(nextIn){} 
};

template <class T>
class Stack
{
    Nodo<T> *TAIL = nullptr;
    public:

    Stack(){

    }   
    Stack(T dato){
        push(dato);
    }   

    void push(T datoIN)
    {
        TAIL = new Nodo<T>(datoIN, TAIL);
    }
    void print()
    {
        for(Nodo<T> *ptr=TAIL; ptr; ptr=ptr->next)
        {
            cout << ptr->dato << " -> ";
        }
        cout << "NULL\n";
    }

    T pop()
    {
        if(TAIL)
        {
            Nodo<T> *t = TAIL;
            T tDato = t->dato;
            TAIL = TAIL->next;
            delete t;
            return tDato;
        }
    }
    ~Stack(){
        while(TAIL)
            pop();
    }   

};

int main()
{
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.print();
}
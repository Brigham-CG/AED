#include <iostream>

using namespace std;

template <class T>
struct Node{

    T dato = 0;
    Node<T> *next = nullptr;
    Node<T> *before = nullptr;
    Node(int datoIn = 0, Node<T> *nextIn = nullptr, Node<T> *beforeIn = nullptr):
     dato(datoIn), next(nextIn), before(beforeIn){};
};

template <class T>
class List
{   
    Node<T> *HEAD;
    Node<T> *TAIL;
    int n_elem = 0;
    public:

        void push_back(int dato)
        {
            
            Node<T> *ele = new Node<T>(dato);
            if(!n_elem)
            {
                HEAD = TAIL = ele;
            }
            else{
                ele->before = TAIL;
                TAIL = TAIL->next = ele; 
            }
            n_elem++;
        }

        void push_front(int dato)
        {
            Node<T> *ele = new Node<T>(dato);
            if(!n_elem)
            {
                HEAD = TAIL = ele;
            }
            else{
                ele->next = HEAD; 
                HEAD = ele;
            }
            n_elem++;

        }

        void pop_back()
        {
            if(n_elem)
            {
                TAIL = TAIL->before;
                delete TAIL->next;
                TAIL->next = nullptr;
                n_elem--;
            }
        }

        void pop_front()
        {
            if(n_elem)
            {
                HEAD = HEAD->next;
                delete HEAD->before;
                HEAD->before = nullptr;
                n_elem--;
            }
        }

        void print()
        {

            cout << "HEAD ";
            for (Node<T> *ptr = HEAD;ptr; ptr = ptr->next)
            {
                cout << " <--> "<< ptr->dato ;
            }     
            cout << " <--> TAIL\n";
        }

        int & operator[](int i)
        {

            if(i >= n_elem)
                i = n_elem -1;

            Node<T> *ptr = HEAD; 
            for(int k = 0; k < i; k++){
                ptr = ptr->next;
            }
            return ptr->dato;
        }
};

int main()
{
    List<int> lista;
    lista.push_back(3);
    lista.push_back(2);
    lista.push_back(1);
    lista.push_front(0);
    lista.push_front(6);
    lista.print();
    lista.pop_back();
    lista.pop_back();
    lista.pop_front();
    lista.print();
    int &a = lista[5];
    cout << a << endl;
}
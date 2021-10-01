//expresion matematica - posfija

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

        int size(){
            return n_elem;
        }

        T operator[](int i)
        {

            if(i == -1 || i >= n_elem)
                i = n_elem -1;

            Node<T> *ptr = HEAD; 
            for(int k = 0; k < i; k++){
                ptr = ptr->next;
            }
            return ptr->dato;
        }
};

template <class T>
class Stack
{
    Node<T> *TAIL = nullptr;
    int cant = 0;
    public:

    Stack(){

    }   
    Stack(T dato){
        push(dato);
    }   

    void print()
    {
        cout << "TAIL -> ";
        for(Node<T> *ptr=TAIL; ptr; ptr=ptr->next)
        {
            cout << ptr->dato << " -> ";
        }
        cout << "NULL\n";
    }

    int size(){
        return cant;
    }

    void push(T datoIN)
    {
        TAIL = new Node<T>(datoIN, TAIL);
        cant++;
    }


    T dato()
    {
        return TAIL->dato;
    }

    T pop()
    {
        Node<T> *t = TAIL;
        T tDato = t->dato;
        TAIL = TAIL->next;
        delete t;
        cant--;
        return tDato;
    }

    ~Stack(){
        while(TAIL)
            pop();
    }   

};

void to_posfijo(char *exprs, List<char> &postfijo)
{
    Stack<char> s;

    for (;*exprs;exprs++)
    {
        if(*exprs == ' ')
            continue;
        else if(*exprs == '(')
            s.push(*exprs);
        else if(*exprs == ')')
        {
            // vaciar pila
            while(s.dato() != '(')
            {
                postfijo.push_back(s.pop());
            }
            // eliminar parentesis izquierdo
            s.pop();
        }
        else if((int) *exprs < 48)
        {   
            // // añadir operadores
            
            do{

                if(!s.size() || (int)*exprs > (int)s.dato())
                {
                    s.push(*exprs);
                    break;
                }
                else{
                    postfijo.push_back(s.pop());
                }

            }while(true);
        }

        else{
            // añadir numeros
            postfijo.push_back(*exprs);
        }

    }
    while(s.size())
    {
        postfijo.push_back(s.pop());
    }
}

float to_number(char oper)
{
    return (int)oper - 48;
}
char to_char(float oper)
{
    return (char)(oper + 48);
}

float operar(float oper1, float oper2, char &oper)
{
    if (oper == '+')
        return oper1 + oper2;
    else if(oper == '-')
        return oper1 - oper2;
    else if(oper == '*')
        return oper1 * oper2;
    else 
        return oper1 / oper2;
}

float resolver(List<char> postfijo)
{
    Stack<char> s;
    float result = 0;
    for (char oper = postfijo[0]; postfijo.size();  postfijo.pop_front())
    {
        oper=postfijo[0];
        if((int) oper >= 48)
        {
            // operando 
            s.push(oper);
        }
        else
        {
            // operar
            float oper1, oper2;
            oper2 = to_number(s.pop());
            oper1 = to_number(s.pop());
            result = operar(oper1, oper2, oper);
            if(postfijo.size() != 1)
            {
                s.push(to_char(result));

            }
            else{
                break;
            }
        }           
    }
    return result;
}

int main()
{
    char e[] = "(3+5)*(7-4)";
    List<char> postfijo;
    to_posfijo(e, postfijo);
    postfijo.print();
    cout << resolver(postfijo) << endl; 
}   
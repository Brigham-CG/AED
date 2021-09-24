#include <iostream>
using namespace std;

class Nodo{

    public:
        int dato = 0;
        Nodo *next;
        Nodo(int datoIn, Nodo *nextIn = nullptr): dato(datoIn), next(nextIn){} 
};

class Vector{
    
    int m_num_elem = 0;
    Nodo *m_v = nullptr;
    public:
        Vector()
        {            
        }

        void print()
        {

            Nodo *ptr = m_v;
            cout << "Vector-->" ;
            for( int i = 0; i < m_num_elem; i++, ptr= ptr->next)
        
                cout << ptr->dato << "-->"; 
            cout << "NULL\n";
        }

        // void resize(){

        //     Nodo *ptr = m_v;
        //     for (int i = 0; i < m_num_elem; i++, ptr= ptr->next);


        //     for(int i = 0; i < m_size*2; i++, ptr = ptr->next){

        //         ptr->next = new Nodo(0);
        //     }
            
        // }

        void push_back(int datoIN)
        {

            if(m_num_elem == 0)
            {
                m_v = new Nodo(datoIN);
                Nodo *ptr = m_v;   
            }
            else{
                Nodo *ptr = m_v;
                for (int i = 0; i < m_num_elem - 1; i++, ptr= ptr->next);
                ptr->next = new Nodo(datoIN);
            } 
            m_num_elem++;
        }
        
        void pop_back()
        {
            Nodo *ptr = m_v;
            if (m_num_elem >0)
            {
                for (int i = 0; i < m_num_elem - 1; i++, ptr= ptr->next);
                delete ptr->next;
                m_num_elem--;
            }
        }

        void push_front(int datoIN)
        {   
            
            if(m_num_elem == 0)
            {
                m_v = new Nodo(0);
                Nodo *ptr = m_v;   
            }
            else{
                Nodo *ptr = new Nodo(datoIN, m_v);
                m_v = ptr;
                m_num_elem++;
            }
        }

        void pop_front()
        {
            if(m_num_elem > 0){

                Nodo *ptr = m_v;
                m_v = m_v->next;
                m_num_elem--;
                delete ptr;  
            }
        }
        
};

int main()
{
    Vector vec;
    vec.print();
    vec.push_back(1);
    vec.print();
    vec.push_back(2);
    vec.print();
    vec.push_back(3);
    vec.print();
    vec.pop_back();
    vec.print();
    vec.push_front(0);
    vec.print();
    vec.pop_front();
    vec.print();
}   
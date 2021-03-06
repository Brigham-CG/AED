#include <iostream>
using namespace std;

class Vector{

    public:

    Vector(int size = 1){
        m_size = size;
        m_v = new int[m_size];
        m_num_elem = 0;
    }

    ~Vector(){
        delete m_v;
    }

    void print()
    {
        for (int *ptr = m_v; ptr < m_v + m_num_elem; ptr++)
            cout << *ptr << " ";
        cout << endl;
    }

    void resize()
    {
        int *newVec = new int[2*m_size];    
        int *t = newVec;
        for (int *ptr = m_v; ptr < m_v + m_size; ptr++, t++)
        {
            *t = *ptr;
        }
        delete m_v;
        m_v = newVec;
    }

    void push_back(int x){

        if (m_num_elem == m_size){
            resize();
        }
        m_v[m_num_elem] = x;
        m_num_elem++;
        
    }

    void push_front(int x)
    {
        if(m_num_elem == m_size)
            resize();
        
        for (int *ptr = m_v + m_num_elem-1 ; ptr >= m_v; ptr--)
            *(ptr+1) = *ptr;

        *m_v = x;
        m_num_elem++;
    }

    int pop_back(){

        if(m_num_elem > 0)
        {
            int t = *(m_v+m_num_elem-1);
            *(m_v+m_num_elem-1) = 0;
            m_num_elem--;
            return t;
        }
        else{

            delete m_v;
            m_v = new int[5];
            return -1;
        }
    }
    
    int pop_front()
    {
        if(m_num_elem > 0)
        {
            int t = *m_v;

            for(int *ptr = m_v; ptr < m_v + m_num_elem; ptr++)
            {
                *ptr = *(ptr + 1);
            }
            m_num_elem--;

            return t;
        }
        else{

            delete m_v;
            m_v = new int[0];
            return -1;
        }
    }

    int & operator[](int i)
    {       
        return m_v[i];
    }


    private:
        int *m_v;
        int m_size;
        int m_num_elem;
};

int main()
{
    Vector vec(5);
    for (int i = 0; i < 12; i++){
        vec.push_back(i);
        vec.print();
    }

    for(int i = 0; i < 4; i++){
        vec.push_front(i);
        vec.print();
    }

    for(int i= 0; i < 5; i++){
        vec.pop_back();
        vec.print();
    }

    for(int i = 0; i < 20;i++){
        vec.pop_front();
        vec.print();
    }
    vec.push_back(3);
    vec.print();
    int &a = vec[2];
    cout << &a << endl;
}   
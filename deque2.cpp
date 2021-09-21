#include <iostream>

using namespace std;

class Deque
{
    int **map;
    int **iniMap;    
    int **endMap;
    int *ini;
    int *end;
    int size = 5;

    public:

        Deque()
        {
            map = new int * [size];
            endMap = iniMap = map + size / 2;
            *iniMap = new int[size];
            end = ini = *iniMap + size / 2;
        }

        void push_back(int x)
        {
            if(endMap == *map + size-1)
            {

            }
            if(end == *endMap + size - 1)
            {
                //el array esta lleno, se crea uno nuevo
                endMap++;
                end = *endMap = new int[size];
                *end = x;
            }
            else
            {
                // el array aun no esta lleno entonces se trabaja sobre el mismo 
                end++;
                *end = x;
            }
        }

        void push_front(int x)
        {
            if(ini == *iniMap)
            {
                //el array esta lleno, se crea uno nuevo
                iniMap--;
                *iniMap = new int [size];
                ini = *iniMap + size ;
                *ini = x;
            }
            else
            {
                // el array aun no esta lleno entonces se trabaja sobre el mismo 
                ini--;
                *ini = x;
            }
        }

        void print()
        {
            int *ptri = ini;
            for (int **ptr = iniMap; ptr <= endMap; ptr++, ptri = *ptr)
            {
                if (ptr == endMap)
                {
                    while(ptri <= end)
                    {   
                        cout << *ptri << " ";
                        ptri++;
                    }
                }
                else{
                    while(ptri <= *ptr + size - 1 )
                    {   
                        cout << *ptri << " ";
                        ptri++;
                    }
                    cout << " - ";
                }
            }
            cout << endl;
        }


        void pop_front()
        {
            if(ini == *iniMap + size - 1)
            {
                // la posicion del primer elemento esta al final del primer limite
                delete *iniMap;
                iniMap++;
                ini = *iniMap;
            }
            else{
                ini++;
            }
        }

        void pop_back()
        {
            if(end == *endMap)
            {
                // la posicion del primer elemento esta al final del primer limite
                delete *endMap;
                endMap--;
                end = *endMap + size - 1;
            }
            else{
                end--;
            }
        }

        int & operator[](int i)
        {
            int **fila = iniMap + i / size;
            
            // descontar la cantidad de numeros. al primer array


            return *(*fila + i - size*i / 2); 
        }

};

int main()
{
    Deque d;
    d.push_back(3);
    d.push_front(4);
    d.push_back(3);
    d.push_front(4);
    d.push_back(3);
    d.push_front(4);
    d.push_back(3);
    d.push_front(4);
    d.push_back(3);
    d.push_front(4);
    d.push_back(3);
    d.push_front(4);
    d.print();
    d.pop_back();
    d.pop_front();
    d.print();
}
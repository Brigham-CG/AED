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
    int cantEle;

    public:

        Deque()
        {
            map = new int * [size];
            // añadir posiciones iniciales
            endMap = iniMap = map + size / 2;
            *iniMap = new int[size];
            end = ini = *iniMap + size / 2;
            end--;
            //
            cantEle = size / 2;
        }

        void expand_map()
        {
            int **t = new int*[size + 2];
            int **tt = t;
            tt++;
            for (int **ptr = map; ptr < map + size; ptr++){
                *tt = *ptr; 
            }
            map = t;
        }

        void push_back(int x)
        {
            if(end == *endMap + size - 1)
            {
            
                if(endMap== map + size - 1)
                {
                     // expandir mapa
                    expand_map();
                }
                else{
                    //el array esta lleno, se crea uno nuevo
                    endMap++;
                    end = *endMap = new int[size];
                    *end = x;
                }
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
                if(endMap== map + size - 1)
                {
                    // expandir mapa
                    expand_map();
                }
                else{
                    //el array esta lleno, se crea uno nuevo
                    iniMap--;
                    *iniMap = new int [size];
                    ini = *iniMap + size ;
                    *ini = x;
                    cantEle = size;
                }
            }
            else
            {
                // el array aun no esta lleno entonces se trabaja sobre el mismo 
                ini--;
                *ini = x;
                cantEle--;
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
                cantEle = 0;
            }
            else{
                ini++;
                cantEle++;
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

            return *(*fila + (i + cantEle) % size); 
        }

};

int main()
{
    Deque d;
    d.push_front(-1);
    d.push_back(1);
    d.push_front(-2);
    d.push_back(2);
    
    d.print();
    d.pop_back();
    d.pop_front();
    d.print();
    int &a = d[2];
    cout << a << endl;
}
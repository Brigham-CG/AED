#include <iostream>

using namespace std;

template <class T>

class Deque
{
    T **map;
    T **iniMap;    
    T **endMap;
    T *ini;
    T *end;
    T sizeMap = 5;
    T sizeArray = 5;
    T cantEle;

    public:

        Deque()
        {
            map = new T * [sizeMap];
            // añadir posiciones iniciales
            endMap = iniMap = map + sizeMap / 2;
            *iniMap = new T[sizeArray];
            end = ini = *iniMap + sizeArray / 2;
            end--;
    
            cantEle = sizeArray / 2;
        }

        void expand_map()
        {
            T **t = new T*[sizeMap + 2];
            T **tt = t;
            tt++;
            T countIni = 0, countEnd = 0;
            
            // copiar los elementos del mapa
            for (T **ptr = map; ptr < map + sizeMap; ptr++, tt++, countIni){
                *tt = *ptr;
                if(ptr < iniMap)
                {
                    // contabilizar la posicion desde el princio hasta el puntero inicial del mapa
                    countIni++;
                }
                if(ptr < endMap)
                {
                    // contabilizar la posicion desde el princio hasta el puntero final del mapa
                    countEnd++;
                }
            }
            // cambiar el puntero inicial y final en el nuevo mapa
            iniMap = t + 1 + countIni;
            endMap = t + 1 + countEnd; 
            
            delete []map;
            sizeMap+=2;
            map = t;
        }

        void push_back(T x)
        {
        
            if(end == *endMap + sizeArray - 1)
            {
                
                if(endMap == map + sizeMap - 1)
                {
                    // el final del mapa esta lleno, se expandira el mapa
                     
                    expand_map();
                }
                
                //el array esta lleno, se crea uno nuevo
                endMap++;
                end = *endMap = new T[sizeArray];
                *end = x;
                 
            }
            else
            {
                // el array aun no esta lleno entonces se trabaja sobre el mismo 
                end++;
                *end = x;
            }
        }

        void push_front(T x)
        {
            if(ini == *iniMap)
            {
                if(endMap== map + sizeMap - 1)
                {
                    // el principio del amapa esta lleno, se expandira el mapa
                    expand_map();
                }
                
                //el array esta lleno, se crea uno nuevo
                iniMap--;
                *iniMap = new T [sizeArray];
                ini = *iniMap + sizeArray ;
                *ini = x;
                cantEle = sizeArray;
            
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
            T *ptri = ini;
            for (T **ptr = iniMap; ptr <= endMap; ptr++, ptri = *ptr)
            {
                if (ptr == endMap)
                {
                    // el ultimo array en el mapa
                    while(ptri <= end)
                    {   
                        cout << *ptri << " ";
                        ptri++;
                    }
                }
                else{
                    // imprimir los primeros arrays en el mapa
                    while(ptri <= *ptr + sizeArray - 1 )
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
            if(ini+1 != end)
            {
                if(ini == *iniMap + sizeArray - 1)
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
        }

        void pop_back()
        {
            if(ini+1 != end){
                if(end == *endMap)
                {
                    // la posicion del primer elemento esta al final del primer limite
                    delete *endMap;
                    endMap--;
                    end = *endMap + sizeArray - 1;
                }
                else{
                    end--;
                }
            }
        }

        T & operator[](int i)
        {
            T **fila = iniMap + (i+cantEle) / sizeArray;
            
            // descontar la cantidad de numeros. al primer array

            return *(*fila + (i + cantEle) % sizeArray); 
        }

};

int main()
{
    Deque<int> d;
    for (int i = 0; i < 27; i++)
    {
        d.push_back(i);
        d.print();
    }

    for (int i = 0; i < 27; i++)
    {
        d.push_front(i);
        d.print();
    }

    int &a = d[6];
    cout << a << endl;
}
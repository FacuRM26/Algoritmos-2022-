#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

string leer(string ruta) {
    string linea;
    ifstream archivo(ruta);
    string cadena="";
    int contador=0;
    if (archivo.is_open()) {
        while (archivo.good()) {
          getline(archivo, linea);
          cadena+=linea+"\n";  
        }
        archivo.close();
        return cadena;
    } else {
        cout << "Imposible abrir el archivo,revise que sea una ruta correcta."<<endl;
        return "false";
    }
}





// Busqueda por Boyer Moore Horspool 
# define NO_OF_CHARS 256
 
void badCharHeuristic( string str, int size,
    int badchar[NO_OF_CHARS])
{
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}
 

int search( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int count=0;
    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
        if (j < 0)
        {
            count++;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }
        else
            s += max(1, j - badchar[txt[s + j]]);
    }
    return count;
}



int main(){

    float t1 , t2, tiempo ; 
    string texto=leer("texto.txt");
    string patron="no";
    t1 = clock();
    int cantidad=search(texto, patron);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Palabra buscada= "<<patron<<endl;
    cout<<"Cantidad de veces que aparece el patron en el texto: "<<cantidad<<endl;
    cout<<"Tiempo de busqueda : "<< tiempo<<endl<<endl;
    t1,t2=0;
    patron="los";
    t1 = clock();
    cantidad=search(texto, patron);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Palabra buscada = "<<patron<<endl;
    cout<<"Cantidad de veces que aparece el patron en el texto: "<<cantidad<<endl;
    cout<<"Tiempo de busqueda : "<< tiempo<<endl;
    return 0;
}
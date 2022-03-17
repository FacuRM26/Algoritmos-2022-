#include <iostream>
#include <list>
#include <math.h> 
#include <bits/stdc++.h>
using namespace std;

void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;//2
   list<int> pocket[10];  //1 
   for(i = 0; i< max; i++) {//3n
      m = pow(10, i+1);//5n
      p = pow(10, i);//4n

      for(j = 0; j<n; j++) {//3n
         temp = arr[j]%m;//3
         index = temp/p;  //2n  
         pocket[index].push_back(arr[j]);//4n
      }
      count = 0;//1
      for(j = 0; j<10; j++) {//3n
         while(!pocket[j].empty()) {//3n
            arr[count] = *(pocket[j].begin());//5n
            pocket[j].erase(pocket[j].begin());//5n
            count++;//2
         }
      }
   }
}
//f(n)=2+1+m(3+5+4+n(3+3+2+4)+1+10(j(5+5)))
//O(n*k)=donde n es el numero de llaves y k es la longuitud de la llave
/*Loop invariant=Justo antes de cada iteracion del bucle exterior con un valor particular de i, los numeros en la lista esta ordenado según los valores  
inducidos por sus ultimos i digitos.*/



int coste(int m, int n,int x[], int y[])
{
   m--;//2
   n--;//2
    //sort para ordenar los dos array de mayor a menor.
    sort(x, x + m, greater<int>());
    sort(y, y + n, greater<int>());
    int horizon = 1, verti = 1,i = 0, j = 0,resultado = 0;//5

   //loop principal para recorrer todo el algoritmo 
    while (i < m && j < n)//2n
    {
        if (x[i] > y[j])//3
        {
            resultado += x[i] * verti;//4
            //Incrementamos los cortes horizontales
            horizon++;//2
            i++;//2
        }
        else
        {
            resultado += y[j] * horizon;//4
            //Incrementamos los cortes verticales
            verti++;//2
            j++;//2
        }
    }
    // 2 bucles por si quedo algun elemento si contar en el bucle pasado, solo uno de los 2 ocurrá
    int total = 0;//1
    while (i < m)//1n
        total += x[i++];//5
        
   resultado += total * verti;//3

    total = 0;//1
    while (j < n)//1n
        total += y[j++];//5
    resultado += total * horizon;//3
 
    return resultado;
}
 //f(n)=9+13n+1+5n+7=18n+17
 //O(n)=lineal
 //Loop invariant=El resultado debe ser igual o menor a C1*T1+C2*T2+...+Ci*Ti ,donde C es el costo de cada corte y T es la cantidad de cortes que se han realizado.

int main()
{
    int m = 6, n = 4;
    int X[]= {2, 1, 3, 1, 4};
    int Y[] = {4, 1, 2};
    cout << coste(m, n, X, Y);
    return 0;
}



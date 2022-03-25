#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <chrono>
#include <string>
#include <windows.h>

using namespace std;
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    float t1 , t2, tiempo ; 
    //Prueba 1
        cout<<"InsertionSort Lineal"<<endl;
    int k=500000;
    int arr[k];

    int n = sizeof(arr) / sizeof(arr[0]);
    srand( time( 0 ) );
    for ( int i = 0; i < k; ++i ){
        //Elementos ordenados para calcular el lineal
        arr[i]=i;
    }

    t1=clock();
    insertionSort(arr, n);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 500.000 "<<endl;
    cout<<"Tiempo de ordenamiento: "<< tiempo<<endl<<endl;
    t1,t2=0;
    
    cout<<"Para el resto de pruebas del InsertionSort ,descomentar partes del codigo debido que no me deja crear 2 veces un arreglo,por alguna razon que desconozco"<<endl;
//Prueba 2
    /*
    cout<<"InsertionSort Lineal"<<endl;
    int k=400000;
    int arr2[k];
    
    int n = sizeof(arr2) / sizeof(arr2[0]);
    
    srand( time( 0 ) );
    for ( int i = 0; i < k; ++i ){
        //Elementos ordenados para calcular el lineal
        arr2[i]=i;
    }
    t1=clock();
    insertionSort(arr2, n);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 400.000 "<<endl;
    cout<<"Tiempo de ordenamiento: "<< tiempo<<endl<<endl;
    t1,t2=0;
    cout<<endl;
    */
   //InsertionSort Cuadratico
   //Prueba 1
   /*
     cout<<"InsertionSort cuadratico"<<endl;
    int k=100000;
    int arr2[k];
    
    int n = sizeof(arr2) / sizeof(arr2[0]);
    
    srand( time( 0 ) );
    for ( int i = 0; i < k; ++i ){
        //Elementos ordenados inversamente para calcular el cuadratico
        arr2[k-i-1]=i;
    }
    t1=clock();
    insertionSort(arr2, n);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 100.000 "<<endl;
    cout<<"Tiempo de ordenamiento: "<< tiempo<<endl<<endl;
    t1,t2=0;
    cout<<endl;
    */
    //prueba2
    /*
    cout<<"InsertionSort cuadratico"<<endl;
    int k=80000;
    int arr2[k];
    
    int n = sizeof(arr2) / sizeof(arr2[0]);
    
    srand( time( 0 ) );
    for ( int i = 0; i < k; ++i ){
        //Elementos ordenados inversamente para calcular el cuadratico
        arr2[k-i-1]=i;
    }
    t1=clock();
    insertionSort(arr2, n);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 80.000 "<<endl;
    cout<<"Tiempo de ordenamiento: "<< tiempo<<endl<<endl;
    t1,t2=0;
    cout<<endl;
*/
    return 0;
}
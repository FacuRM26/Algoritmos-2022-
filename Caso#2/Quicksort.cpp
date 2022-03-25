#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <chrono>
#include <string>
#include <windows.h>


using namespace std;

template<typename T>
void printVector(const vector<T> &vec) {
    for (auto &i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

template<typename T>
T partitionVec(vector<T> &vec,  size_t start, size_t end) {
    T pivot = vec.at(start);
    auto lh = start + 1;
    auto rh = end;
    while (true) {
        while (lh < rh && vec.at(rh) >= pivot) rh--;
        while (lh < rh && vec.at(lh) < pivot) lh++;

        if (lh == rh) break;

        T tmp = vec.at(lh);
        vec.at(lh) = vec.at(rh);
        vec.at(rh) = tmp;
    }

    if (vec.at(lh) >= pivot) return start;
    vec.at(start) = vec.at(lh);
    vec.at(lh) = pivot;
    return lh;
}

template<typename T>
void sort(vector<T> &vec, size_t start, size_t end) {
    if (start >= end)
        return;

    auto boundary = partitionVec(vec, start, end);

    sort(vec, start, boundary);
    sort(vec, boundary + 1, end);
}

template<typename T>
void quickSort(vector<T> &vec) {
    sort(vec, 0, vec.size() - 1);
}

int main()
{
    float t1 , t2, tiempo ; 

//Quicksort logaritmico
    cout<<"Quicksort Logaritmico"<<endl;
    vector<int> vec1;
    srand( time( 0 ) );
    for ( int i = 0; i < 1000000; ++i ){
    //Random lo utilizaremos para calcular el logaritmico.
      vec1.insert(vec1.begin()+i,rand() % 100000);

    }

    t1=clock();
    quickSort(vec1);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 1.000.000 "<<endl;
    cout<<"Tiempo de ordenamiento : "<< tiempo<<endl<<endl;
    t1,t2=0;

    vector<int> vec2;
    srand( time( 0 ) );
    for ( int i = 0; i < 800000; ++i ){
    //Random lo utilizaremos para calcular el logaritmico.
      vec2.insert(vec2.begin()+i,rand() % 100000);
    }

    t1=clock();
    quickSort(vec2);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 800.000 "<<endl;
    cout<<"Tiempo de ordenamiento: "<< tiempo<<endl<<endl;
    t1,t2=0;
    cout<<endl;

//Quicksort caudratico
    cout<<"Quicksort cuadratico"<<endl;
    vector<int> vec3;
    srand( time( 0 ) );
    for ( int i = 0; i < 40000; ++i ){
     //Insertamos ordenado los valores para calcular el cuadratico
        vec3.insert(vec3.begin()+i,i);
    }

    t1=clock();
    quickSort(vec3);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 40.000 "<<endl;
    cout<<"Tiempo de ordenamiento : "<< tiempo<<endl<<endl;
    t1,t2=0;

    vector<int> vec4;
    srand( time( 0 ) );
    for ( int i = 0; i < 35000; ++i ){
     //Insertamos ordenado los valores para calcular el cuadratico
        vec4.insert(vec4.begin()+i,i);
    }

    t1=clock();
    quickSort(vec4);
    t2 = clock();
    tiempo = (t2-t1)/1000;
    cout<<" >> Cantidad de elemntos procesados= 35.000 "<<endl;
    cout<<"Tiempo de ordenamiento: "<< tiempo<<endl<<endl;
    t1,t2=0;
    cout<<endl;
    return 0;
}
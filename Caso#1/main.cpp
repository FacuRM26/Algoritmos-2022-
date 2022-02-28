#include <stdio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>
#include <cassert>
using namespace std;
vector<string> split(const string &);


void triplets1(int a[],int b[], int* result){
    for(int i=0;i<3;i++){
        if (a[i]>b[i]){
            result[0]++;
        }
        if (b[i]>a[i]){
            result[1]++;
        }
    }
}

void triplets2(int a[],int b[], int* result){

    if(a[0]!=b[0]){
        int num=(a[0]-b[0])/abs(a[0]-b[0]);
        result[0]+=num+1;
        result[1]+=num-1;
    }
    if(a[1]!=b[1]){
        int num=(a[1]-b[1])/abs(a[1]-b[1]);
        result[0]+=num+1;
        result[1]+=num-1;
    }
    if(a[2]!=b[2]){
        int num=(a[2]-b[2])/abs(a[2]-b[2]);
        result[0]+=num+1;
        result[1]+=num-1;
    }
    result[0]=result[0]/2;
    result[1]=abs(result[1]/2);
    }

string timeConvertion(string horaIni){
     string formato24h= horaIni.substr(2,6);
     int horas = stoi(horaIni.substr(0,2));
     if(horaIni[8]=='A'){
       if(horas==12)
            horas=0;
     }else if(horas<12)
        horas+=12;

    formato24h = (horas<10) ? "0"+to_string(horas)+formato24h : to_string(horas)+formato24h;

	return formato24h;
}

//Creador Alonso Garita
string timeConvertion2(string horaIni){

    string formato24h= horaIni.substr(2,6);
     int horas = stoi(horaIni.substr(0,2));
    int factor = ((horas%12)/horas); //Para PM: =0 si hrs=12 | =1 en otro caso
	if(horaIni[8]=='A')
        factor--; //Para AM: =-1 si hrs=12 | =0 en otro caso

    horas += (12 * factor);

	formato24h = (horas<10) ? "0"+to_string(horas)+formato24h : to_string(horas)+formato24h;

	return formato24h;
}

int subarrayDivision(int array[],int tam ,int mes, int dia){
    int suma=0;
    int respuesta=0;
    for(int i=0;i<tam;i++){
        for(int j=0;j<mes;j++){
            suma+=array[i+j];
        }
        if (suma==dia)
            respuesta++;
        suma=0;

    }
    return respuesta;

}

int subarrayDivision2(int array[],int tam ,int mes, int dia){
    int suma=0;
    int respuesta=0;
    int num=1;
    int resta=mes-1;
    for(int i=0;i<tam;i++){
        suma+=array[i];
        if (num ==mes){
            if(suma ==dia)
                respuesta++;
            suma-=array[i-resta];
        }else{
            num++;
        }
    }
    return respuesta;
}

void minionGame(string palabra){
    int resultado[]={0,0};
    for (unsigned int i=0;i<palabra.length();i++){
        if((palabra[i]=='A'||palabra[i]=='E'||palabra[i]=='I'||palabra[i]=='O'||palabra[i]=='U')){
            resultado[0]+=palabra.length()-i;
        }
        else
            resultado[1]+=palabra.length()-i;
    }
    if(resultado[0]>resultado[1]){
        cout<<"Jugador 1 "<<resultado[0]<<endl;
    }
    else if(resultado[0]<resultado[1]){
        cout<<"Jugador 2 "<<resultado[1]<<endl;
    }
    else{
        cout<<"Empate"<<endl;
    }

}

//Autor Ericka Guo
string cipher(int k, int n, string s) {
    vector<char> result(n);

    result[0] = s[0]-48;


    for (int i = 1; i < k; i++) {
        result[i] = s[i-1] ^ s[i];
    }

    char aux;
    for (int i = k; i < n; i++) {
        aux = '0';
        for (int j = i-(k-1); j < i; j++) {
            aux = aux ^ result[j];
        }
        result[i] = aux ^ s[i];
    }

     string final_result = "";
    for (int i = 0; i < n; i++) {
        final_result += result[i]+48;
    }
    return final_result;
}


int pairsFallido(int k,int a[],int size){//Intento fallido con el hash,funciona con ciertos casos solo que depende del caso no llega a contar ciertas parejas
   map<int,int> hashh;
   int result=0;
   int num=0;
   for(int i=0;i<size;i++){
        if(hashh.find(a[i])!=hashh.end()){
           result++;
        }
        num=a[i]-k;
        hashh.insert(pair<int,int>(num,a[i]));
        num=a[i]+k;
        hashh.insert(pair<int,int>(num,a[i]));
    }
   return result;
}

//Autor Deyner navarro
int pairs(int k, vector<int> arr){

    sort(arr.begin(), arr.end());

    int pointers[] = {1, 0, 0};
    int result = 0;
    int valueDif = 0;

    while (pointers[0] < arr.size()) {

        valueDif = arr[pointers[0]] - arr[pointers[2]];

        if (valueDif == k) {
            result++;
            pointers[0]++;
            continue;
        }
        pointers[ ((valueDif - k)/abs(valueDif - k)) + 1 ]++;
    }

    return result;
}

int main()
{       
    cout<<"Caso #1 Fabricio Rios Montero"<<endl;
    cout<<"Triplets:"<<endl;
    int a[]={1,2,4};
    int b[]={3,2,5};
    int result[]={0,0};
    triplets2(a,b,result);
    cout<<result[0] <<" "<< result[1]<<endl;
    int c[]={5,6,7};
    int d[]={3,6,10};
    int result2[]={0,0};
    triplets2(c,d,result2);
    cout<<result2[0] <<" "<< result2[1]<<endl;
    cout<<endl;

    cout<<"TimeConversion"<<endl;
    cout<<timeConvertion2("07:05:45PM")<<endl;
    cout<<timeConvertion2("12:01:00AM")<<endl;
    cout<<endl;

    cout<<"Subarray Division:"<<endl;
    int array [] = {1,2,1,3,2};
    int array2 [] = {4};
    cout<<subarrayDivision2(array,5,2,3)<<endl;
    cout<<subarrayDivision2(array2,1,1,4)<<endl;
    cout<<endl;

    cout<<"Minion Game:"<<endl;
    minionGame("BANANA");
    minionGame("ARIAL");
    cout<<endl;

    cout<<"Cipher"<<endl;
    string resultado = cipher(4, 7, "1110100110");
    cout << "Resultado = " << resultado << "\n";
    string resultado2 = cipher(2, 6, "1110001");
    cout << "Resultado = " << resultado2 << "\n";
    cout<<endl;

    cout<<"Pairs"<<endl;
    //int array [] = {1, 3, 5, 8, 6, 4, 2};
    //cout<<pairsFallido(2,array,7);
    vector<int> array3 = {1, 3, 5, 8, 6, 4, 2};
    cout<<pairs(2,array3)<<endl;
    vector<int> array4= {1, 5, 3, 4, 2};
    cout<<pairs(2,array4)<<endl;
    
    return 0;
}

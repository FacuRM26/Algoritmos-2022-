#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Noticia
{
public:
    string titulo;
    string fecha;
    string reportero;
    Noticia(string titulo,string fecha,string reportero){
        this->titulo=titulo;
        this->fecha=fecha;
        this->reportero=reportero;
    }
    virtual string getInfo()=0;
};
class NoticiaPaper:public Noticia
{
private:
    string ruta;
public:
    NoticiaPaper(string titulo,string fecha,string reportero,string ruta):Noticia(titulo,fecha,reportero){
        this->ruta=ruta;
    }
    string getInfo()override{
        string result= "Titulo: "+titulo+", Fecha:"+fecha+", Reportero: "+reportero+", Ruta: "+ruta;
        return result ;
    }

};

class NoticiaDigital:public Noticia
{
private:
    list<string> lista;
public:
    NoticiaDigital(string titulo,string fecha,string reportero,list<string> lista):Noticia(titulo,fecha,reportero){
        this->lista=lista;
    }
    string getInfo()override{
        string result= "Titulo: "+titulo+", Fecha:"+fecha+", Reportero: "+reportero+", Media: ";
        for(list<string>::iterator it=lista.begin();it!=lista.end();it++){
                result+=*it+", ";
        }
        return result ;
    }
};

class NoticiaRadio:public Noticia
{
private:
    string audio;
public:
    NoticiaRadio(string titulo,string fecha,string reportero,string audio):Noticia(titulo,fecha,reportero){
        this->audio=audio;
    }
    string getInfo()override{
        string result= "Titulo: "+titulo+", Fecha:"+fecha+", Reportero: "+reportero+", Audio: "+audio;
        return result ;
    }
};

int main()
{
    setlocale(LC_ALL, "");
    cout<<"Quiz #1 y #2 Fabricio Rios Montero."<<endl;
    list<string> lista={"Tigre","gruñido","manada"};
     Noticia *notiPape= new NoticiaPaper("Adios rompe su relacion con Rusia","2022","Javier Altorre","C:/Users/User/Documents/jugador_ruso.jgp");
     Noticia *notiDigi= new NoticiaDigital("El arma secreta del tigre dientes de sable","2017","NUÑO DOMÍNGUEZ",lista);
     Noticia *notiRadi= new NoticiaRadio("Desmontando la fama de asesinas que los humanos atribuimos a las orcas","2019","Eva Rodirguez","https://www.youtube.com/watch?v=2W4B-VbrxdQ");
    Noticia *noticias[]={notiPape,notiDigi,notiRadi};
    for(int i=0;i<3;i++){
        cout<<i+1<<". "<<noticias[i]->getInfo()<<endl;
    }

    return 0;
}

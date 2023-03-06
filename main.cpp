#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "../lib/hmColor.h"


using namespace std;
const int HMCEDULA =1722966650 ;  
const string HMNOMBRECOMPLETO ="Harryson Ariel Montesdeoca Rhea" ;  

struct hmCoordenadas{
    int hmCap;
    string hmGeo;
    char hmTipo_Arsenal[10];
    hmCoordenadas* izq;
    hmCoordenadas* der;
};


void hmLeerCoordenadas() {
    ifstream hmArchivo;
    hmArchivo.open("./src/Coordenadas.txt");

    if (hmArchivo.is_open()) {
        string hmlinea;
        cout<<"Leyendo coordenadas..."<<endl;
        bool hmPrimer = false;                       // booliano que verifica si es la primera linea del archivo
        while (getline(hmArchivo, hmlinea)) {        // procesar la línea leída del archivo
            bool hmCompleto = false;                 // booliano que verifica si el porcentaje llega a 100                
            while((hmCompleto==false)&&(hmPrimer==true)){              // Imprimir de 0 a 100
                for(int i=0; i<=100;i++){
                    cout<<i<<"%"<<"\r";
                    Sleep(10);
                }
                cout<<"100%   ";
                hmCompleto = true;
            }
            if(hmPrimer==false){
                cout << RED<<"Error: "<< hmlinea <<GREEN<< endl;
            }else{
                cout << GREEN << hmlinea << endl;
            }
            
            hmPrimer = true; 
        }
        hmArchivo.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }
}

void hmInformacion(){
   cout<<GRAY<<"\n[+] Informacion Arbol Binario de capacidad belica Ucrania"<<endl;
   cout<<"\t Developer-Nombre : "<<HMNOMBRECOMPLETO<<endl;;
   cout<<"\t Developer-Cedula : "<<HMCEDULA<<endl;;
   cout<<"\t Capacidad belica : 30"<<endl;
   cout<<"\t Coordenada-Total : 7"<<endl;
   cout<<"\t Coordenada-Seccarga : 1, 7, 2, 9, 6, 5, 0"<<endl;
}
int main()

{
    hmLeerCoordenadas();
    hmInformacion();
    cout << "Hello world!" << endl;
}

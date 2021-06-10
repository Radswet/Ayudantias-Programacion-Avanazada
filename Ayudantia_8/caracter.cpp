#include <iostream>
using namespace std;
int Buscar(char *cadena, char caracter){
    char *p = cadena;
    int aux=1;
    while (*p!=caracter && *p){
        aux++;
        p++;
    }
    if(*p=caracter){
        return aux;
    }
    return -1;
}
int main(){
    char cadena[60],caracter;
    int pos;
    cout<<"cadena";
    cin.getline(cadena,60);
    cout<<"introducir caracter";
    cin.get(caracter);
    pos= Buscar(cadena, caracter);

    if(pos!=-1){
        cout<<"caracterencontrado en posicion ";
        cout<<pos<<endl;
    }
    else 
        cout<<"no encontrado";
    
}
#include <iostream>
using namespace std;

class Nodo{
    public:
    int valor;
    Nodo *siguiente;

    Nodo(int valor, Nodo *siguiente){
        this->valor=valor;
        this->siguiente = siguiente;
    }
    Nodo(int valor){
        this->valor=valor;
        this->siguiente=nullptr;
    }

};

// % imprimir iterativo
void imprimir(Nodo *nodo){
    Nodo *actual = nodo;
    for ( int i = 1; actual != nullptr ; i++) {
        cout<<"Nodo: "<<i<<" valor: "<<actual->valor<<endl;
        actual=actual->siguiente;
    }
}

// % imprimir recursivo
int imprimir2(Nodo *cabeza){
    //return (cabeza->siguiente == nullptr) ? contador + 1: tamano2(cabeza->siguiente, contador + 1);
    cout<<cabeza->valor<<endl;
    if(cabeza->siguiente == nullptr) {
        
        return 0;
    }
    else {
        return imprimir2(cabeza->siguiente);
    }
}

// % implementacion iterativa
int tamano(Nodo *cabeza){
    int contador=0;
    Nodo *actual = cabeza;
    while( actual != nullptr) {
        contador++;
        actual=actual->siguiente;
    }
    return contador;
}

// % implementacion recursiva
int tamano2(Nodo *cabeza, int contador){
    //return (cabeza->siguiente == nullptr) ? contador + 1: tamano2(cabeza->siguiente, contador + 1);
    if(cabeza->siguiente == nullptr) {
        return contador +1;
    }
    else {
        return tamano2(cabeza->siguiente, contador + 1);
    }
}




void encontrar(Nodo *cabeza, int valor){
    Nodo *actual = cabeza;
    for ( int i = 1; actual != nullptr ; i++) {
        if(actual->valor==valor){
            cout<<"se encontro el valor en la posicion "<<i<<endl;
            return;
        }
        actual=actual->siguiente;
    }
    cout<<"No se encontro el valor"<<endl;
}

int main(){
    Nodo nodo1(8);  
    Nodo nodo2(11,&nodo1);
    Nodo nodo3(9,&nodo2);
    Nodo nodo4(12,&nodo3);
    Nodo nodo5(101,&nodo4);
    Nodo nodo6(24,&nodo5);
    imprimir2(&nodo6);
    cout<<endl;
    imprimir(&nodo6);
    cout<<endl;
    cout<<"el tamaño de la lista es: "<<tamano(&nodo6)<<endl;
    cout<<endl;
    cout<<"el tamaño de la lista es: (recursivo) "<<tamano2(&nodo6,0)<<endl;
    cout<<endl;
    encontrar(&nodo6,9);
}
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> pila;
    pila.push(1);// push agrega un elemento al frente
    pila.push(2);
    pila.push(3);  

    cout<<"top "<<pila.top()<<endl; //top retorna el elemento de enfrente

    cout<<"empty "<<pila.empty()<<endl;//verifica si esta vacio, retorn un boolean 

    for(int i=0; !pila.empty();i++){
        cout<<pila.top()<<endl;
        pila.pop(); //elimina el elemento de en frente
    }
    cout<<endl;
}
#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue <int> cola;
    cola.push(1);
    cola.push(2);
    cola.push(3);
    cout<<"cabeza "<<cola.front()<<endl;
    cout<<"cola "<<cola.back()<<endl;

    //fifo 

    //first in 
    //first out

    cout<<"empty "<<cola.empty()<<endl;

    queue <int> aux;

    for(int i=0; !cola.empty();i++){
        aux.push(cola.front());
        cout<<cola.front()<<" ";
        cola.pop();
    }
    cout<<endl;
    cout<<"empty "<<cola.empty()<<endl;
    cout<<"size cola "<<cola.size()<<endl;
    cout<<"size aux "<<aux.size()<<endl;
    
    for(int i=0; !aux.empty();i++){
       
        cout<<aux.front()<<" ";
        aux.pop();
    }
}
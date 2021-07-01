#include <iostream>
#include <map>
using namespace std;
int main(){
    map <int,string> mapa;
    mapa.insert(make_pair(1,"hola"));
    mapa.insert(pair <int,string> (3,"hola2"));
    cout<<mapa.at(3)<<endl;
    mapa.erase(1);
	mapa.erase(3);
    cout<<"empty "<<mapa.empty()<<endl;
 
}
// at accede a una llave 
// empty retorna si esta vacio
// erase elimina un nodo por su llave
//insert inserta un par
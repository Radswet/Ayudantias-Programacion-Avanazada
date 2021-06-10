#include <iostream>
#include <vector>
using namespace std;
class retaurante{

};

int main(){
    vector <retaurante> vec;
    vec.push_back(1);   // 0
    vec.push_back(5);
    vec.push_back(12); // 1
    vec.push_back(13); // 2
    vec.push_back(0);
    //vec.erase(vec.begin());
    vec.pop_back();
    for(int i = 0; i < vec.size(); i++){
        cout<<vec.at(i)<<" ";
    }


    // % .push_back(i) => añadir al final del vector el elemento i
    // % .size() => retorna el tamaño del vector
    // % .at(i) => accede al elemento i del vector
    // % .pop_back() => elimina el ultimo elemento
    //    
}



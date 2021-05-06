//class rectangulo el alto y el ancho
//class area que calcule el area y ademas reciba los datos
#include <iostream>
using namespace std;

class Rectangulo{
protected:
    int alto;
    int ancho;
public:
    void descripcion(){
        cout<<"alto: "<<alto<<" ancho: "<<ancho<<endl;
    }
};

class AreaRectangulo : public Rectangulo{
public:
    void area(){
        cout<<"area: "<<alto*ancho<<endl;
    }

    void lectura(){
        cout<<"ingrese el alto y el ancho: ";
        cin>>alto>>ancho;
    }
};

int main(){
    AreaRectangulo area;
    area.lectura();
    area.descripcion();
    area.area();
}
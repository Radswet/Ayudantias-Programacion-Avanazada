#include <iostream>
#include <cmath>
using namespace std;
//calculadora de areas circulo rectangulo cuadrado trapecio
//class figura-> almacena el area y clases figuras-> calcular el area

class Figuras{
    protected:
        float area;
    public:
        Figuras(){}

        void ObtenerArea(){
            cout<<"Area: "<<area<<endl;
            cout<<endl;
        }
};

class Circulo : public Figuras{
    private:
        int Radio;
    public: 
        Circulo(int Radio){
            this -> Radio = Radio;
            area = 3.14 * pow(Radio,2);
        }
        Circulo(){}
};

class Rectangulo : public Figuras{
    private:
        int alto;
        int ancho;
    public: 
        Rectangulo(int alto, int ancho){
            this -> alto = alto;
            this -> ancho = ancho;
            area = alto * ancho;
        }
        Rectangulo(){}
};

class Cuadrado : public Figuras{
    private:
        int lado;
    public:
        Cuadrado(int lado){
            this -> lado = lado;
            area = pow(lado,2);
        }
        Cuadrado(){}
};

class Trapecio : public Figuras{
    private:
        int baseMenor;
        int baseMayor;
        int altura;
    public:
        Trapecio(int baseMenor, int baseMayor, int altura){
            this-> baseMenor = baseMenor;
            this-> baseMayor = baseMayor;
            this-> altura = altura;
            area = ((baseMayor+baseMenor)/2)*altura;
        }
        Trapecio(){}
};

int main(){
    Circulo circulo;
    Rectangulo rectangulo;
    Cuadrado cuadrado;
    Trapecio trapecio;

    int opcion;
    while (true){
        cout<<"1. circulo"<<endl;
        cout<<"2. rectangulo"<<endl;
        cout<<"3. cuadrado"<<endl;
        cout<<"4. trapecio"<<endl;
        cout<<"opcion: ";
        cin>>opcion;
        switch (opcion){
        case 1:
            int radio;
            cout<<"ingrese el radio del circulo: ";
            cin>>radio;
            circulo = Circulo(radio);
            circulo.ObtenerArea();
            break;
        case 2:
            int alto, ancho;
            cout<<"ingrese el alto del rectangulo: ";
            cin>>alto;
            cout<<"ingrese el ancho del rectangulo: ";
            cin>>ancho;
            rectangulo = Rectangulo(alto,ancho);
            rectangulo.ObtenerArea();
            break;
        case 3:
            int lado;
            cout<<"ingrese el lado del cuadrado: ";
            cin>>lado;
            cuadrado = Cuadrado(lado);
            cuadrado.ObtenerArea();
            break;
        case 4:
            int baseMenor;
            int baseMayor;
            int altura;
            cout<<"ingrese la base menor: ";
            cin>>baseMenor;
            cout<<"ingrese la base mayor: ";
            cin>>baseMayor;
            cout<<"ingrese la altura: ";
            cin>>altura;
            trapecio = Trapecio(baseMenor,baseMayor, altura);
            trapecio.ObtenerArea();
            break;
        default:
            break;
        }
    }
    
}
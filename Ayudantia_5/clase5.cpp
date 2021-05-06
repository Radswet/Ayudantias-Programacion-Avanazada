//calculadora 
//suma resta division multiplicacion
#include <iostream>
using namespace std;

class Operacion{
    protected:
        int numero1;
        int numero2;
        int resultado;
    public:
        void ingresar(){
            cout<<"ingrese el primer valor: ";
            cin>>numero1;
            cout<<"ingrese el segundo valor: ";
            cin>>numero2;
        }
};

class Suma : public Operacion{
    public:
        int operar(){
                ingresar();
                return numero1 + numero2;
        }
};

class Resta : public Operacion{
    public:
        int operar(){
            ingresar();
            return numero1-numero2;
        }
};

class Multiplicacion: public Operacion{
    public:
        int operar(){
            ingresar();
            return numero1*numero2;
        }
};

class Division : public Operacion{
    public:
        int operar(){
            ingresar();
            return numero1/numero2;
        }
};

int main(){
    Suma suma;
    Resta resta;
    Multiplicacion multiplicacion;
    Division division;

    int opcion;
    while (true){
        cout<<endl;
        cout<<"1. suma"<<endl;
        cout<<"2. resta"<<endl;
        cout<<"3. multiplicacion"<<endl;
        cout<<"4. division"<<endl;
        cout<<endl;
        cin>>opcion;
        cout<<endl;
        switch (opcion)
        {
        case 1:
            cout<<suma.operar();
            break;
        case 2:
            cout<<resta.operar();
            break;
        case 3:
            cout<<multiplicacion.operar();
            break;
        case 4:
            cout<<division.operar();
            break;
        default:
            break;
        }
    }
}
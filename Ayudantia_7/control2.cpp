#include <iostream>
#include <vector>

using namespace std;

class Vehiculo{
    protected:
    string nombre, modelo;
    int ano, ruedas, puertas;
    int asientos;
    public:
    Vehiculo(){}
    

    void Describir(){
        cout<<"nombre: "<<nombre<<endl;
        cout<<"modelo: "<<modelo<<endl;
        cout<<"año: "<<ano<<endl;
        cout<<"ruedas: "<<ruedas<<endl;
        cout<<"puertas: "<<puertas<<endl;
        cout<<"asientos: "<<asientos<<endl;
    }
    
    void Ingresar(){
        cout<<"ingrese el nombre: ";
        cin>>this->nombre;
        cout<<"ingrese el modelo: ";
        cin>>this->modelo;
        cout<<"ingrese el año: ";
        cin>>this->ano;
        cout<<"ingrese las ruedas: ";
        cin>>this->ruedas;
        cout<<"ingrese las puertas: ";
        cin>>this->puertas;
        cout<<"ingrese los asientos: ";
        cin>>this->asientos;
    }
};

class Auto : public Vehiculo{
    protected:
    string nombre_motor;
    bool automatico;
    public:
    Auto():Vehiculo(){}
    void Describir(){
        Vehiculo::Describir();
        cout<<"nombre de motor:"<<nombre_motor<<endl;
        if(automatico)
            cout<<"es automatico";
        else
            cout<<"no es automatico"; 
    }
    void Ingresar(){
        Vehiculo::Ingresar();
        cout<<"ingrese el nombre del motor: ";
        cin>>this->nombre_motor;
        cout<<"es automatico(1 si 0 no) ";
        cin>>this->automatico;
    }
    void getAsiento(){
        cout<<"el auto tiene "<<modelo<<"tiene"<<asientos<<endl;
    }
};

class Moto : public Vehiculo{
    protected:
    int velocidad_maxima;
    bool tcs;
    public:
    Moto():Vehiculo(){}
    void Describir(){
    Vehiculo::Describir();
        cout<<"velocidad maxima: "<<velocidad_maxima<<endl;
        if(tcs)
            cout<<"tiene tcs";
        else
            cout<<"no tiene tcs"; 
    }
    void Ingresar(){
        Vehiculo::Ingresar();
        cout<<"ingrese la velocidad maxima: ";
        cin>>this->velocidad_maxima;
        cout<<"tiene tcs(1 si 0 no) ";
        cin>>this->tcs;
    }

    void getAsiento(){
        cout<<"la moto tiene"<<endl;
    }
};

class Camion : public Vehiculo{
    protected:
    int cantidad_cambios;
    int carga_maxima;
    public:
    Camion():Vehiculo(){}
    void Describir(){
    Vehiculo::Describir();
        cout<<"cantidad cambios: "<<cantidad_cambios<<endl;
        cout<<"cantidad cambios: "<<carga_maxima<<endl;
    }
    void Ingresar(){
        Vehiculo::Ingresar();
        cout<<"ingrese la cantidad de cambios: ";
        cin>>this->cantidad_cambios;
        cout<<"ingrese la carga maxima ";
        cin>>this->carga_maxima;
    }

    void getAsiento(){
        cout<<"el camion"<<nombre<<" tiene "<<asientos<<asientos;
    }
};



int main(){
    vector <Auto> auto_;
    vector <Moto> moto_;
    vector <Camion> camion_;

    Auto _auto;
    Moto _moto;
    Camion _camion;

    int opcion;
    while (true){
        cout<<"1. agregar"<<endl;
        cout<<"2. listar"<<endl;
        cout<<"3. cuantas personas pueden viajar?"<<endl;

        cin>>opcion;

        if(opcion == 1){
            while (true){
                cout<<"que desea agregar"<<endl;
                cout<<"1. auto"<<endl;
                cout<<"2. moto"<<endl;
                cout<<"3. camion"<<endl;
                cin>>opcion;
                if(opcion==1){
                    _auto.Ingresar();
                    auto_.push_back(_auto);
                    break;
                }
                else if(opcion == 2){
                    _moto.Ingresar();
                    moto_.push_back(_moto);
                    break;
                }
                else if(opcion == 3){
                    _camion.Ingresar();
                    camion_.push_back(_camion);
                    break;
                }
                else{
                    cout<<"opcion invalida"<<endl;
                }
            }
            
        }
        else if(opcion == 2){
            while (true){
                cout<<"que desea listar"<<endl;
                cout<<"1. auto"<<endl;
                cout<<"2. moto"<<endl;
                cout<<"3. camion"<<endl;
                cin>>opcion;
                if(opcion==1){
                    for (int i = 0; i < auto_.size(); i++){
                        auto_.at(i).Describir();
                    }
                    break;
                }
                else if(opcion == 2){
                    for (int i = 0; i < moto_.size(); i++){
                        moto_.at(i).Describir();
                    }
                    break;
                }
                else if(opcion == 3){
                    for (int i = 0; i < camion_.size(); i++){
                        camion_.at(i).Describir();
                    }
                    break;
                }
                else{
                    cout<<"opcion invalida"<<endl;
                }
            }
        }
        else if(opcion == 3){
            while (true){
                cout<<"maximo pasajeros"<<endl;
                cout<<"1. auto"<<endl;
                cout<<"2. moto"<<endl;
                cout<<"3. camion"<<endl;
                cin>>opcion;
                if(opcion==1){
                    for (int i = 0; i < auto_.size(); i++){
                        auto_.at(i).getAsiento();
                    }
                    break;
                }
                else if(opcion == 2){
                    for (int i = 0; i < moto_.size(); i++){
                        moto_.at(i).getAsiento();
                    }
                    break;
                }
                else if(opcion == 3){
                    for (int i = 0; i < camion_.size(); i++){
                        camion_.at(i).getAsiento();
                    }
                    break;
                }
                else{
                    cout<<"opcion invalida"<<endl;
                }
            }
        }
        else{
            cout<<"ingrese una opcion valida"<<endl;
        }
    }
        
}
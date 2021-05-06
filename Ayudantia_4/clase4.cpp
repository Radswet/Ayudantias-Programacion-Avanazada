#include <iostream>
#include <vector>
using namespace std;

class Auto{
    private:
    string marca, modelo;
    int id;
    bool vendido, nuevo;
    string vendedor;
    int precio;
    public:
    Auto(string modelo_,int id_,string marca_, bool nuevo_, int precio_){
        modelo = modelo_;
        id = id_;
        marca = marca_;
        nuevo = nuevo_;
        vendido = false;
        vendedor = "";
        precio = precio_;
    }
    Auto(){}
    
    bool getVendido(){
        return vendido;
    }

    int getPrecio(){
        return precio;
    }

    void setVendido(){
        vendido = 1;
    }

    void setVendedor(string vendedor_){
        vendedor = vendedor_;
    }

    void Descripcion(){
        cout<<"Marca: "<<marca<<endl;
        cout<<"Modelo: "<<modelo<<endl;
        cout<<"id: "<<id<<endl;
        cout<<"Precio"<<precio<<endl;
        if(vendido){
            cout<<"El Vendedor fue: "<<vendedor<<endl;
        }
        else{
            if(nuevo)
                cout<<"el auto es nuevo"<<endl;
            else
                cout<<"el auto es usado"<<endl;
        }
    }
};

int main(){
    vector <Auto> autos;
    cout<<"------------automotora---------"<<endl;
    int opcion;

    //$auxiliares entrada
    string modelo;
    string marca;
    bool nuevo;
    int precio;
    string vendedor;
    

    //$auxiliares
    int id = 1;
    Auto car;
    int vendidos = 0; //# total en $ de autos vendidos
    
    while (true){
        cout<<"1. Ingresar autos."<<endl;
        cout<<"2. Listar autos disponibles para la venta."<<endl;
        cout<<"3. Listar autos vendidos."<<endl;
        cout<<"4. Vender auto. (mediante un ID)"<<endl;
        cout<<"5. Mostrar el total vendido. (en $)"<<endl;
        cin>>opcion;
        cout<<endl;

        switch (opcion){

        case 1: //" Auto(string modelo_,int id_,string marca_, bool nuevo_,int precio_)
            cout<<"ingrese el modelo del auto: ";
            cin>>modelo;
            cout<<"ingrese la marca del auto: ";
            cin>>marca;
            cout<<"si es nuevo ingrese 1 si es usado ingrese 0: ";
            cin>>nuevo;
            cout<<"ingrese el precio del auto";
            cin>>precio;
            car = Auto(modelo,id,marca,nuevo,precio);
            autos.push_back(car);
            id++;
            cout<<endl;
            break;
        
        case 2: //" autos para la venta
            for ( int i = 0; i < autos.size(); i++){
                car = autos.at(i);
                if(car.getVendido()==0){
                    car.Descripcion();
                    cout<<endl;
                }
            }
            
            break;

        case 3://"  Listar autos vendidos
            for (int i = 0; i < autos.size(); i++){
                car = autos.at(i);
                if(car.getVendido()){
                    car.Descripcion();
                    cout<<endl;
                }
            }
            break;
        case 4://" Vender auto. (mediante un ID)
            int aux;
            cout<<"ingrese el id del auto a vender: ";
            cin>>aux;
            //car = autos.at(aux-1);
            //if(car.getVendido()){
            if(autos.at(aux-1).getVendido()){
                cout<<"el auto ya esta vendido"<<endl;
                break;
            }
            cout<<"ingrese su nombre: ";
            cin>>vendedor;
            //car.setVendedor(vendedor);
            //car.setVendido();
            autos.at(aux-1).setVendedor(vendedor);
            autos.at(aux-1).setVendido();
            vendidos +=autos.at(aux-1).getPrecio(); 
            //vendidos += car.getPrecio();
            cout<<"El auto se ha vendido"<<endl;
            break;
            

        case 5:
            cout<<"el total de autos vendidos es: $"<<vendidos<<endl;
            break;

        default:
            cout<<"ingrese un numero valido"<<endl;
            break;
        }
    }

}
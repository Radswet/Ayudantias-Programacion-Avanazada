#include <iostream>
#include <vector>
using namespace std;

class Producto{
    private://----------------------privado
    string Nombre;
    int Precio;
    float Peso;

    public://---------------------public
    Producto(string Nombre_ , int Precio_ , int Peso_){
        Nombre = Nombre_;
        Precio = Precio_;
        Peso = Peso_;
    }
    /*
    Producto(string Nombre, int Precio, int Peso){
        this -> Nombre = Nombre;
        this -> Precio = Precio;
        this -> Peso = Peso;
    }
    */
    
    //---------------------------set-------------------
    void setNombre(string _Nombre){
        Nombre = _Nombre;
    }
    void setPrecio(int _Precio){
        Precio = _Precio;
    }
    void setPeso(float _Peso){
        Peso =_Peso;
    }
    //--------------------get---------------------------
    string getNombre(){
        return Nombre;
    }
    int getPrecio(){
        return Precio;
    }
    float getPeso(){
        return Peso;
    }
    void Descripcion(){
        cout<<"Nombre: "<<Nombre<<endl;
        cout<<"Precio: "<<Precio<<endl;
        cout<<"Peso:   "<<Peso<<endl;
        cout<<endl;
    }


};

int main(){
    int Opcion;
    vector <Producto> Productos;
    string Nombre;
    int Precio;
    float Peso;
    while (true)
    {
        cout<<"-------Supermercado-------"<<endl;
        cout<<"1 agregar un producto"<<endl;
        cout<<"2 listar productos"<<endl;
        cin>>Opcion;
        if(Opcion == 1){
            cout<<"cual es el producto a agregar?"<<endl;
            cout<<"ingrese el nombre: "; 
            cin>>Nombre;
            cout<<"ingrese el precio: ";
            cin>>Precio; 
            cout<<"ingrese el peso: ";
            cin>>Peso;
            Producto prod = Producto(Nombre,Precio,Peso);
            Productos.push_back(prod);
        }
        
        if(Opcion == 2){
            for (int i = 0; i < Productos.size(); i++)
            {
                Productos.at(i).Descripcion();   
            }
        }
        else{

        }
        
    }
}

/*
                    vector
.size() -> retorna el tamaño del vector
.empty() -> ve si el vector está vacío
.at() -> accede a un elemento, puede ser con []
.front() -> primer elemento
.back() -> último elemento
.push_back() -> agregar elemento al final
.pop_back() ->eliminar último elemento
*/




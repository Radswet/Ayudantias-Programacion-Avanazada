/*
%Clase Restaurante
%Contiene las mesas del local

$Clase Mesa
$Contiene la cantidad de personas en la mesael sistema debe poder realizar lo siguiente

#ingresar una mesa
#mostrar cantidad de personas en el restaurante
#mostrar las personas por cada mesa
*/
#include <iostream>
using namespace std;
class Mesa{
    private:
        int CantidadDePersonas;
    public:
        Mesa(int CantidadDePersonas_){
            CantidadDePersonas = CantidadDePersonas_;
        }
        Mesa(){}
        int getCantidadDePersonas(){
            return CantidadDePersonas;
        }
        void setCantidadDePersonas(int CantidadDePersonas_){
            CantidadDePersonas = CantidadDePersonas_;
        }
};

class Restaurante{
    private:
        Mesa mesas[10];
    public:
        Restaurante(){}
    void setMesa(int mesa, int CantidadDePersonas){
        mesas[mesa] = Mesa(CantidadDePersonas);
    }
    int getPersonas(){
        int cantidad = 0;
        for (int i = 0; i < 10 ; i++){
            cantidad += mesas[i].getCantidadDePersonas();
        }
        return cantidad;
    }
    int getMesa(int Mesa){
        return mesas[Mesa].getCantidadDePersonas();
    }
    void iniciar(){
        for (int i = 0; i < 10; i++)
        {
            mesas[i].setCantidadDePersonas(0);
        }
    }
};

int main(){
    int opcion;
    int aforo = 30;
    Restaurante restaurante;
    int personas = 0;
    restaurante.iniciar();
    while (true){
        cout<<"1. ingresar una mesa"<<endl;
        cout<<"2. mostrar cantidad de personas en el restaurante"<<endl;
        cout<<"3. mostrar las personas por cada mesa"<<endl;
        cin>>opcion;
        cout<<endl;
        if(opcion == 1){
            cout<<"ingrse el numero de mesa: ";
            int mesa;
            cin>>mesa;
            if(restaurante.getMesa(mesa - 1) == 0){
                cout<<"ingrese la cantidad de personas en la mesa: "<<endl;
                int personas;
                cin>>personas;
                if(personas + restaurante.getPersonas()<aforo){
                    restaurante.setMesa(mesa-1,personas);
                }
                else{
                    cout<<"se supera el aforo permitido"<<endl;
                }
            }
            else{
                cout<<"la mesa no esta disponible"<<endl;
            }
        }
        else if(opcion == 2){
            personas =  restaurante.getPersonas();
            cout<<"hay "<<personas<<" personas en el restaurante"<<endl;
        }
        else if(opcion == 3){
            for (int i = 0; i < 10; i++)
            {
                cout<<"la mesa "<<i + 1<<" tiene "<<restaurante.getMesa(i)<<endl;
            }    
        }
    }
}
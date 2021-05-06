#include <iostream>
#include <vector>
using namespace std;

/*
ingresar un trabajador
sueldo
años en la empresa
id 
cargo
bono años > 50 +500000 sueldo

agregar trabajador
pagar sueldos (todos)
pagar sueldo por (id)
listar trabajadores
*/

class Persona
    {
    private: 
    int sueldo, id , anos;
    string cargo;
    bool bono;
    bool  pagado;

    public: 
    Persona(int sueldo, string cargo, int id, int anos){
        this -> sueldo = sueldo;
        this -> cargo  = cargo;
        this -> id     = id;
        this -> anos   = anos;
        if(anos>50){
            this -> bono = true;
            this -> sueldo += 500000; //sueldo= sueldo+500000
        }
        else{
            this-> bono = false;
        }
    }
    Persona(){}

    bool getBono(){
        return bono;
    }
    int getSueldo(){
        return sueldo;
    }
    int getId(){
        return id;
    }
    string getCargo(){
        return  cargo;
    }
    int getAnos(){
        return anos;
    }
    bool getPagado(){
        return pagado;
    }
    void setPagado(bool pagado){
        this-> pagado= pagado;
    }


};

int main(){
    vector <Persona> vec;
    int opcion;
    bool bol;

    int sueldo, anos;
    string cargo;
    bool bono;

    int id=1;
    int sueldoPagados=0;
    int idIngresar;
    Persona aux;
    while (1) //1 == true
    {
        cout<<"1 ingresar trabajador "<<endl;
        cout<<"2 pagar todos los sueldos "<<endl;
        cout<<"3 pagar sueldos a un trabajador (por id) "<<endl;
        cout<<"4 listar trabajadores "<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1: //if(opcion==1)
            cout<<"ingrese el cargo";
            cin>>cargo;
            cout<<"ingrese los anos del trabajador en la empresa";
            cin>>anos;
            cout<<"ingrese el sueldo del trabajador";
            cin>>sueldo;
            aux = Persona(sueldo,cargo,id,anos);
            vec.push_back(aux);
            id++; //id=id+1;
            if(aux.getBono()){//aux.getBono()==true
                cout<<"por sus años de servicio al trabajador le corresponden 500000 adicionales"<<endl;
                cout<<"su nuevo sueldo es"<<aux.getSueldo()<<endl;
            }
            break;
        case 2:
            cout<<"desea pagar los sueldos?";
            cin>>bol;
            if(bol){//bol == true
                for (int i = 0; i < vec.size(); i++){ 
                    sueldoPagados += vec.at(i).getSueldo();
                    vec.at(i).setPagado(true);
                }
                cout<<"los sueldos pagados son en total $"<<sueldoPagados<<endl;
            }
            break;
        case 3:
            cout<<"a que trabajador desea pagar su sueldo (ingrese su id)"<<endl;
            cin>>idIngresar;
            for (int i = 0; i < vec.size(); i++)
            {
                aux = vec.at(i);
                if(aux.getId() == idIngresar){
                    cout<<"se han pagado"<<aux.getSueldo()<<endl;
                    sueldoPagados += aux.getSueldo();
                    aux.setPagado(true);
                }
            }
            break;
        case 4:
            cout<<"los trabajadores son: "<<endl;
            for (int i = 0; i < vec.size(); i++){
                aux = vec.at(i);
                cout<<"trabajador "<<aux.getId()<<endl;
                cout<<"sueldo "<<aux.getSueldo()<<endl;
                cout<<"cargo "<<aux.getCargo()<<endl;
                if(aux.getBono()){
                    cout<<"el trabajador tiene bono"<<endl;
                }
                    
                else{
                    cout<<"el trabajador no tiene bono"<<endl;
                }
                cout<<"anos"<<aux.getAnos()<<endl;
                cout<<"pagado"<<aux.getPagado()<<endl;

            }
            break;
        default:
            cout<<"ingrese una opcion valida";
            break;
        }
    }
}


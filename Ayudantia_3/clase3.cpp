#include <iostream>
#include <vector>
using namespace std;


/*
"Clase Pokemon
"Clase Pokedex

#Se debe poder añadir una pokedex
#Se debe poder a ̃nadir un pokemon a una pokedex especifica
#Se debe poder mostrar a todos los pokemones de una generacion o region (ingresarnombre o generacion)
#Se debe poder buscar a un pokemon dentro de todas las pokedex
*/
class Pokemon{
    private:
        int id;
        string Nombre;
        int PS;
        int PC;
    public:
        Pokemon(int id, string Nombre, int PS, int PC){
            this -> id = id;
            this -> Nombre = Nombre;
            this -> PS = PS;
            this -> PC = PC;
        }
        string getNombre(){
            return Nombre;
        }
        int getID(){
            return id;
        }
        int getPS(){
            return PS;
        }
        int getPC(){
            return PC;
        }
        void Descripcion(){
            cout<<"id: "<<id<<endl;
            cout<<"Nombre: "<<Nombre<<endl;
            cout<<"PS: "<<PS<<endl;
            cout<<"PC: "<<PC<<endl;
        }
};


class Pokedex{
    private:
        string Region;
        int Generacion;
        vector <Pokemon> pokemones;
    public:
        Pokedex(string Region, int Generacion){
            this -> Region = Region;
            this -> Generacion = Generacion;
        }
        Pokedex(){}
        // | agregar pokemon con todos sus atributos
        void AgregarPokemon(){
            int id;
            cout<<"ingrese el id: ";
            cin>>id;
            
            string Nombre;
            cout<<"ingrese el nombre: ";
            cin>>Nombre;

            int PS;
            cout<<"ingrese los PS: ";
            cin>>PS;

            int PC;
            cout<<"ingrese los PC: ";
            cin>>PC;

            Pokemon poke(id, Nombre, PS, PC);
            pokemones.push_back(poke);  // ! agrega el pokemon a vector pokemones
        }
        // |mostrar todos los pokemones de una generacion es decir de una pokedex
        void MostrarPokemones(){
            for (int i = 0; i < pokemones.size(); i++){
                pokemones.at(i).Descripcion();
            } 
        }
        // | buscar un Pokemon por Nombre
        bool BuscarPokemon(string poke){
            for (int i = 0; i < pokemones.size(); i++){
                if(pokemones.at(i).getNombre()==poke){
                    cout<<"id"<<pokemones.at(i).getID()<<endl;
                    cout<<"PS"<<pokemones.at(i).getPS()<<endl;
                    cout<<"PC"<<pokemones.at(i).getPC()<<endl;
                    return true;
                }
            }
            return false;
        }


};

int main(){
    vector <Pokedex> pokedexS;

    int opcion;
    int Generacion = 1 ; // $otorga el numero de la generacion a la pokedex automaticamente

    int gen;
    string Region;
    string poke;
    Pokedex pokedex;

    while (true){
        cout<<"1. anadir pokedex"<<endl;
        cout<<"2. ingresar pokemon"<<endl;
        cout<<"3. mostrar pokemones de una generacion"<<endl;
        cout<<"4. buscar un pokemon por el nombre en todas las pokedex"<<endl;
        cin>>opcion;
        if(opcion == 1){
            // # añadir pokedex
            cout<<"ingrese la region de la pokedex: ";
            cin>>Region;
            pokedex = Pokedex(Region, Generacion);
            pokedexS.push_back(pokedex);
            Generacion++;
            cout<<endl;
        }
        else if(opcion == 2){
            // # ingresar pokemon 
            cout<<"en que generacion desea ingresar el pokemon: ";
            cin>>gen;
            pokedexS.at(gen-1).AgregarPokemon();
            cout<<endl;
        }
        else if(opcion == 3){
            // # mostrar los pokemones de una generacion
            cout<<"de que generacion desea mostrar los pokemones: ";
            cin>>gen;
            pokedexS.at(gen-1).MostrarPokemones();
            cout<<endl;
        }
        else if(opcion == 4){
            // # bucar pokemon por nombre en todas las pokedex
            cout<<"que pokemon desea buscar: ";
            cin>>poke;
            for (int i = 0; i < pokedexS.size(); i++){
                if(pokedexS.at(i).BuscarPokemon(poke)){
                    cout<<"generacion "<<i+1;
                }
                cout<<endl;
            }
            
        }
    }
    
}

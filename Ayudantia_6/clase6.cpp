// "                 criatura
// #         mamifero       reptiles
// %  viviparos oviparos
// (  Persona
// |hombre mujer

// criatura TipoHabitat - Peso - EsperanzaVida
// mamifero PeridoGestacion
// oviparo PeriodoIncubacion
// viviparo /
// Persona Nombre - Nacimiento
// hombre
// mujer

//private -> privado para todos menos para la misma clase
//public -> publico para todos 
//protected -> publico solo para ella y las clases hijas privado para los demas

#include <iostream>
using namespace std;

class Criatura{
    protected:
    string TipoHabitat;
    float Peso;
    int EsperanzaVida;
    public:
    Criatura(string TipoHabitat, float Peso, int EsperanzaVida){
        this -> TipoHabitat = TipoHabitat;
        this -> Peso = Peso;
        this -> EsperanzaVida = EsperanzaVida;
    }
    Criatura(){}

    string getTipoHabitat(){
        return TipoHabitat;
    }
    float getPeso(){
        return Peso;
    }

    int getEsperanzaVida(){
        return EsperanzaVida;
    }

    void Descripcion(){
        cout<<"hola soy una criatura"<<endl;
        cout<<"Mi tipo de habitat es: "<<getTipoHabitat()<<endl;
        cout<<"Mi peso es: "<<getPeso()<<endl;
        cout<<"Tengo una esperanza de vida de "<<getEsperanzaVida()<<" años"<<endl;
    }
};

class Mamifero : public Criatura{
    protected:
    int PeriodoGestacion;
    public:
    Mamifero(string TipoHabitat, float Peso, int EsperanzaVida,int PeriodoGestacion):Criatura(TipoHabitat, Peso, EsperanzaVida){
        this -> PeriodoGestacion = PeriodoGestacion;
    }
    Mamifero():Criatura(){}
    int getPeriodoGestacion(){
        return PeriodoGestacion;
    }
    void Descripcion(){
        Criatura::Descripcion();
        cout<<"ademas soy un mamifero y amamanto"<<endl;
        cout<<"Tengo un periodo de gestacion de "<<getPeriodoGestacion()<<" meses"<<endl;
    }
};

class Oviparo : public Mamifero{
    protected:
    int PeriodoIncubacion;
    public:
    Oviparo(string TipoHabitat, float Peso, int EsperanzaVida,int PeriodoGestacion,int PeriodoIncubacion):Mamifero(TipoHabitat, Peso, EsperanzaVida, PeriodoGestacion){
        this -> PeriodoIncubacion=PeriodoIncubacion;
    }
    Oviparo():Mamifero(){}
    int getPeriodoIncubacion(){
        return PeriodoIncubacion;
    }
    void Descripcion(){
        Mamifero::Descripcion();
        cout<<"nazco por huevos"<<endl;
        cout<<"El periodo de incubacion de los huevos es: "<<getPeriodoIncubacion();
    }
};

class Viviparo : public Mamifero{
    protected:
    public:
    Viviparo(string TipoHabitat, float Peso, int EsperanzaVida,int PeriodoGestacion):Mamifero(TipoHabitat, Peso, EsperanzaVida, PeriodoGestacion){
    }
    Viviparo():Mamifero(){}
    void Descripcion(){
        Mamifero::Descripcion();
        cout<<"nazco por crias vivivas"<<endl;
    }

};

class Persona : public Viviparo{
    protected:
    string Nombre;
    string Nacimiento;
    public:
    Persona(string TipoHabitat, float Peso, int EsperanzaVida,int PeriodoGestacion, string Nombre, string Nacimiento):Viviparo(TipoHabitat, Peso, EsperanzaVida, PeriodoGestacion){
        this->Nombre = Nombre;
        this->Nacimiento=Nacimiento;
    }
    Persona():Viviparo(){}
    string getNombre(){
        return Nombre;
    }
    string getNacimiento(){
        return Nacimiento;
    }

    void Descripcion(){
        Viviparo::Descripcion();
        cout<<"Puedo hablar"<<endl;
        cout<<"mi nombre es: "<<getNombre()<<endl;
        cout<<"mi fecha de nacimiento es: "<<getNacimiento()<<endl;
    }
};

class Hombre : public Persona{
    protected:
    public:
    Hombre(string TipoHabitat, float Peso, int EsperanzaVida,int PeriodoGestacion, string Nombre, string Nacimiento):Persona(TipoHabitat, Peso, EsperanzaVida, PeriodoGestacion, Nombre, Nacimiento){
    }
    Hombre():Persona(){}
    void Descripcion(){
        Persona::Descripcion();
        cout<<"puedo hacer memes"<<endl;
    }
};

class Mujer : public Persona{
    protected:
    public:
    Mujer(string TipoHabitat, float Peso, int EsperanzaVida,int PeriodoGestacion, string Nombre, string Nacimiento):Persona(TipoHabitat, Peso, EsperanzaVida, PeriodoGestacion, Nombre, Nacimiento){
    }
    Mujer():Persona(){}
    void Descripcion(){
        Persona::Descripcion();
        cout<<"puedo hacer memes"<<endl;
    }
};


int main(){
    Criatura criatura;
    //criatura.Descripcion();
    Mamifero mamifero;
    //mamifero.Descripcion();
    cout<<endl;
    Oviparo oviparo;
    //oviparo.Descripcion();
    cout<<endl;
    Viviparo viviparo;
    //viviparo.Descripcion();
    Hombre hombre("ciudad", 70,80,9,"Fernando","02/12/2000");
    hombre.Descripcion();
}
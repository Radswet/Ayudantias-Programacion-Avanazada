#include <iostream> 
using namespace std;

class Persona{
    private:
        string Nombre; 
        int Edad;
    public:
    Persona(string Nombre_, int Edad_){
        Nombre = Nombre_;
        Edad = Edad_;
    }
    void DescribirPersona(){
        cout<<"Nombre: "<<Nombre<<endl;
        cout<<"Edad: "<<Edad<<endl;
        
    }
};

class Estudiante : public Persona{
    private:
        string carrera;
        string ventana;
    public:
        Estudiante(string Nombre_, int Edad_,string carrera_, string ventana_):Persona( Nombre_, Edad_){
            carrera = carrera_;
            ventana = ventana_;
        }
        void DescribirEstudiante(){
            DescribirPersona();
            cout<<"Carrera: "<<carrera<<endl;
            cout<<"Ventana: "<<ventana<<endl;
        }
};
class Universitario : public Estudiante{
    private: 
        bool ganasDeVivir;
    public:
        Universitario(string Nombre_, int Edad_,string carrera_, string ventana_,bool ganasDeVivir_):Estudiante(Nombre_, Edad_, carrera_, ventana_){
            ganasDeVivir = ganasDeVivir_;
        }

        void Describiruniversitario(){
            DescribirEstudiante();
            if(ganasDeVivir)
                cout<<"tiene ganas de vivir";
            else
                cout<<"no tiene ganas de vivir";  
        }
};

int main(){
    Persona persona("fernando",20);
    Estudiante estudiante("pape",20,"informatica","e1");
    Universitario universitario("pape",20,"informatica","e1",true);
    persona.DescribirPersona();
    cout<<endl;
    estudiante.DescribirPersona();
    cout<<endl;
    estudiante.DescribirEstudiante();
    cout <<endl;
    universitario.Describiruniversitario();
    cout<<endl;

}
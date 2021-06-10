#include <iostream>
#include <vector>

using namespace std;
//% puntero es una variable que almacena la direccion de memoria de otra variable
//% siendo N un puntero 
//% &n -> retorna la direccion de memoria de N
//% *n-> La variable
void inter(int *n1,int *n2){
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int max(int *dir,int tamaño){
    int max=0; //{1,2,3,4,5}
    for(int i=0;i<tamaño;i++){
        if(*(dir+i)>max){ 
            max = *(dir+i);
        }
    }
    return max;
}

int main(){
    /*
    int n=1;
    int *dirN = &n;
    cout<<"Direccion de memoria de N: "<<&n<<endl;
    cout<<"Valor de N: "<<n<<endl<<endl;
    
    cout<<"Direccion de memoria de N:"<<dirN<<endl;
    cout<<"Valor de N: "<<*dirN<<endl;
    */

    /*
    int numero, *dir_numero;
    cout<<"Digite un numero para verificar si es par o impar"<<endl;
    cin>>numero;
    dir_numero = &numero;
    if(*dir_numero%2==0){ //es par
        cout<<*dir_numero<<" es par"<<endl;
        cout<<"Direccion "<<dir_numero<<endl;
    }
    else{ //es impar
        cout<<*dir_numero<<" es impar"<<endl;
        cout<<"Direccion "<<dir_numero<<endl;
    }
    */

    /*
    int numeros[]={1,2,3,4,5};
    int *dir_numeros = numeros;
    for (int i = 0; i < 5; i++)
    {
        cout<<"pos = "<<i<<" valor = "<<dir_numeros++<<endl;   //dir_numeros++ -> dir_numeros+i
                                                                //dir_numeros++ cambia
                                                                //dir_numeros + i busco las siguientes posiciones
    }
    */
   /*
   int n1= 99;
   int n2= 2;

   cout<<"N1 = "<<n1<<" N2 = "<<n2<<endl;
   cout<<"dir N1 = "<<&n1<<" dir N2 = "<<&n2<<endl;
   inter(&n1,&n2);
   cout<<"N1 = "<<n1<<" N2 = "<<n2<<endl;
   cout<<"dir N1 = "<<&n1<<" dir N2 = "<<&n2<<endl;
    */

   /*
   int n[5] = {5,6,3,4,1};
   cout<<"el mayor elemento es "<<max(n,5); 
   */

    vector <int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    int *a = &vec.at(0);
    int *b = &vec.at(1);

    cout<<&vec[0]<<endl;
    cout<<&vec[1]<<endl;
    cout<<endl<<&a<<endl;
    cout<<&b<<endl;

    cout<<endl<<*a<<endl;
    cout<<*b<<endl;
}
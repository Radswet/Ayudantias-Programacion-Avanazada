#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;

    Node(int new_value, Node *new_next){
        this->value=new_value;
        this->next = new_next;
    }
    Node(int new_value){
        this->value=new_value;
        this->next=nullptr;
    }

    int getValue(){
        return this->value;
    }
    void setValue(){
        this->value=value;
    }

    Node *getNext(){
        return this->next;
    }
    void setNext(Node *next){
        this->next=next;
    }

};


class Queue{
    private:
        Node *head;
        Node *tail;
    public:
        Queue(){
            this->head=nullptr;
            this->tail=nullptr;
        }

        void pop(){ //elimina un elemento
            if(this->head == nullptr && this->tail == nullptr){ // si tanto la cabeza como la cola estan vacios retorna nada
                return;
            }
            if(this->head == this->tail){// si la cabeza es el mismo elemento que la cola entonces eliminino ese unico 
                                        // ojo no el mismo valor
                this->head = this->tail = nullptr;
            }
            this->head = this->head->getNext();// la cabeza pasa a ser el elemento siguiente
        }

        void push(int value){
            Node *n_node = new Node(value);

            if(this->head ==  nullptr && this -> tail == nullptr){ // si la cola esta vacia 
                this->head = this->tail = n_node;                   // la cabeza y la cola(ultimo elemento) se asignan como el elemnto entrante
            }
            this->tail->setNext(n_node); // se asigna el nodo entrante al ultimo nodo de la cola
            this->tail = n_node;        // se cambia la "tail" de la cola
        }

        int front(){ //accede al elemento de enfrente
            Node *tmp = this-> head; //declaramos un auxiliar igual a la cabeza
            return tmp->getValue(); // retornamos el valor de ese elemento
        }

        bool empty(){ // retorna si esta vacio
            if(this->head==nullptr){ // si la cabeza es null 
                return true; //dice si
            }
            else{ // si la cabeza no es null
                return false;// dice no
            }
        }
};

int main(){
    Queue cola;
    cola.push(1);
    cola.push(2);
    cola.push(3);

    cout<<"cabeza "<<cola.front()<<endl;
    cola.pop();
    cout<<"cabeza "<<cola.front()<<endl;
    cola.pop();
    cout<<"cabeza "<<cola.front()<<endl;   
}

//cola -> fila de super con carritos
//pila -> monton de platos apilados


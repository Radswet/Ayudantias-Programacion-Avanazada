#include <iostream>
using namespace std;

class Node{
    private:
    int value;
    Node *next;

    public:
    Node(int new_value, Node *new_next){
        this->value = new_value;
        this->next = new_next;
    }

    Node(int new_value){
        this->value = new_value;
        this->next = nullptr;
    }

    int getValue() {
        return this->value;
    }

    void setValue(int value){
        this->value = value;
    }

    Node *getNext(){
        return this->next;
    }
    void setNext(Node *next){
        this->next = next;
    }
};

class Stack{
    private:
    Node *head;
    
    public:
    Stack(){
        this->head = nullptr;
    }

    void push(int value){//agrega un elemento al frente
        Node *n_node = new Node(value, this->head);
        this->head = n_node;
    }

    int top(){//retorna el elemento de el frente
        Node *tmp = this->head;
        return tmp->getValue();
    }

    bool empty(){//retorna si esta vacio o no
        if(this->head == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    void pop(){//elimino el elemento del frente
        if(this->head !=nullptr){
            this->head = this->head->getNext();
        }
    }
};

int main(){
    Stack stack, aux;
    cout<<"empty "<<stack.empty()<<endl;
    stack.push(1);
    cout<<"top "<<stack.top()<<endl;
    stack.push(2);
    cout<<"top "<<stack.top()<<endl;
    stack.push(4);
    cout<<"top "<<stack.top()<<endl;
    cout<<"empty "<<stack.empty()<<endl;

    cout<<endl;
    for(int i=0; !stack.empty();i++){ // se recorre la pila stack y se guardan sus elementos en la pila aux
        aux.push(stack.top());
        cout<<stack.top()<<endl;
        stack.pop();
    }
    cout<<endl;

    int buscar;
    cout<<"elemento a borrar ";
    cin>>buscar;
    for(int i=0; !aux.empty();i++){// se muestran los elementos en el orden ingresado
        if(aux.top()==buscar){
            aux.pop();
        }
        else{
            stack.push(aux.top());
            aux.pop();
        }
    }
    cout<<endl;
    for(int i=0; !stack.empty();i++){ // se recorre la pila stack y se guardan sus elementos en la pila aux
        cout<<stack.top()<<endl;
        stack.pop();
    }
    
}
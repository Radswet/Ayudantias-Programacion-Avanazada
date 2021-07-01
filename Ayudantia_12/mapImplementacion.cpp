#include <iostream>
#include <string>
using namespace std;

class Pair{
	public:
  	int key;
  	string value;
	Pair *next;
  
  	Pair(int key, string value){
  		this->key = key;
      	this->value = value;
      	this->next = nullptr;
    }
    Pair(int key, string value, Pair *next){
    	this->key = key;
      	this->value = value;
      	this->next = next;
    }
};

class Map{
	public:
  	Pair *first;
  	int count;
  	Map(){
  		this->first=nullptr;
      	this-> count = 0;
    }
    Pair *add(int key, string value){
    	if(this->search_key(key)){
          	return this->first;
    	}
        if(count == 0){
			this->first = new Pair(key,value);
          	this->count++;
        }
        else if(count>0){
        	Pair *temp = this->first;
           	this->first = new Pair(key,value,temp);
          	this->count++;
        }
        return this->first;
    }
    
    bool search_key(int key){
    	Pair *temp = this->first;	
      	while(temp !=nullptr){
       		if(temp->key == key){
            	return true;
            }
            temp = temp->next; //esta linea falto en la implementacion
        }
      	return false;
    }
	
	void print(){
	    Pair *temp = this->first;
	    while(temp!=nullptr){
	        cout<<"Key: "<<temp->key<<" | Value: "<<temp->value<<endl;
	        temp = temp->next;
	    }
	}
	
	string at(int key){ //retorna el valor 
	    Pair *temp=this->first;
	    while(temp!=nullptr){
	        if(temp->key == key){
	            return temp->value;
	        }
	        temp = temp->next;
	    }
	    return "no hay elementos";
	}
	bool empty(){
	    if(this->first==nullptr){
	        return true;
	    }
	    else{
	        return false;
	    }
	}
	
	bool remove_especific(string value){//remover un elemento por su valor
	    if(this->first == nullptr){
	        return false;
	    }
	    
	    if(this->first->value == value){
	        this->first = this->first->next;
	        count--;
	        return true;
	    }
	    
	    for(Pair *temp = this-> first; temp->next != nullptr; temp= temp->next){
	        if(temp->next->value == value){
	            temp->next = temp->next->next;
	            return true;
	        }
	    }
	    return false;
	}
	
	bool remove_key(int key){//remover un elemento por su key
	    if(this->first == nullptr){
	        return false;
	    }
	    
	    if(this->first->key == key){
	        this->first = this->first->next;
	        count--;
	        return true;
	    }
	    
	    for(Pair *temp = this-> first; temp->next != nullptr; temp= temp->next){
	        if(temp->next->key == key){
	            temp->next = temp->next->next;
	            return true;
	        }
	    }
	    return false;
	}
};

int main(){
    
    Map map;
    cout<<map.empty()<<endl;
    map.add(1,"nombre1");
    
    map.add(2,"nombre2");
    map.add(3,"nombre3");

    cout<<map.at(1)<<endl;
    map.remove_especific("nombre2");
    
    map.remove_key(1);
    
    cout<<map.empty()<<endl;
    
    map.print();
    return 0;
}

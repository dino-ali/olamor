/*
1. Implementar el juego del 2048/pero hasta 128 con una sola estructura (Pilas)
 
2. Dado un arbol binario, determinar si dos numeros a y b son nodos primos, si existe

*/


 //------------------------------------------------- CON LISTAS --------------------------------------------------

#include<iostream>
#include<string>
#include <math.h> 

using namespace std;

class Nodo{
  
    int dato;
    Nodo* pointer;
  
public:
  
    Nodo(){
        dato = 0;
        pointer = NULL;
    }
    
    ~Nodo(){
    }
    
    Nodo(int d){
        dato = d;
        pointer = NULL;
    }
    
    int getDato(){
        return dato;
    }
    
    void setDato(int d){
        dato = d;
    }
    
    Nodo* getNext(){
        return pointer;
    }
    
    void setNext(Nodo* p){
        pointer = p;
    }
 
    string to_string() {
        string a(std::to_string(getDato()));
		return a;
    }
    
      
    friend std::ostream& operator<<(std::ostream& os, Nodo& b) {
    	return os << b.to_string();
    }
  
};

class Lista{
    
    Nodo* ptr;
    int size;

public:  

    Lista(){
        ptr = NULL;
        size = 0;
    }

    ~Lista(){

    }
    
    void push_back(int d){
        
        if(size == 0){
            ptr = new Nodo(d);
            size++;
        }else{
            Nodo* t = ptr;
            while(t->getNext() != NULL){
                t = t->getNext();    
            }
            t->setNext(new Nodo(d));
            size++;
        }
        
    }
    
    int getSize(){
        return size;
    }
    
    void setSize(int i){
        size=i;
    }
    
    void setPtr(Nodo* n){
        ptr= n;
    }
    
    Nodo* getPtr(){
        return ptr;
    }
    
    void print(){
        if(size == 0){
            cout<<"La lista estÃ¡ vacia"<<endl;
        }else{
            Nodo* t = ptr;
            do{
                //cout<<"("<<(*t).getDato()<<"), ";
                cout<<(*t)<< ", ";
                t = t->getNext();
                
            }while(t != NULL);
            cout<<endl;
        }
    }
    
    Nodo* get(int i){
        if(i < size && i>=0){
            Nodo* n = ptr;
            for(int x = 0; x<i;x++){
                n = n->getNext();
            }
            return n;
        }else{
            //throw invalid_argument("La posicion no existe");
            if(size == 0){
                cout<<"La lista estÃ¡ vacia";
            }else{
                cout<<"La posicion no existe";
            }
            return NULL;
        }
        
    }
    
    void insert(int p, int pos){
        if(pos >= 0 && pos <= size){
            //Si la lista estÃ¡ vacia o si se quiere insertar el nodo al final
            //se usa el mÃ©todo push_back
            if(size == 0 || pos == size){ 
                push_back(p);
            }else{
                Nodo* n = new Nodo(p);
                //Si se quiere insertar el nodo de primero en la lista
                if(pos == 0){
                    n->setNext(ptr);
                    ptr = n;
                }else{
                    Nodo* t = get(pos-1);
                    n->setNext(t->getNext());
                    t->setNext(n);
                }
                size++;
            }
        }else{
            throw invalid_argument("La posicion no existe");
        }
        
    }
    
    void remove(int pos){
        if(pos >= 0 && pos < size){
            if(pos == size-1){ 
                Nodo* n = get(pos);
                Nodo* t = get(pos-1);
                t->setNext(NULL);
                delete n;
                size--;
                
            }else if (pos == 0){
                Nodo* n = get(pos);
                Nodo* t = get(pos+1);
                ptr = t;
                delete n;                
                size--;
            } else{
                Nodo* n = get(pos);
                Nodo* t = get(pos-1);
                t->setNext(n->getNext());
                delete n;
                size--;                
            }
        }else{
            throw invalid_argument("La posicion no existe");
        }       
    }
    
    void invertir_lista(){
        if(size == 0){
            cout<<"La lista estÃ¡ vaciaa"<<endl;
        }else{
            Nodo* nNext;
            Nodo* ptr2 = NULL;
            Nodo* d = ptr;
            while(d != NULL){
                nNext = d -> getNext();
                d -> setNext(ptr2);
                ptr2 = d;
                d = nNext;
            }
            ptr = ptr2;
        }
    } 
    
    void pop(){
        remove(size-1);
    }

    void inPila(int x){
        push_back(x);
    }
    
    int canPila(){
        Nodo* x = get(size-1); 
        int y = x->getDato();
        pop();
        return y;
    }

    void inCola(int x){
        push_back(x);
    }
    
    int canCola(){
        Nodo* x = get(0); 
        int y = x->getDato();
        remove(0);
        return y;
    }
};
    



int main()
{
   
    Lista l = Lista();
    int x,y,d, a, b;
    a = l.getSize();
    l.push_back(32);
    b = l.get(a)->getDato();
    while (b < 128){
        cin>> x;
        y = l.getSize();
        d = l.get(y-1)->getDato();
        l.print();
        while (x == d){
            l.canPila();
        y = l.getSize();
        d = l.get(y-1)->getDato();
            x = x + x;
        }
        l.push_back(x);
        b = l.get(y-1)->getDato();
    }
    l.print();
    
    return 0;
}
 
 


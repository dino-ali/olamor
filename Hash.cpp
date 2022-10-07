#include <iostream>       
#include <stack>        
#include <vector>
#include <tuple>

using std::stoi;
using namespace std;

template <typename T, typename T2>

class Tupla{
    T key;
    T2 dato;

public:

    //Constructores
    Tupla(T x, T2 y) {
        key = x;
        dato = y;
  
    }

    T getKey() {
        return key;
    }

    T2 getDato() {
        return dato;
    }
    
    void get_tp(){
        tuple<T, T2> t;
        t = make_tuple(key, dato);
        cout << "(" << get<0>(t) << ", " << get<1>(t) << ")";
    }
};

template <typename T, typename T2>
class Mapas{
    vector<Tupla<T, T2>> x;
    int size;

public:

    //Constructores
    Mapas(vector<Tupla<T,T2>> z){
        x = z;
        size = x.size();
    }
    
    void add(T z, T2 p){
        Tupla<T,T2> t = Tupla<T,T2>(z, p);
        x.push_back(t);
        size++;
    }

    void print(){
        for (int i = 0; i < size; i++){
            x[i].get_tp();
            cout << ", ";
        }
        cout << endl;
    }

    Tupla<T,T2> find(T k){
        for (int i = 0; i < size; i++){
            if (x[i].getKey() == k){
                return x[i]; 
            }
        }
        return x[0];
    }
    
    char get(T k){
        char x = find(k).getDato();
        return x;
    }
    
    bool haskey(T k){
        for (int i = 0; i < size; i++){
            if (x[i].getKey() == k){
                return true; 
            }
        }
        return false;
    }
};


int Hash(string clave){
    string a = clave;
    string e = "";
    int c = 0, f = 0;
    
    for (int i = 0; i < a.length(); i++){
        c += a.at(i);
    }
    
    c = c*c;
    
    string b = to_string(c);
    int d = b.length()/2;
    e += b[d-1];
    e += b[d];
    f = stoi(e);    
    return f;
}

int main()
{
    string a = "David";
    int b = Hash(a);
    string c = "Lissa";
    int d = Hash(c);
    
    
    vector<Tupla<string,int>> x;
    Mapas<string,int> m = Mapas<string,int>(x);
    
    m.add(a,b);
    m.add(c,d);
    m.print();


    return 0;
}


//--------------------------------------------------------- HASH CON MULTILISTA

#include<iostream>
#include <math.h> 
#include <stdlib.h>
#include <random>
#include <iomanip>

using std::setprecision;
using namespace std;

class Tweet{
  
  string dato;
  Tweet* pointer;
  
public:
  
  Tweet(){
      dato = "";
      pointer = NULL;
  }
  
  ~Tweet(){
  }
  
  Tweet(string d){
      dato = d;
      pointer = NULL;
  }
    
  string getDato(){
      return dato;
  }
  
  void setDato(string d){
      dato = d;
  }
  
  Tweet* getNext(){
      return pointer;
  }
  
  void setNext(Tweet* p){
      pointer = p;
  }
    
    string to_string() {
		return getDato();
	}


	friend std::ostream& operator<<(std::ostream& os, Tweet& b) {
		return os << b.to_string();
	}
    
};

class Nodo{
  
    int dato;
    Nodo* pointer;
    Tweet* tweets;
    int size;
    
public:
    
    Nodo(){
        dato = 0;
        pointer = NULL;
        tweets = NULL;
        size = 0;
    }
    
    ~Nodo(){
        Tweet* t = tweets;
        Tweet* tt;
        while(t != NULL){
          tt = t;
          t = t->getNext();
          delete tt;
        }
    }
    
    Nodo(int d){
        dato = d;
        pointer = NULL;
        tweets = NULL;
        size = 0;
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
    
    void push_back(string d){
        
        if(size == 0){
            tweets = new Tweet(d);
            size++;
        }else{
            Tweet* t = tweets;
            while(t->getNext() != NULL){
                t = t->getNext();    
            }
            t->setNext(new Tweet(d));
            size++;
        }
        
    }
    
    Tweet* get(int i){
        if(i < size && i>=0){
            Tweet* n = tweets;
            for(int x = 0; x<i;x++){
                n = n->getNext();
            }
            return n;
        }else{
            //throw invalid_argument("La posicion no existe");
            if(size == 0){
                cout<<"La lista de tweets está vacía";
            }else{
                cout<<"La posicion no existe";
            }
            return NULL;
        }
        
    }

    
    string to_string() {
        string s = std::to_string(getDato());
        s.append(" >> ");
        Tweet* t = tweets;
        while(t != NULL){
            s.append(t->getDato());
            s.append(" > ");
            t = t->getNext();
        }
        s.append("\n");
		return s;
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
        Nodo* t = ptr;
        Nodo* n;
        while(t->getNext() != NULL){
            n = t;
            t = t->getNext();    
            delete n;
        }
        delete t;
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
    
    void print(){
        if(size == 0){
            cout<<"La lista está vacía"<<endl;
        }else{
            Nodo* t = ptr;
            do{
                //cout<<"("<<(*t).getDato()<<"), ";
                cout<<(*t);
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
                cout<<"La lista está vacía";
            }else{
                cout<<"La posicion no existe";
            }
            return NULL;
        }
        
    }
    
    void insert(int p, int pos){
        if(pos >= 0 && pos <= size){
            //Si la lista está vacía o si se quiere insertar el nodo al final
            //se usa el método push_back
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
            //throw invalid_argument("La posicion no existe");
            cout<<"La posicion no existe"<<endl;
            
        }
        
    }
    
    void remove(int pos){
        
        if((pos >= 0 && pos <= size) && size > 0){
            //Si la lista está vacía o si se quiere insertar el nodo al final
            //se usa el método push_back
            if(pos == 0){ 
                Nodo* t = ptr;
                ptr = ptr->getNext();
                delete t;
            }else{
                Nodo* t = get(pos-1);
                Nodo* t2 = t->getNext();
                
                t->setNext(t2->getNext());
                delete t2;
            }
            size--;
        }else{
            //throw invalid_argument("La posicion no existe o la lista está vacía");
            cout<<"La posicion no existe o la lista está vacía"<<endl;
        }
        
    }
    
};

/*
int Hash(string clave){
    string a = clave;
    string e = "";
    int c = 0, f = 0;
    
    for (int i = 0; i < a.length(); i++){
        c += a.at(i);
    }
    
    c = c*c;
    
    string b = to_string(c);
    int d = b.length()/2;
    e += b[d-1];
    f = stoi(e);    
    return f;
}
*/

int Hash(string clave){
    string a = clave;
    string e = "";
    float c = 0;
    int f = 0;

    float h = 0 + (float)(rand()) / ((float)(RAND_MAX));
    h = setprecision(4) 

    
    for (int i = 0; i < a.length(); i++){
        c += a.at(i);
    }
    
    c = c*h;
    c = c%1;
    c = c*11;
    f = round(c);
        
    string b = to_string(c);
    int d = b.length()/2;
    e += b[d-1];
    f = stoi(e);    
    return f;
}

int main()
{
    srand (time(nullptr));

    string a = "David";
    int b = Hash(a);
    string c = "Lissa";
    int d = Hash(c); 
    string e = "Carlos";
    int f = Hash(e);
    string g = "Pedro";
    int h= Hash(g); 
    
    Lista l = Lista();
    
    for(int i = 0; i<11; i++){
       l.push_back(i);
    }
    
    l.get(b)->push_back(a);
    l.get(d)->push_back(c);
    l.get(f)->push_back(e);
    l.get(h)->push_back(g);
    
    l.print();
    
    return 0;
}


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

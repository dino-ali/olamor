#include <iostream>       
#include <stack>        
#include <vector>
#include <tuple>

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

/*
Tupla busqueda_binaria(vector<Tupla> & arr, int n, int x){
    int ini = 0;
    int fin = n-1;
    while(ini <= fin){
        int i = (fin+ini)/2;
        if(arr[i].getKey() == x){
            cout << i <<endl;
        }
        else{
            if(arr[i].getKey()>x){
                fin = i-1;
            }
            else{
                ini = i+1;
            }
        }    
    }
}
void bubble_sort (vector<Tupla> & arr){
    int a;
    for(int i =0; i<size; i++){
        for(int j=0; j<size; j++){
            if(arr[j].getKey()>arr[j+1].getKey()){
                a=arr[j].getKey();
                arr[j].getKey()=arr[j+1].getKey();
                arr[j+1].getKey()=a;
            }
        }
        for(int j=size-1; j>0; j--){
            if(arr[j]<arr[j-1]){
                a=arr[j].getKey();
                arr[j].getKey()=arr[j-1];
                arr[j-1].getKey()=a;
            }
        }
    }
}
*/

int main ()
{   
    vector<Tupla<int,char>> x;
    Mapas<int,char> m = Mapas<int,char>(x);
    
    m.add(7,'k');
    m.add(2,'a');
    m.add(5,'b');
    m.print();
    cout << m.get(7) << endl;;
    cout << m.haskey(4);

    return 0;
}

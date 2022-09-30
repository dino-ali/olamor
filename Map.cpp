#include <iostream>       
#include <stack>        
#include <vector>
#include <tuple>

using namespace std;

//template<typename T, typename T1>

class Tupla{
    int key;
    char dato;

public:

    //Constructores
    Tupla(int x, char y) {
        key = x;
        dato = y;
  
    }

    int getKey() {
        return key;
    }

    char getDato() {
        return dato;
    }
    
    void get_tp(){
        tuple<int, char> t;
        t = make_tuple(key, dato);
        cout << "(" << get<0>(t) << ", " << get<1>(t) << ")";
    }
};


class Mapas{
    vector<Tupla> x;
    int size;

public:

    //Constructores
    Mapas(vector<Tupla> z){
        x = z;
        size = x.size();
    }
    
    void add(int z, char p){
        Tupla t = Tupla(z, p);
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

    Tupla find(int k){
        for (int i = 0; i < size; i++){
            if (x[i].getKey() == k){
                return x[i]; 
            }
        }
        return x[0];
    }
    
    char get(int k){
        char x = find(k).getDato();
        return x;
    }
    
    bool haskey(int k){
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
    vector<Tupla> x;
    Mapas m = Mapas(x);
    
    m.add(7,'k');
    m.add(2,'a');
    m.add(5,'b');
    cout << m.get(7) << endl;;
    cout << m.haskey(4);

    return 0;
}



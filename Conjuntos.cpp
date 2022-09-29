#include <iostream>       
#include <stack>        
#include <vector>

using namespace std;

class Conjunto{

    vector<int> x;
    int size;

public:

    //Constructores
    Conjunto(vector<int> z) {
        x = z;
        size = x.size();
    }
    
    void add(int z){
        bool a = true;
        for (int i = 0; i < size; i++){
            if (x[i] == z){
                a = false;    
            }
        }
        if (a){
            x.push_back(z);
            size++;
        }
    }

    vector<int> getVector(){
        return x;    
    }
    
    int getSize(){
        return size;    
    }
    
    void corrimiento_der(int i){
        for(int j = size; j>i; j--){
            x[j] = x[j-1];
        }
    }
    
    void corrimiento_izq(int i){
        for(int j = i; j<size-1; j++){
            x[j] = x[j+1];
        }
    }
    
    
    void remove(int i){
        if(i < size){
            corrimiento_izq(i);
            size--;
        }else{
            cout<<"Error en la posición - remove"<<endl;
        }
    }
    
    void print(){
        for (int i = 0; i < size; i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }

    bool empty(){
        if (x.empty()){
            return 1;
        }else{
            return 0;
        }
    }
    

    bool contains(int j){
        bool a = false;
        for (int i = 0; i < size; i++){
            if (x[i] == j){
                a = true;
                return a;
            }
        }
        return a;
    }
    
};

void unioncj(Conjunto a, Conjunto b){
    vector<int> x;
    Conjunto c = Conjunto(x);
    for (int i = 0; i < a.getSize(); i++){
        c.add(a.getVector()[i]);    
    }
    for (int i = 0; i < b.getSize(); i++){
        c.add(b.getVector()[i]);    
    }
    
    c.print();
}

void interseccion(Conjunto a, Conjunto b){
    vector<int> x;
    int mayor = 0, menor = 0;
    if (a.getSize() > b.getSize()){
        mayor = a.getSize(); 
        menor = b.getSize();
        for (int i = 0; i < menor; i++){
            for (int j = 0; j < mayor; j++){
                if (a.getVector()[j] == b.getVector()[i]){
                    x.push_back(a.getVector()[j]);    
                }
            }
        }
    } else{
        mayor = b.getSize();
        menor = a.getSize();
        for (int i = 0; i < menor; i++){
            for (int j = 0; j < mayor; j++){
                if (a.getVector()[j] == b.getVector()[i]){
                    x.push_back(a.getVector()[j]);    
                }
            }
        }
    }
    
    for (int i = 0; i < x.size(); i++){
        cout << x[i] << " ";
    }
}

int main ()
{   
    vector<int> x;
    vector<int> y;
    
    Conjunto c = Conjunto(x);
    Conjunto d = Conjunto(y);    
    
    for (int i = 0; i < 10; i++){
        c.add(i);   
    }
    
    for (int i = 8; i < 16; i++){
        d.add(i);   
    }
    
    c.print();
    d.print();
    unioncj(c,d);
    
    

    return 0;
}

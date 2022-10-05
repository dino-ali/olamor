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
    
    void unioncj(Conjunto b){
        for (int i = 0; i < size; i++){
            add(x[i]);    
        }
        for (int i = 0; i < b.getSize(); i++){
            add(b.getVector()[i]);    
        }
        print();
    }
    
    void diferencia(Conjunto b){
        vector<int> y;
        for (int i = 0; i < size; i++){
            bool c = true;
            for (int j = 0; j < b.getSize(); j++){
                if (x[i] == b.getVector()[j]){
                    c = false;
                }
            }
            if (c == true){
                y.push_back(x[i]);    
            } 
        }
        
        for (int i = 0; i < y.size(); i++){
            cout << y[i] << " ";
        }
    }    
    

    void interseccion(Conjunto b){
        vector<int> y;
        for (int i = 0; i < b.getSize(); i++){
            for (int j = 0; j < size; j++){
                if (x[j] == b.getVector()[i]){
                    y.push_back(x[j]);    
                }
            }
        }
    
        for (int i = 0; i < y.size(); i++){
            cout << y[i] << " ";
        }
    }
    
    
};

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
    d.interseccion(c);
    
    

    return 0;
}

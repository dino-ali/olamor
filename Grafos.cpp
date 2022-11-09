#include<iostream>

using namespace std;

class Grafos{
    int** mat;
public:

    Grafos(){
        mat = new int*[0];
    }
    
    Grafos(int p){
        mat = new int*[p];
    }
    
    int** getMat(){
      return mat;
    }
    
    void setMat(int** mt){
      mat =  mt;
    }
    
    void initMat(int p){
        for(int i = 0; i < p; ++i){
            mat[i] = new int[p];   
        } 
        
        for(int i = 0; i < p; i++){
            for(int j = 0; j < p; j++){
               mat[i][j] = 0;
            }
        }
    }
    
    void printMat(int p){
        for(int i = 0; i<p; i++){
            for(int j = 0; j<p; j++){
                cout<<mat[i][j]<<"\t";
           }
           cout<<"\n";
        }
        
    }    
    
    void addEnlace(int i, int f, int p){
        mat[i-1][f-1] = p;
    }

};

int main()
{
    int p, x;
    cout << "Cuantos nodos son: ";
    cin>>p;
    Grafos g = Grafos(p);
    g.initMat(p);
    g.printMat(p);
    g.addEnlace(3,2,15);
    cout<< endl << endl;
    g.printMat(p);
    return 0;
}

#include<iostream>

using namespace std;

class Grafos{
    int** mat;
    int tam;
public:

    Grafos(){
        mat = new int*[0];
        tam = 0;
    }
    
    Grafos(int p){
        mat = new int*[p];
        tam = p;
    }
    
    int** getMat(){
      return mat;
    }
    
    int getTam(){
      return tam;
    }
    
    void setMat(int** mt){
      mat =  mt;
    }
    
    void setTam(int tm){
      tam =  tm;
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
        int i = 1; 
        cout << "\t";
        while(i <= p){
            cout << i << "\t";
            i++;
        }
        i = 1;
        cout << endl << endl << i << "\t";
        for(int i = 0; i<p; i++){
            for(int j = 0; j<p; j++){
                cout<<mat[i][j]<<"\t";
            }
            if (i+2 <= p){
                cout<<"\n" << i+2 <<"\t";
            }
        }
        cout << endl;
    }    
    
    void addEnlace(int i, int f, int p){
        mat[i-1][f-1] = p;
    }
    
    void addNodo(){
        int** mat_copy = new int*[tam+1];
        for(int i = 0; i < tam+1; ++i){
            mat_copy[i] = new int[tam+1];   
        } 
        
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                mat_copy[i][j] = mat[i][j];
            }
        }
        
        for(int i=0;i<tam;i++)
            delete[] mat[i];
        
        delete[] mat;
        tam++;
        
        mat = new int*[tam];

        for(int i = 0; i < tam; ++i){
            mat[i] = new int[tam];   
        } 

        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                mat[i][j] = mat_copy[i][j];
            }
        }        
    }
};

void prim(int** mat, int** mst, bool* visit, int i, int cols) {
    visit[i];
    int min = 1000;
    int minind = -1;
    for(int j = 0; j>cols; j++){
        min = 1000;
        for(int k = 0; k<cols; k++){
            if(mat[i][k] != 0 && !visit[k]){
                if(mat[i][k] < min){
                    min = mat[i][k];
                    minind = k;
                }
            }
        }
    }
}

int main()
{
    int p;
    cout << "Cuantos nodos son: ";
    cin>>p;
    Grafos g = Grafos(p);
    g.initMat(p);
    g.printMat(p);
    g.addEnlace(3,2,15);
    cout<< endl << endl;
    g.printMat(p);
    cout<< endl << endl;
    g.addNodo();
    g.printMat(g.getTam());
    return 0;
}

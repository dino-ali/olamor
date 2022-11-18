//3.
#include<iostream>
#include<vector>

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

//**************************************************************
    
    int mayor_grado(){
        int grado, mayor = 0;
        vector <int> v;
        for(int i = 0; i < tam; i++){
            grado = 0;
            for(int j = 0; j < tam; j++){
                if (mat[i][j] != 0){
                    grado++;
                }
            }
            v.push_back(grado);
        }
        for (int i = 0; i < v.size(); i++){
            cout << v[i] << ", ";
            if (v[i] > mayor and v[i] > 0){
                mayor = v[i];
            }
        }
        cout <<  endl;
        for(int i=0; i<v.size(); i++){
            if (mayor==v[i])
                return i+1;
            
        }
    }

//**************************************************************

    int menor_grado(){
        int grado, menor = 100000;
        vector <int> v;
        for(int i = 0; i < tam; i++){
            grado = 0;
            for(int j = 0; j < tam; j++){
                if (mat[i][j] != 0){
                    grado++;
                }
            }
            v.push_back(grado);
        }
        
        for (int i = 0; i < v.size(); i++){
            cout << v[i] << ", ";
            if (v[i] < menor and v[i] > 0){
                menor = v[i];
            }
        }
        cout <<  endl;
        for(int i=0; i<v.size(); i++){
            if (menor==v[i])
                return i+1;
            
        }
    }

//**************************************************************
    
    void print_nodos_k(int a, int k){
        vector<int> v;
        int c = 0;
        if (k == 0){
            for (int i = 0; i < v.size(); i++){
                cout << v[i] << ", ";
            }
        }
        for(int i = 0; i < tam; i++){
            if(mat[a-1][i] != 0){
                c++;
                if (c == k){
                    v.push_back(i+1);
                }
                else{
                    print_nodos_k(i, k-1);
                }
            }
        }
    }   
};


int main()
{
    int p;
    cout << "Cuantos nodos son: ";
    cin>>p;
    Grafos g = Grafos(p);
    g.initMat(p);
    g.addEnlace(5,4,1);
    g.addEnlace(4,5,1);
    g.addEnlace(4,1,1);
    g.addEnlace(1,4,1);
    g.addEnlace(4,3,1);
    g.addEnlace(3,4,1);
    g.addEnlace(1,2,1);
    g.addEnlace(2,1,1);
    g.addEnlace(2,3,1);
    g.addEnlace(3,2,1);
    cout<< endl << endl;
    g.printMat(p);
    cout<<endl;
    cout << "Nodo mayor grado: "<< g.mayor_grado() << endl;
    cout << "Nodo menor grado: "<< g.menor_grado() << endl;
    g.print_nodos_k(3,1);
    return 0;
}

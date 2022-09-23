#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void bubble_sort (int *v, int m){
    int a;
    for(int i =0; i<m; i++){
        for(int j=0; j<m; j++){
            if(v[j]>v[j+1]){
                a=v[j];
                v[j]=v[j+1];
                v[j+1]=a;
            }
        }
        for(int j=m-1; j>0; j--){
            if(v[j]<v[j-1]){
                a=v[j];
                v[j]=v[j-1];
                v[j-1]=a;
            }
        }
    }
}
void select_sort(int *v, int m){
    int minimo=100000000, maximo=-10000000;
    int a,b;
    for(int i=0; i< m; i++){
        for( int j=i; j<m; j++){
            if( v[j]< minimo){
                minimo=v[j];
                a=j;
            }
        }
        b=v[i];
        v[i]=minimo;
        v[a]=b;
        minimo=100000000;
       for(int j=m-1-i; j>=0; j--){
            if( v[j]> maximo){
                maximo=v[j];
                a=j;
            }
        }
        b=v[m-i-1];
        v[m-i-1]=maximo;
        v[a]=b;
        maximo=-10000000;
    }
}
void max_y_min(int *v, int m){
    int a,b;
    select_sort(v, m);
    a=v[m-1];
    b=v[0];
    cout<<"El item minimo para el conjunto es: "<<b-1<<endl;
    cout<<"El item máximo para el conjunto es: "<<a+1<<endl;
}
void media_y_mediana(int *v, int m){
    double media, mediana, suma=0;
    select_sort(v, m);
    //media
    for(int i=0; i<m; i++){
        suma+=v[i];
    }
    media=suma/m;
    //mediana
    if(m%2==0){
        mediana=(v[m/2] + v[(m/2)-1] )/2;
    }else{
        mediana=v[(m)/2];
    }
    cout<<"La media es: "<<media<<endl;
    cout<<"La mediana es: "<<mediana<<endl;
}

void print(int *v, int m){
    for(int i=0; i<m; i++){  
        cout << v[i] << " ";  
    }     
}

int main() {
   
    int m = 15;
    int b[m];

    for(int i=0; i<m; i++){  
        int x = rand()%15;
        b[i] = x;  
    } 
   
    print(b,m); 
       
    cout << endl;
    
    media_y_mediana(b, m);

    print(b,m); 
   
    return 0;
}

#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Vector{
    
    int* v;
    int size;
    int capacity;
    
public:

    Vector(){
        v = new int[10];
        size = 0;
        capacity = 10;
    }
    
    Vector(int cap){
        v = new int[cap];
        size = 0;
        capacity = cap;
    }
    
    ~Vector(){
        delete[] v;
    }
    
    int get(int i){
        if(i < size){
            return v[i];
        }else{
            cout<<"Error en la posición - get"<<endl;
        }
        return -999;
    }
    
    void set(int i, int x){
        if(i < size){
            v[i] = x;
        }else{
            cout<<"Error en la posición - set"<<endl;
        }
    }
    
    void push_back(int x){
        if(size == capacity){
            //Aumentar el vector
            increase_capacity();
        }
        v[size] = x;
        size++;
    }
    
    void increase_capacity(){
        int* old_v = v;
        v = new int(2*capacity);
        for(int i=0; i<capacity; i++){
            v[i] = old_v[i];
        }
        delete[] old_v;
        capacity = capacity * 2;
    }
    
    void print(){
        for(int i=0; i<size; i++){
            cout<<v[i]<<"\t";
        }
        cout<<endl;
    }
    
    void getStats(){
        cout<<"Size: "<<size<<" Capacity: "<<capacity<<endl;
    }
    
    /*Se corren a la derecha los elementos a partir del elemento i, para crear espacio en esa ubicación. 
       Se asume que hay espacio en el vector.*/
    void corrimiento_der(int i){
        for(int j = size; j>i; j--){
            v[j] = v[j-1];
        }
    }
    
    /*Se corren a la izquierda los elementos sobre el elemento i, para eliminar el espacio en esa ubicación. 
       Se asume que hay espacio en el vector.*/
    void corrimiento_izq(int i){
        for(int j = i; j<size-1; j++){
            v[j] = v[j+1];
        }
    }
    
    void insert(int i, int x){
        if(i < size){
            cout<<"Entre 1"<<endl;
            if(size == capacity){
                //Aumentar el vector
                cout<<"Entre 2"<<endl;
                increase_capacity();
            }
            corrimiento_der(i);
            size++;
            v[i] = x;
        }else{
            cout<<"Error en la posición - insert"<<endl;
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
    
//------------------------------------------------------------------------------------------------------------
     
    int busqueda_secuencial(int n, int x){
        double start = double(clock());
        for(int i = 0; i<n; i++){
            if(v[i] == x){
                cout << i <<endl;
            }
        }
        double finish = double(clock());
        double elapsed = finish - start;
        return elapsed;
    }    
    
    int busqueda_indexada(int n, int k){   
        int elements[20], indices[20], temp, i, set = 0;
        int j = 0, ind = 0, start, end;
        for (i = 0; i < n; i += 3) {
     
            // Storing element
            elements[ind] = v[i];
     
            // Storing the index
            indices[ind] = i;
            ind++;
        }
        if (k < elements[0]) {
            return -1;
            exit(0);
        } else{
            for (i = 1; i <= ind; i++){
                if (k <= elements[i]) {
                    start = indices[i - 1];
                    end = indices[i];
                    set = 1;
                    break;
                }
            }
        }
        if (set == 0) {
            start = indices[i - 1];
            end = n;
        }
        for (i = start; i <= end; i++) {
            if (k == v[i]) {
                j = 1;
                break;
            }
        }
        if (j == 1){
            return i;
        }else{
            return -1;
        }
    }

    int busqueda_binaria(int n, int x){
        double start = double(clock());
        int ini = 0;
        int fin = n-1;
        while(ini <= fin){
            int i = (fin+ini)/2;
            if(v[i] == x){
                cout << i <<endl;
            }
            else{
                if(v[i]>x){
                    fin = i-1;
                }
                else{
                    ini = i+1;
                }
            }    
        }
        double finish = double(clock());
        double elapsed = finish - start;
        return elapsed;
        
    }
    
    int busqueda_terciaria(int n, int x){
        int ini = 0;
        int fin = n-1;
        while(ini <= fin){
            int i = (fin+(2*ini))/3;
            int i2 = ((2*fin)+ini)/3;
            if(v[i] == x){
                return i;
            }else if(v[i2] == x){
                return i2;
            }
            else{
                if(v[i]>x){
                    fin = i-1;
                }else if(v[i2]<x){
                    ini = i2+1;
                }
                else{
                    ini = i+1;
                    fin = i2-1;
                }
            }    
        }
        return -1;
        
    }

    
//-----------------------------------------------------------------------------------------
    
/*
    void insert_sort(){
        int x, f;
        for (int j = 1; j<size;j++){
            f = j;
            for(int i= f-1; i >= 0; i--){
                if (v[f] <= v[i]){
                    x = v[f];
                    v[f] = v[i];
                    v[i] = x;
                    f--;
                }
            }
        }        
    }
    
    void bubble_sort_Invertido(){
        int x;
        for (int j = 0; j<size;j++){
            for(int i= 0; i<size-1; i++){
                if (v[i] <= v[i+1]){
                    x = v[i];
                    v[i] = v[i+1];
                    v[i+1] = x;
                }
            }
        }        
    }    
   
    void bubble_sort(){
        int x, k = 0;
        for (int j = 0; j<size;j++){
            for(int i= 0; i<size-1; i++){
                if (v[i+1] <= v[i]){
                    x = v[i];
                    v[i] = v[i+1];
                    v[i+1] = x;
                }
            }
        }        
    }   
    
    void select_sort(){
        int minimo = 1000;
        int x, k;
        for (int j = 0; j<size;j++){
            for(int i = j; i<size; i++){
                if (v[i] <= minimo ){
                    minimo = v[i];
                    x = i;
                }
            }
            k = v[j];
            v[j] = minimo; 
            v[x] = k;
            minimo = 1000; 
        }
    } 
*/ 

    
    void insert_sort(){
        double start = double(clock());
        int x, f, k = 0;
        for (int j = 1; j<size;j++){
            f = j;
            k = 0;
            for(int i= f-1; i >= 0; i--){
                if (v[f] <= v[i]){
                    x = v[f];
                    v[f] = v[i];
                    v[i] = x;
                    k++;
                    f--;
                }
            }
            //print();
            //cout << k << " intercambios"<<endl<<endl;
        }    
        double finish = double(clock());
        double elapsed = finish - start;
        cout << elapsed;
    }
    
    /*void bubble_sort(){
        double start = double(clock());
        int x, p, y = 1, k = 0;
        while (k < y){
            k++;
            p = 0;
            for(int i= 0; i<size-1; i++){
                if (v[i+1] <= v[i]){
                    x = v[i];
                    v[i] = v[i+1];
                    v[i+1] = x;
                    p++;
                }
            }
            if (p > 0){
                y++;   
            }
            //print();
        }    
        //cout<<"Numero de repeticiones: "<<k<<endl;
        double finish = double(clock());
        double elapsed = finish - start;
        cout << elapsed;
    }  

    void select_sort(){
        double start = double(clock());
        int minimo = 1000;
        int x, k, p = true, t = 0;
        while (p){
            for(int i = t; i<size; i++){
                if (v[i] <= minimo ){
                    minimo = v[i];
                    x = i;
                }
            }
            k = v[t];
            v[t] = minimo; 
            v[x] = k;
            if(v[size-1] > v[size-2] and v[size-1] > v[size-3] and v[size-2] > v[size-3]){
                p = false;
            }
            minimo = 1000; 
            t++;
            //print();
        }
        double finish = double(clock());
        double elapsed = finish - start;
        cout << elapsed;
    }  */

    void shell_sort(){
        double start = double(clock());
        for (int gap = size/2; gap > 0; gap /= 2){
            for (int i = gap; i < size; i++){
                int temp = v[i];
                int j;            
                for (j = i; j >= gap && v[j - gap] > temp; j -= gap){
                    v[j] = v[j - gap];
                }
                v[j] = temp;
            }
            //print();
        }
        double finish = double(clock());
        double elapsed = finish - start;
        cout << "Tiempo de ejecucion: " <<elapsed;
    }
    
    bool checkrep(int n, int x)
    {
        for(int i=0; i<x; i++)
            if(n == v[i])
                return true;
        return false;
    }
    
    void bubble_sort (){
        int a;
        for(int i =0; i<size; i++){
            for(int j=0; j<size; j++){
                if(v[j]>v[j+1]){
                    a=v[j];
                    v[j]=v[j+1];
                    v[j+1]=a;
                }
            }
            for(int j=size-1; j>0; j--){
                if(v[j]<v[j-1]){
                    a=v[j];
                    v[j]=v[j-1];
                    v[j-1]=a;
                }
            }
        }
    }
    void select_sort(){
        int minimo=100000000, maximo=-10000000;
        int a,b;
        for(int i=0; i< size; i++){
            for( int j=i; j<size; j++){
                if( v[j]< minimo){
                    minimo=v[j];
                    a=j;
                }
            }
            b=v[i];
            v[i]=minimo;
            v[a]=b;
            minimo=100000000;
           for(int j=size-1-i; j>=0; j--){
                if( v[j]> maximo){
                    maximo=v[j];
                    a=j;
                }
            }
            b=v[size-i-1];
            v[size-i-1]=maximo;
            v[a]=b;
            maximo=-10000000;
        }
    }
    void max_y_min(){
        int a,b;
        select_sort();
        a=v[size-1];
        b=v[0];
        cout<<"El item minimo para el conjunto es: "<<b-1<<endl;
        cout<<"El item máximo para el conjunto es: "<<a+1<<endl;
    }
    void media_y_mediana(){
        double media, mediana, suma=0;
        //media
        for(int i=0; i<size; i++){
            suma+=v[i];
        }
        media=suma/size;
        //mediana
        if(size%2==0){
            mediana=(v[size/2] + v[(size/2)-1] )/2;
        }else{
            mediana=v[(size-1)/2];
        }
        cout<<"La media es: "<<media<<endl;
        cout<<"La mediana es: "<<mediana<<endl;
    }

    int particion(int ini, int fin){
        int pivote = v[fin];
        int i = ini-1;
        int temp;
        for (ini; ini <= fin; ini++){
            if (v[ini] < pivote){
                i++;
                temp = v[i];
                v[i] = v[ini];
                v[ini] = temp;
            }

        }
        i++;
        if (v[i] > pivote){
            temp = v[i];
            v[i] = v[fin];
            v[fin] = temp;            
        }
        return i;
    }

    void quick_sort(int ini, int fin){
        if(ini >= fin){
            cout << "";
        }
        else{
            int x = particion(ini,fin);
            quick_sort(ini, x-1);
            quick_sort(x+1, fin);
        }
    }
    
    void swap(int *a, int *b){ //Intercambiar
        int temp = *a;
        *a = *b;
        *b = temp;
    }
   
    void heapify(int n) {
        for (int i = n / 2 - 1; i >= 0; i--){
            // Compara las hojas con su nodo superior
            int may = i;
            int iz = 2*(i + 1) - 1;
            int der = 2*(i + 1);
          
            if (iz < n && v[iz] > v[may]){
                may = iz;
            }    
            if (der < n && v[der] > v[may]){
                may = der;
            }
            // Cambia el nodo superior si este no fue el mayor numero
            if (may != i) {
                swap(&v[i], &v[may]);
            }
        }
        swap(&v[0], &v[n-1]);
    }
  
    void heapSort(int n) {
        if((n-1) <= 0){
            cout << "";
        }
        else{
            heapify(n);
            heapSort(n-1);
        }
    }

    void pop(){
        remove(size-1);
    }

    void inPila(int x){
        push_back(x);
    }
    
    int canPila(){
        int x = get(size-1); 
        pop();
        return x;
    }
};


    

int main()
{
    srand(time(NULL));
    int n = 10;
    int p = 0;
    int x = 0, y = 0;
    Vector v = Vector(n);
    for(int i=0; i<n; i++)
    {
        do
            p = rand() % 15;
        while(v.checkrep(p, n));
        v.inPila(p);
    }
    v.print();
    cout<<endl;
    for(int i = n-1; i>=0; i--){
        cout << v.canPila() << " ";        
    }

    return 0;
}


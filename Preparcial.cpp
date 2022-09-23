#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector <string > & v){
    int minimo=v[0].length();
    int a;
    string b,c;
    for(int i=0; i< v.size(); i++){
        for( int j=i; j<v.size(); j++){
            if(v[j].length() <= minimo){
                minimo=v[j].length();
                a=j;
            }
        }
        b = v[i];
        v[i] = v[a];
        v[a] = b;
        minimo = 100000000;
    }
    for(int i=0; i< v.size(); i++){
        for( int j=1; j<v.size(); j++){
            if(v[j-1].length() == v[j].length()){
                if(v[j-1] > v[j]){
                    c = v[j-1];
                    v[j-1] = v[j];
                    v[j] = c;
                }   
            }else{
                if(v[j-1].length() > v[j].length()){
                    c = v[j-1];
                    v[j-1] = v[j];
                    v[j] = c;
                }                
            }
        }
    }
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }   
}

int main()
{
    vector<string> v;
    v.push_back("ABC");    
    v.push_back("2");
    v.push_back("AB");
    v.push_back("4");
    v.push_back("F");
    v.push_back("A");    
    
    bubble_sort(v);

    return 0;
}

//----------------------------------------------------- Version 2

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int particion(string *v, int ini, int fin){
    string pivote = v[fin];
    int i = ini-1;
    string temp;
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

void quick_sort(string *v, int ini, int fin){
    if(ini >= fin){
        cout << "";
    }
    else{
        int x = particion(v, ini, fin);
        quick_sort(v, ini, x-1);
        quick_sort(v, x+1, fin);
    }
}

void bubble_sort(string *v, int m){
    int minimo=v[0].length();
    int a;
    string b,c;
    for(int i=0; i< m; i++){
        for( int j=i; j<m; j++){
            if(v[j].length() < minimo){
                minimo=v[j].length();
                a=j;
            }
        }
        b = v[i];
        v[i] = v[a];
        v[a] = b;
        minimo = 100000000;
    }
    
}

void print(string *v, int m){
    for(int i=0; i<m; i++){  
        cout << v[i] << " ";  
    }     
}




int main() {
   
    int m = 6;
    string b[m];

    b[0] = "ABC";    
    b[1] = "2";
    b[2] = "AB";
    b[3] = "4";
    b[4] = "F";
    b[5] = "A";
   
    print(b,m); 
       
    cout << endl;
    
    quick_sort(b, 0, m-1);
    
    print(b,m); 

    cout << endl;

    bubble_sort(b, m);
    
    print(b,m); 
   
    return 0;
}

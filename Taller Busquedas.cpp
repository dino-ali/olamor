//----------------------------------------------------------- #1

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 1; i < 10; ++i)
        v.push_back(i);  
    cout << v.size()<<endl;
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
    
    cout << endl;
    v.erase(v.begin()+3);

    for (int i = 1; i <= v.size(); i++){
        if (v[i-1] != i){
            cout <<  "El entero que falta es el "<< i;
            break;
        }
    }
}

//----------------------------------------------------------- #2

#include <iostream>
#include <vector>

using namespace std;


void two_smallest( vector <string > & arr){
    int minimo, x;
    
    minimo = arr[0].length();
    for (int i = 1; i < arr.size(); i++){
        if (arr[i].length() <= minimo){
            minimo = arr[i].length();
            x = i;
        }
    }
    cout << "El  primero mas pequeño es "<< arr[x] << endl;
    arr.erase(arr.begin()+ x);
    minimo = arr[0].length();
    
    for (int i = 1; i < arr.size(); i++){
        if (arr[i].length() <= minimo){
            minimo = arr[i].length();
            x = i;
        }
    }
    
    cout << "El  segundo mas pequeño es "<< arr[x] << endl;    
}


int main()
{
    vector<string> v;
    
    v.push_back("Hola");
    v.push_back("Mundo");
    v.push_back("x");
    v.push_back(":)");
    
    two_smallest(v);
    

}

//----------------------------------------------------------- #3

#include <iostream>
#include <vector>

using namespace std;

int findMaximum (vector <int > & arr){
    int maximo, x;
    maximo = arr[0];
    
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] >= maximo){
            maximo = arr[i];
            x = i;
        }
    }
    
    return x;
}

int main()
{
    vector<int> v;
    int a;
    
    for (int i = 1; i < 6; i++)
        v.push_back(i);
    for (int i = 6; i > 0; i--)
        v.push_back(i);
    
    a = findMaximum(v);
    cout << "El mayor elemento es: " << v[a];
    
    
}

//----------------------------------------------------------- #4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int r;
    
    for (int i = 1; i <= 10; ++i){
        r = rand()%10;
        v.push_back(r);  
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
    cout << endl;
    
    
    for (int i = 0; i <= v.size(); i++){
        if (v[i] == i){
            cout <<  "El indice "<< i << " es igual a su valor";
            break;
        }
    }
    

}


//----------------------------------------------------------- #5

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int interpolacion(vector <int > & arr, int x, int right, int left){
    int pos;
    if(right!=left){
        pos=left+ ((x-arr[left])*(right-left))/(arr[right]-arr[left]);
        if(x==arr[pos]){
            return pos;
        }else if(x<arr[pos]){
            interpolacion(arr, x, pos-1,left);
        }else if(x>arr[pos]){
            interpolacion(arr,x, right, pos+1);
        }
    }else{
        return pos;
    }
    return -1;
}

int main() {
    //punto5
    vector<int>v5;
    v5.push_back(1);
    v5.push_back(2);
    v5.push_back(3);
    v5.push_back(4);
    v5.push_back(5);
    v5.push_back(6);
    cout << "El numero está en la posición: ";
    cout << interpolacion(v5, 4, 0, 5);

   
    return 0;
}

//----------------------------------------------------------- #6
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int anti_peak(const vector<int> & vec){
    for(int i=0; i<vec.size(); i++){
        if(vec[i]<vec[i-1] && vec[i]<vec[i+1]){
            return i;
        }
        if(i==0){
            if(vec[i]<vec[i+1]){
                return i;
            }
        }else if(i==vec.size()-1){
            if(vec[i]<vec[i-1]){
                return i;
            }
        }
    }
    return -1;
}

int main() {
    vector<int>v6;
    v6.push_back(12);
    v6.push_back(11);
    v6.push_back(10);
    v6.push_back(6);
    v6.push_back(5);
    v6.push_back(1);
    cout << "El numero mínimo local es : ";
    cout << anti_peak(v6);
   
    return 0;
}


//----------------------------------------------------------- #7


#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

char** crear_mat(int n, int m){
    char** mat = new char*[n];
    for(int i = 0; i<n; i++){
        mat[i] = new char[m];
        for(int j=0; j<m; j++){
            mat[i][j] = 0;
        }
    }
    return mat;
}

int search (char **a, char *v, int n, int m){
    int cnt = 0;
    for(int i=0; i < n; i++){  
       for(int j=0; j <= n-m; j++){  
            if (a[i][j] == v[j] && a[i][j+1] == v[j+1] && a[i][j+2] == v[j+2] && a[i][j+3] == v[j+3]){
                cnt ++;
            }
        }  
    }  
    cout << "La cantidad de ocurrencias es: "<<cnt;
}



int main() {
   
    srand(time(NULL));
    std::string alphabet = "cgta";
    int n = 7;
    int m = 4;
    char** a = crear_mat(n,n);
    char b[4];
    for(int i=0; i<n; i++){  
       for(int j=0; j<n; j++){  
            char ch = alphabet[rand() % alphabet.size()];
            a[i][j] = ch;  
       }  
    }  
   
    for(int i=0; i<n; i++){  
       for(int j=0; j<n; j++){  
            cout << a[i][j] << " ";  
       }  
       cout << endl;
    } 
    
    cout<<endl;    
      
    for(int i=0; i<m; i++){  
        char ch = alphabet[rand() % alphabet.size()];
        b[i] = ch;  
    } 
   
    for(int i=0; i<m; i++){  
        cout << b[i] << " ";  
    } 
       
    cout << endl;
    
    search(a,b,n,m);
    return 0;
}

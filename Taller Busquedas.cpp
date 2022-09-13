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

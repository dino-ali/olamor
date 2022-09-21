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
    v.push_back("ABC");    
    v.push_back("2");
    v.push_back("AB");
    v.push_back("4");
    v.push_back("F");
    v.push_back("A");


    
    
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout<<endl;
    int minimo=v[0].length();
    int a;
    string b;
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
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
    cout << endl;
    

    string c;
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

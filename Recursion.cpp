//------------------------------------------------------------------------------- ELEMENTO MINIMO

#include<iostream>

using namespace std;

int min(int* v) {
	int min = v[0];
	for (size_t i = 1; i < (sizeof v - 1); i++)
	{
		if (v[i] < min) {
			min = v[i];
		}
	}

	return min;
}

int min2(int* v, int k, int min) {
	if (k >= (sizeof v - 1)){
		return min;
	}
	else{
		
		if (v[k] < min) {
			min = v[k];
		}
		min2(v, k+1, min);
	}
}

int main()
{
    int vector[] = {5,45,6,2,8,63,1};
    
	cout << min2(vector,0,100);
    
    
    return 0;
}

//------------------------------------------------------------------------------- FIBONACI Y FACTORIAL

#include<iostream>

using namespace std;
/*
int Fib(int n, int x, int y, int suma) {
	if (n == 1){
		x = 0, y = 1;
		cout << " " << x << " " << y ;
	}else{
		suma = x + y;
		cout << " " << suma;
		x = y;
		y = suma;	 	
		Fib(n-1, x, y, suma);
	}
}
*/

int Fib(int n, int x, int y, int suma, int k) {
	if (k < n){	
		if (k == n){
			suma = x + y;
			cout << " " <<suma;
		}else{ 
			suma = x + y;
			cout << " " <<suma;
			x = y;
			y = suma;	 	
			Fib(n, x, y, suma, k+1);
		}
	}
}

int Fact(int n) {
	if (n == 0){
		return 1;
	}else{
		return n*Fact(n-1); 	
	}
}

int fib1(int n){
	int suma = 0;
	int x = 0, y = 1;
	if (n > 2){
		cout << x << " " << y;
		for (int i = 0; i < n; i++){
		}
	}else{
		cout << x << " " << y;
	}
	return suma;
}



int main()
{   
	Fib(6, 0, 1, 0,0);    
   	return 0;
}



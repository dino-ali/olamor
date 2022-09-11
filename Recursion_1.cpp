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


#include <bits/stdc++.h>
using namespace std;
int n;

void in_arr(float *a, int* b){
	for(int i = 0; i < n; i++){
		cout<<"nhap co so: "; cin>>*(a+i);
		cout<<"nhap so mu: "; cin>>*(b+i);
	}
}

int horner(float *a, int* b, int x){
	double result = 0; 
	for(int i = 0; i < n; i++)
		result += *(a+i) * pow( x,*(b+i) );
	return result;
}

int main(){
	cin>>n;
	float* a = new float[n+1];
	int* b = new int[n+1];
	in_arr(a,b);
	float x; cin>>x; 
	cout<<horner(a,b,x);
	delete a;
	delete b;
}
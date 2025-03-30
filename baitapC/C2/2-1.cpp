#include <bits/stdc++.h>
using namespace std;

//Cau a
void input_arr(int *a, int n){
	for(int i = 0; i < n; i++)
		cin>> *(a+i);
}
void show_arr(int *a, int n){
	for(int i = 0; i < n; i++){
		cout<< *(a+i) << " "; 
	} cout<<endl;
}
void deleteK(int *a, int &n, int k){
	for(int i = k; i < n - 1; i ++){
		a[i] = a[i+1];
	} --n;
}

//Cau b
void addX(int *a, int n, int h, int x){
	for(int i = n - 1; i >= h; i--){
		a[i+1] = a[i];
	}
	a[h] = x;
	++n;
} 

//Cau c
int Integer(int n){
	if( n < 2) return 0;
	if ( n > 2){
		if( n % 2 == 0)
			return 0;
	} 
	for(int i = 2; i <= sqrt(n); i++){
		if( n % i == 0){
			return 0;
		}
	}
	return 1;
}

void deleteInteger(int *a, int n, int k){
	for(int i = 0; i < n; i++){
		if( Integer(a[i]) == 1 ){
			deleteK(a,n,i);
			i--; n--;
		}
	} cout<<"sau khi xoa SNT: "; show_arr(a,n);
}

int main(){
	int n, k; cin>>n;
	int *a = new int[n+1]; 
	input_arr(a,n);
	show_arr(a,n);

	// Cau a
	cin>>k;
	cout<<"ma tran sau khi xoa vi tri k: ";
	deleteK(a,n,k);
	show_arr(a,n);

	//Cau b	
	cin>>k;
	int x; cin>>x;
	addX(a,n,k,x);
	show_arr(a,n);

	// Cau c
	deleteInteger(a,n,k);
	delete a;
}
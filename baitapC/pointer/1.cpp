#include <bits/stdc++.h>
using namespace std;

void input_arr(int *a, int n){
	for(int i = 0; i < n; i++){
		cin>> *(a+i);
	}
}
void show_arr(int *a, int n){
	for(int i = 0; i < n; i++){
		cout<< *(a+i) << " "; 
	} cout<<endl;
}
void sum_arr(int *a, int n){
	int sum = 0;
	for(int i = 0; i < n; i ++){
		sum += *(a+i);
	} cout<<endl<<"tong phan tu: "<<sum<<endl;
}
void reverse(int *a, int n){
	for(int i = 0; i < n / 2; i++){
		swap(a[i],a[n-i-1]);
	}
}
int main(){
	int n; cin>>n;
	int *a = new int[n+1]; 
	input_arr(a,n);
	show_arr(a,n);
	sum_arr(a,n); //tong phan tu mang
	reverse(a,n); //dao nguoc phan tu mang
	cout<<"mang sau khi dao nguoc: ";
	show_arr(a,n);
	delete[] a;
}
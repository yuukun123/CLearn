//heap sort 
#include <bits/stdc++.h>
using namespace std;

void heap(int a[], int n, int i){
	int max = i;
	int l = 2 * i + 1; // lay phan tu con cua i + 1
	int r = 2 * i + 2; // lay phan tu con cua i + 2
	if( l < n && a[l] > a[max] ) max = l; 
	if( r < n && a[r] > a[max] ) max = r;
	if( max != i ){
		swap(a[i], a[max]);
		heap(a,n,max);
	}
}

void heapsort(int a[], int n){
	for(int i = n/2 -1; i >= 0; i--)
		heap(a,n,i);
	for(int i = n - 1; i >= 0; i--){
		swap(a[0],a[i]);
		heap(a,i,0);
	}
}

void out_arr(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	int a[] = {5, 6, 9, 3, 8, 2, 5, 0, 8, 1}; int n = 10;
	out_arr(a,n); cout<<endl;
	heapsort(a,n);
	out_arr(a,n);
}
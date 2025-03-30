#include <bits/stdc++.h>
using namespace std;

void quick_sort(int a[], int l, int r){
	int i = l; int j = r; int mid = a[l];
	while( i < r && a[i] < mid) i++;
	while( j > l && a[j] > mid) j--;
	if( i <= j ){
		swap(a[i],a[j]);
		i++; j--;
	} 
    if (l < j) quick_sort(a, l, j);
    if (i < r) quick_sort(a,i, r);
}

void out_arr(int a[], int n){
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
}

int main(){
	int a[] = {5, 6, 9, 3, 8, 2, 5, 0, 8, 1}; int n = 10;
	out_arr(a,n); cout<<endl;
	quick_sort(a,0,n);
	out_arr(a,n);
}
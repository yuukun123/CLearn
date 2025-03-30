#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int x, int n){
	int l = 0, r = n - 1;
	
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] == x) return 1;
		else if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return 0;
}

void input_arr(int a[], int &n){
	for(int i = 0; i < n; i++)
		cin>>a[i]; 
}

void out_arr(int a[], int n){
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
}

int main(){
	int a[1001]; int n ; cin>>n;
	input_arr(a,n);
	out_arr(a,n); cout<<endl;
	sort(a, a + 10);
	out_arr(a,n); cout<<endl;
	int x; 
	while ( x != 0 ){
		cin>>x;
		if ( x == 0 ) break;
		if( binary_search(a,x,n)) cout<<"tim thay x"<<endl;
		else cout<<"khong tim thay"<<endl;		
	}
}
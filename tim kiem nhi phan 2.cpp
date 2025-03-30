#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int x, int n){
	int l = 0, r = n - 1, result = -1;
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] == x){
			return mid;
			r = mid - 1;
		} 
		else if (a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return result;
}

void input_arr(int a[], int &n){
	for(int i = 0; i < n; i++)
		cin>>a[i]; 
}
void out_arr(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
	} 
}

int UCLN(int a[], int n){
	int UCLN = a[0];
	for(int i = 0; i < n; i++){
		UCLN = __gcd(UCLN,a[i]);
	} return UCLN;
}

int main(){
	int n ; cin>>n;
	int a[n+1]; 
	input_arr(a,n);
	out_arr(a,n); cout<<endl;

	int x; cin>>x;
	if( binary_search(a,x,n) ){
		for (int i = x; i < n - 1; i++){
				a[i] = a[i+1];
		} --n;	
	}cout<<UCLN(a,n);
}
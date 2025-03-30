#include <bits/stdc++.h>
using namespace std;

int max(int a[], int n){
	if(n==1) return a[0];
	if (a[n-1]>max(a,n-1)) return a[n-1];
	return max(a,n-1);
}

main(){
	int a[5], n; cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}
	cout<<max(a,n);
}
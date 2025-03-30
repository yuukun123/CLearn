#include <bits/stdc++.h>
using namespace std;

#define m 1000

int main(){
	int a[100]; int cnt[10001]; int b[100];
	int n; cin >> n;
	for( int i = 0; i < n; i++){
		cin>>a[i];
		++cnt[a[i]];	
	}
	for( int i = 1; i <= m; i++){
			cnt[i] = cnt[i] + cnt[i-1];
	}
	for(int i = n - 1; i >= 0; i--){
		b[--cnt[a[i]]] = a[i];
	}
	for(int i = 0; i < n; i++){
		a[i] = b[i];
		cout<<b[i]<<" ";
	}

}
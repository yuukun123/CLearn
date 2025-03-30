#include <bits/stdc++.h>
using namespace std;

//a
int sum(int k, int n){
	if( k == 0 || n == k ) return 1;
	if( k == 1 ) return n;
	else return sum(k-1,n-1) + sum(k,n-1);
}

//b
void passcal(int k, int n){
	for(int i = 0; i < n; i++){
		for(int j = n; j > i; j--)
			cout<<" ";
		for(int j = 0; j <= i; j++){
			cout<<sum(j,i)<<" ";	
		}cout<<endl;
	}
}

int main(){
	int n, k; cin>>k>>n;
	cout<<sum(k,n)<<endl;
	passcal(k,n);
}
#include <iostream>
using namespace std;

int giaithua(int n){
	if( n == 0) cout<<n;
	if(n > 1) return n * giaithua(n-1);
}

main(){
	int n; cin>>n;
	cout<<giaithua(n);
}
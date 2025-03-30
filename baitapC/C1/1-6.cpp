#include <bits/stdc++.h>
using namespace std;

//Xn = n*X0 + (n-1)*X1 + (n-2)*X2 + (n-3)*X3 + ... + Xn-1

int sum(int n){
	if( n <= 1)	return 1;
	else{
		int result = 0;
		for(int i = 1; i <= n; i++){
			result += i * sum(n-i);
		} return result;
	}
}

int main(){
	int n; cin>>n;
	cout<<sum(n);
}
#include <bits/stdc++.h>
using namespace std;

// Xn = n*(X1+ X2 + X3 + ... + Xn-1)

//a
int sum(int n){
	if( n == 1 ) return 1;
	else{
		int result = 0;
		for(int i = 1; i < n; i++){
			result += 1 * sum(i);
		} return result * n;
	}
}

//b
int sum_b(int n){
	int s = 0, x1 = 1;
	for(int i = n; i > 1; i--){
		s += i * x1;
		x1 = s;
	} return s;
}

main(){
	int n; cin>>n;
	cout<<sum(n)<<endl<<sum_b(n);
}
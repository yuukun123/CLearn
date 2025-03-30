#include <bits/stdc++.h>
using namespace std;

// Xn = Xn-1 + (n-1)*Xn-2

//a
int sum_a( int n ){
	if(n == 1 || n == 2) return 1;
	return sum_a(n-1) + (n - 1) * sum_a(n-2);
}

//b
int sum_b( int n ){
	if(n == 1 || n == 2) return 1;
	else{
		int x1 = 1, x2 = 1, x;
		for(int i = 3; i <= n; i++){
			x = x2 + (i-1) * x1;
			x1 = x2;
			x2 = x;
		} return x2;
	}
}

int main(){
	int n; cin>>n;
	cout<<sum_a(n)<<endl
	<<sum_b(n);
}
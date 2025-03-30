#include <bits/stdc++.h>
using namespace std;

//a
// s = 1 + 2 + 3 + ... + n
int sum_a(int n){
	if(n == 1) return n;
	return n + sum_a(n-1);
}

//b
// s = 1^2 + 2^2 + 3^2 + ... + n^2
int sum_b(int n){
	if(n == 1) return n;
	return pow(n,2) + sum_b(n-1);
}

//c
// s = 1 + 1*2 + 1*2*3 + ... +  1*2*3* ... * n
int sum_(int n){
	if(n == 1) return n;
	return n * sum_(n-1);
}
int sum_c(int n){
	if(n == 1) return n;
	return sum_(n) + sum_c(n-1);
}

//d
// s = 1*2 + 2*3*4 + ... + n*(n+1)* ... * 2n
int sum_(int n, int m){
	if(n > m) return 1 ;
	return n * sum_(n+1,m);
}
int sum_d(int n){
	if(n == 1) return 1 * 2;
	return n* sum_(n+1,2*n) + sum_d(n-1);
}

int main(){
	int n; cin>>n;
	cout<<sum_a(n)<<endl
	<<sum_b(n)<<endl
	<<sum_c(n)<<endl
	<<sum_d(n);
}
#include <bits/stdc++.h>
using namespace std;

// s = 1/1+f1 + 2/1+f2 + ... + n/1+fn

//a
long long fib(int n){
	if(n <= 2) return 1;
	return fib(n-1) + fib(n-2);
}



// float S(int n){
// 	if( n == 1 ) return 1.0 / ( 1 + fib(1) );
// 	return S(n-1) + n * 1.0 / ( 1 + fib(n) );
// }

// //b 
// float S_b(int n){
// 	float s = 0;
// 	int f1 = 1, f2 = 1;
// 	for(int i = 1; i <= n; i++){
// 		s += i * 1.0 / ( 1 + f1);
// 		int f3 = f1 + f2;
// 		f1 = f2;
// 		f2 = f3;
// 	}	return s;
// }

int main(){
	int n; cin>>n;
	long long  x = (fib(n) / pow(10,9) + 7);
	cout<<x;
	// cout<<S(n)<<endl<<S_b(n);
}
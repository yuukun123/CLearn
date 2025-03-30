#include <bits/stdc++.h>
using namespace std;

int solution(int n){
	static int reverse = 0, rem;
	if( n != 0 ){
		rem = n % 10;
		reverse = (reverse * 10) + rem;
		solution(n/10);
	}return reverse;
}

main(){
	int n; cin>>n;
	int temp = solution(n);
	cout<<temp;
	if( n == temp ) 
		cout<<"doi xung";
	else 
		cout<<"khong doi xung";
}
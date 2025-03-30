#include <bits/stdc++.h>
using namespace std;

int solution(int n){
	if( n == 1 || n == 2) 
		return 1;
	return solution(n-1) + solution(n-2);
}

main(){
	int n; cin>>n;
	cout<<solution(n)<<" ";
}
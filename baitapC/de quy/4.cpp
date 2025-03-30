#include <bits/stdc++.h>
using namespace std;

int solution(int n){
	if( n == 1 || n == 0) 
		return n;
	return solution(n-1) + solution(n-2);
}

main(){
	int n; cin>>n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += solution(n-i);
	}
	cout<<sum<<" ";
}
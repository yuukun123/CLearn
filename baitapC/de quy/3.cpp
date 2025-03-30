#include <bits/stdc++.h>
using namespace std;

void solution(int n){
	if( n == 0 ) return;
	if(n > 0){
		solution(n-1);
		cout<<n<<" ";
	}
}

main(){
	int n; cin>>n;
	solution(n);
}
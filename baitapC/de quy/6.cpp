#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b){
	return (a * b) / __gcd(a, b);
}

main(){
	int n, m; cin>>n>>m;
	cout<<solution(n,m)<<" ";
}
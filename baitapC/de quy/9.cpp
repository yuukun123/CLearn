#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b){
    if (b == 0) return a;
    return solution(b, a % b);
}

main(){
	int n, m; cin>>n>>m;
	cout<<solution(n,m)<<" ";
}
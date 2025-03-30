#include <bits/stdc++.h>
using namespace std;

void solution(char n[], int left, int right){
	if(left >= right) return;
	swap(n[left], n[right]);
	solution(n, left+1, right-1);
}

main(){
	char n[] = "chuu"; 
	solution(n, 0, strlen(n) - 1);
	cout<<n;
}
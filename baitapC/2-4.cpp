#include <bits/stdc++.h>
using namespace std;
int n;

void input_arr(int *a, int n){
	for(int i = 0; i < n; i++){
		cin>>*(a+i);
	} cout<<endl;
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += *(a+i);
	} cout<<"tong: "<<sum<<endl;
}

int Integer(int n){
	if( n < 2 ) return 0;
	if( n > 2 && n % 2 == 0 ) return 0;
	for(int i = 2; i < sqrt(n); i++){
		if( n % 2 == 0) return 0;
	}
	return 1;
}

void cntInteger(int *a){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if( Integer( *(a+i) ) == 1 )
			cnt++;
	} cout<<"co "<<cnt<<" SNT"<<endl;
}

void cnt_even_odd(int *a){
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++){
		if( *(a+i) % 2 == 0) cnt1++;
		else cnt2++;
	} 
	cout<<"co "<<cnt1<<" chan"<<endl;
	cout<<"co "<<cnt2<<" le"<<endl;
}

void findMax(int *a){
	for(int i = 0; i < n; i++){
		if( *(a+i) > *(a+i+1) )
			cout<<"so "<<*(a+i)<<" lon nhat"<<endl;
	}
}

void deleteFirst(int *a, int n, int k){
	for(int i = k; i < n - 1; i++){
		*(a+i) = *(a+i+1);
	} --n;
	cout<<"sau khi xoa phan tu dau ";
	for(int i = 0; i < n; i++){
		cout<<*(a+i)<<" ";
	} cout<<endl;
}

int main(){
	cin>>n;
	int *a = new int[n+1];
	input_arr(a,n);
	cntInteger(a);
	cnt_even_odd(a);
	findMax(a);
	deleteFirst(a,n,0);
	delete a;
}
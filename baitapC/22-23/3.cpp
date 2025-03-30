#include <iostream>
using namespace std;

int giaithua(int k, int n ){
	if( k == n || k == 0)
		return 1;
	return giaithua(k, n-1) + giaithua(k-1, n-1);
}

int cnt[10000]={0};

int main(){
	int k, n; int a[10000], b;
	cout<<"nhap k "; cin>>k;
	cout<<"nhap n "; cin>>n;

	if(k > n)
		cout<<"nhap sai";
	else {
		cout<<giaithua(k,n)<<endl;
	}
	cout<<endl;

	cin>>b; cout<<endl;
	for(int i = 0; i < b; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < b; i++)
	{
		cnt[a[i]]++;
	}
	for(int i = 0; i < b; i++){
		if(cnt[a[i]] != 0)
		{
			cout<<a[i]<<" tan suat "<<cnt[a[i]]<<endl;
			cnt[a[i]] = 0;
		}	
	}
}
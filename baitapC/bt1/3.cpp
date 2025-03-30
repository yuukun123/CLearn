#include <iostream>
using namespace std;

int main(){
	int i, j, n;
	cout<<"nhap so: ";
	cin>>n;
	if ( n < 2) cout<<"khong phai so nguyen to";
	else 
		for( i = 2; i < n; i++)
		{
			if( n % i ==0 ) cout<<"khong la nguyen to";
			else cout<<"so nguyen to";
			return 0;
		}
}
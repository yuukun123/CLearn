#include <iostream>
#include <math.h>
using namespace std;

int n, c; 

int main(){
	cout<<"nhap n: "; cin>>n;

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if ( i*i == j )
				cout<<j<<' ';
		}
	}

	c = n/10;
		cout<<endl<<c<<endl;

	for(int i = 0; i <= n; i++)
	{
		long long m = sqrt(n);
		if ( m*m == i )
			cout<<i;
	}

}
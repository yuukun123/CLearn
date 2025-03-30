#include <iostream>
using namespace std;

int main(){
	int n, a = 1, b = 1, i, c;
	cout<<"nhap so: ";
	cin>>n;
    if (n < 0) {
        cout<<"nhap so > 0";
    } else if (n == 0 || n == 1) {
        cout<<n;
	}
	else 
	{
		for (i = 2; i < n; i++)
		{
			c = a+b;
			a = b;
			b = c;
		}	
			cout<<"day so fibonancci: "<<c;
	}
}
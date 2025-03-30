#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n, a;
	float b;
	cout<<"nhap so: ";
	cin>>n;
	a = sqrt(n);
	b = sqrt(n);
	if ( a*a == b*b) cout<<"so chinh phuong";
	else cout<<"khong la so chinh phuong";
}
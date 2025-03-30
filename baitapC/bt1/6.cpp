#include <iostream>
using namespace std;

int main(){
	int n, i, s = 1 ;
	cout<<"nhap so tim giai thua: ";
	cin>>n;
	for ( i = 1 ; i <= n; i++){
		s = s * i;
	}
	cout<<"giai thua cua "<<n<<" la: "<<s;
}
#include <iostream>
using namespace std;

bool check(int n){
	int sum = 0;//khai bao biem sum
	for(int i=1; i<n; i++){
		if( n % i== 0 ) 
			sum += i;
	}
	if( sum==n ) return true; // tra ve true
	return false;
}

int main(){
	int n ;
	cout<<"nhap so: ";
	cin>>n;
	if (check(n))
		cout<<"la so hoan thien";
	else 
		cout<<"khong la so hoan thien";

}


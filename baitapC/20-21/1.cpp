#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

void sum(int &n){
	int s = 0;
	cout<<"nhap N: "; cin>>n;
	for( int i = n; i > 0; i /= 10)
	{
		s += i % 10;
	} cout<<endl<<"tong: "<<s;
}

bool snt(int n){
	if( n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++){
		if( n % i == 0)
			return false;
	} return true;
}

void check(int n)
{
	int s = 0;
	for( int i = 0; i < n; i++)
	{
		if ( snt(i) )
			s++;
	} cout<<endl<<"co "<<s<<" snt";
}

bool snt_doi_xung(int n)
{
	int sotrc;
    int sosau;
    int c = INT_MAX;
    for (int i = n - 1 ; i > 0 ; i--) {
        if (snt(i)) {
            sotrc = i;
            break;
        }
    }
    for (int i = n + 1 ; i < c ; i++) {
        if (snt(i)) {
            sosau = i;
            break;
        }
    }
    int temp = ( sotrc + sosau);
    if( snt((temp/2)) &&  ((temp % 2)== 0) )
    	return true;
    return false;

}
int main()
{
	int n;
	sum(n);	
	
	check(n);
	cout<<endl<<"snt doi xung ";
	for( int i = 0; i < n; i++)
	{
		if ( snt_doi_xung(i) )
			cout<<i<<" ";
	}
}
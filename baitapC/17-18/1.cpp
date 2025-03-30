#include <iostream>
using namespace std;

void caua(){
	int n; 
	cout<<"nhap n: "; cin>>n;
	int s = 0, g = 0;
	for (int i = 1; i < n; i++)
	{
		for( int j = 0; j < n; j++){
			g += (i*j);
			s += j;
		}
	}
	cout<<(float)g/s<<endl;
}
void caub(){
	int n, s = 0;
	cout<<"nhap n: "; cin>>n;
	for (int i = n; i > 0; i /= 10){
	s += i % 10;
	} cout<<s<<endl;
}
int main(){
	caua();
	caub();
}
#include <iostream>
#include <math.h>
using namespace std;

struct toado
{
	int hoanh, tung;
}td[10]; int n; 

void nhapOXY(toado &td){
	cout<<"nhap x "; cin>>td.hoanh;
	cout<<"nhap y "; cin>>td.tung;
}
void xuatOXY(toado td)
{
	cout<<" "<<"("<<td.hoanh<<","<<td.tung<<")"<<endl;
}
void nhapmang(toado td[], int &n)
{
	do{
		cout<<"nhap n "; cin>>n; cout<<endl;
	} while( n < 0 || n > 10);
	for(int i = 0; i < n; i++){
		cout<<"\ttoa do "<<i+1<<endl;
		nhapOXY(td[i]); cout<<endl;
	}
}
void xuatmang(toado td[], int n)
{
	for(int i = 0; i < n; i++){
		cout<<"\ttoa do "<<i+1<<endl;
		xuatOXY(td[i]);
	}
}
void dem(toado td[], int n)
{
	int cnt = 0; 
	for(int i = 0; i < n; i++)
	{
		if( ( pow(td[i].hoanh,2) + pow(td[i].tung,2) -4 ) > 0){
			cout<<"\ttoa do "<<i+1<<endl;
			xuatOXY(td[i]);
			cnt++;			
		}
	} cout<<"co "<<cnt<<" trong duong tron";
	
}

int main(){
	nhapmang(td,n);
	dem(td,n);
}
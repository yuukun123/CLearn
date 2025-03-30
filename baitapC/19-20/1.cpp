#include <iostream>
#include <math.h>
using namespace std;

int main(){
	float a,b,c,d;
	cout<<"nhap a b c de tim phuong trinh bac 2"<<endl;
	cout<<"nhap a: "; cin>>a; cout<<"nhap b: "; cin>>b;	cout<<"nhap c: "; cin>>c;
	if ( a == 0 )
	{
		if ( b == 0 ){
			if ( c == 0 ) cout<<"phuong trinh vo so nghiem"<<endl;
			else cout<<"phuong trinh vo nghiem"<<endl;
		}
		else  cout<<"phuong trinh co 1 nghiem duy nhat: "<<-c/b<<endl;
	}
	else {
		d = b*b-4*a*c;
		if (d<0) cout<<"Phuong trinh vo nghiem!!!"<<endl;
        else if (d==0) cout<<"Phuong trinh co nghiem kep la: "<<-b/(2*a)<<endl;
        else cout<<"Phuong trinh co 2 nghiem phan biet la: "<<(-b+sqrt(d))/(2*a)<<" va: "<<(-b-sqrt(d))/(2*a)<<endl; 
	}
}
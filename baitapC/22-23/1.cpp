#include <iostream>
using namespace std;

int a, b, c, d, e, f, D, Dx, Dy, x, y;

int main(){
	cout<<"he pt "<<endl;
	cout<<"nhap a "; cin>>a;
	cout<<"nhap b " ; cin>>b;
	cout<<"nhap c "; cin>>c;
	cout<<"nhap d "; cin>>d;
	cout<<"nhap e "; cin>>e;
	cout<<"nhap f "; cin>>f;

	D = a * e - b * d;
	Dx = c * e - b * f;
	Dy = a * f - c * d;

	if ( D == 0 )
	{
		if( Dx == 0 && Dy == 0 )
			cout<<"pt vo so nghiem";
		else cout<<"pt vo nghiem";
	}

	else{
		x = Dx/D; cout<<"pt co ngiem x: "<<x<<endl;
		y = Dy/D; cout<<"pt co ngiem y: "<<y;
	}
}
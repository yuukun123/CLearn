#include <iostream>
using namespace std;

struct phanso
{
	double tu, mau;
}; phanso a[10]; int h; int t;

void nhapPS(phanso &x)
{
	cout<<"nhap tu so: "; cin>>x.tu;
	cout<<"nhap mau so: "; cin>>x.mau;
}
void xuatPS(phanso x)
{
	if ((x.mau == 0 && x.tu == 0)||(x.mau == 0)) cout<<"phan so khong xac dinh";
	else if ( x.tu == x.mau) cout<<x.tu;
	else if ( x.tu == 0 ) cout<<'0';
	else cout<<x.tu<<"/"<<x.mau<<endl;
}

void nhapn(int &h)
{
	
	do{
		cout<<endl<<"nhap phan tu: "; cin>>h;
		if( h <= 0 || h >10 ) cout<<"mang chi chua phan tu <= 10"<<endl;
	}while(h <= 0 || h >10 );
}

void Nhap_Danh_Sach_Phan_So(phanso a[], int h)
{
	for (int i = 0; i < h; i++)
	{
		cout <<"\nNhap phan so thu "<<i+1<<endl;
		nhapPS(a[i]);
	}
}
void Xuat_Danh_Sach_Phan_So(phanso a[], int h)
{
	for (int i = 0; i < h; i++)
	{
		cout<<"\nPhan so thu "<<i+1<<": ";
		xuatPS(a[i]);
	}
}

int UCLN(int x, int y)
{
	if (x < 0)
	{
		x *= -1;
	}
	if (y < 0)
	{
		y *= -1;
	}
    int r;
    while (x%y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
	return y;
}
void Rut_Gon_Phan_So(phanso &x)
{
	if (x.mau == 0) ;
	else
	{
		int ucln = UCLN(x.tu, x.mau);
		x.tu = x.tu / ucln;
		x.mau = x.mau / ucln;
	}
}
void Rut_Gon_Danh_Sach_Phan_So()
{
	cout<<endl<<"phan so da toi gian"<<endl;
	for (int i = 0; i < h; i++)
	{
		Rut_Gon_Phan_So(a[i]);
	}
}

int dem(phanso a[], int h){
	int d=0;
	for(int i=0;i<h;i++)
		if(a[i].tu < a[i].mau)
			d=d+1;
	return d;
}

phanso lonnhat(phanso x, phanso y){
	phanso max;
	if(x.mau == y.mau){
	if(x.tu > y.tu)
	max=x;
	else
	max=y;
	}
	if(x.tu == y.tu){
	if(x.mau > y.mau)
	max=y;
	else
	max=x;
	}
	if (x.tu != y.tu && x.mau != y.mau){
	if(x.tu * y.mau > y.tu * x.mau)
	max=x;
	else
	max=y;
	}
	return max;
	}
phanso lonnhatmangphanso(phanso a[], int h){
	phanso max=a[0];
	for(int i=1; i< h;i++)
	max=lonnhat(a[i],max);
	return max;
}
int main(){
	nhapn(h);
	Nhap_Danh_Sach_Phan_So(a,h);
	Xuat_Danh_Sach_Phan_So(a,h);

	int b = dem(a,h);
	cout<<endl<<"co "<<b<<" phan so be hon 1"<<endl;

	phanso m;
	m = lonnhatmangphanso(a,h);
	Rut_Gon_Phan_So(m);
	cout<<endl"phan so lon nhat o dang rut gon la: ";
	xuatPS(m);
	cout<<endl;
}
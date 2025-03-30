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

void themphanso(phanso a[], int &h)
{
	cout<<"nhap phan so muon them "; cin>>t;
	if ( t + h > 10 ) cout<<"o chua da day";
	else{
		for ( int i = 0; i < t; i++){
			cout<<endl<<"nhap phan so them"<<endl;
			nhapPS(a[h]);	
			h++;
		}
	}
}
phanso Tinh_Tong_2_Phan_So(phanso x, phanso y)
{
	phanso tong;
	if (x.mau != y.mau)
	{
		tong.tu = (x.tu * y.mau) + (y.tu * x.mau);
		tong.mau = x.mau * y.mau;
	}
	else
	{
		tong.tu = x.tu + y.tu;
		tong.mau = x.mau;
	}
	return tong;
}
phanso Tinh_Tong_Tat_Ca_Phan_So(phanso a[])
{

	phanso tong = a[0];
	for (int i = 1; i < h; i++)
	{
		tong = Tinh_Tong_2_Phan_So(tong, a[i]);
	}
	return tong;
}

phanso Tinh_Hieu_2_Phan_So(phanso x, phanso y)
{
	phanso hieu;
	if (x.mau != y.mau)
	{
		hieu.tu = (x.tu * y.mau) - (y.tu * x.mau);
		hieu.mau = x.mau * y.mau;
	}
	else
	{
		hieu.tu = x.tu - y.tu;
		hieu.mau = x.mau;
	}
	return hieu;
}
phanso Tinh_Hieu_Tat_Ca_Phan_So(phanso a[])
{

	phanso hieu = a[0];
	for (int i = 1; i < h; i++)
	{
		hieu = Tinh_Hieu_2_Phan_So(hieu, a[i]);
	}
	return hieu;
}

phanso Tinh_Tich_2_Phan_So(phanso x, phanso y)
{
	phanso tich;
	tich.tu = x.tu * y.tu;
	tich.mau = x.mau * y.mau;
	return tich;
}
phanso Tinh_Tich_Tat_Ca_Phan_So(phanso a[])
{
	phanso tich = a[0];
	for (int i = 1; i < h; i++)
	{
		tich = Tinh_Tich_2_Phan_So(tich, a[i]);
	}
	return tich;
}

phanso Tinh_Thuong_2_Phan_So(phanso x, phanso y)
{
	phanso thuong;
	thuong.tu = x.tu * y.mau;
	thuong.mau = x.mau * y.tu;
	return thuong;
}
phanso Tinh_Thuong_Tat_Ca_Phan_So(phanso a[])
{
	phanso thuong = a[0];
	for (int i = 1; i < h; i++)
	{
		thuong = Tinh_Thuong_2_Phan_So(thuong, a[i]);
	}
	return thuong;
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

void Menu()
{				
	nhapn(h);
	Nhap_Danh_Sach_Phan_So(a,h);
	int luachon;
	do{
		cout<<"\n\t	   ===Menu==="
		<<"\n\t_________________________________"
		<<"\n\t|  1. nhap them phan so 	|" 				
		<<"\n\t|  2. hien thi phan so 		|"
		<<"\n\t|  3. phep tinh  2 phan so 	|"
		<<"\n\t|  4. rut gon phan so 		|"
		<<"\n\t|  0. thoat 			|"
		<<"\n\t|_______________________________|"
		<<"\n\n\tmoi ban chon: "; cin>>luachon;
		switch(luachon){
			case 0: {
				cout<<endl<<"\t"<<"chuong trinh da thoat"<<"\n"<<"\n";
				break;
			}
			case 1: {
				themphanso(a,h);
				break;
			}
			case 2:{
				Xuat_Danh_Sach_Phan_So(a,h);
				break;
			}
			case 3:{
				phanso tong; phanso hieu; phanso tich; phanso thuong;
				cout<<endl<<"hieu phan so: ";
				hieu = Tinh_Hieu_Tat_Ca_Phan_So(a);
				Rut_Gon_Phan_So(hieu);
				xuatPS(hieu); cout<<endl;

				cout<<"tong phan so: ";
				tong = Tinh_Tong_Tat_Ca_Phan_So(a);
				Rut_Gon_Phan_So(tong);
				xuatPS(tong); cout<<endl;

				cout<<"tich phan so: ";
				tich = Tinh_Tich_Tat_Ca_Phan_So(a);
				Rut_Gon_Phan_So(tich);
				xuatPS(tich); cout<<endl;

				cout<<"thuong phan so: ";
				thuong = Tinh_Thuong_Tat_Ca_Phan_So(a);
				Rut_Gon_Phan_So(thuong);
				xuatPS(thuong);
				break;
			}
			case 4:{
				Rut_Gon_Danh_Sach_Phan_So();
				Xuat_Danh_Sach_Phan_So(a,h);
				break;
			}
		}
	}while(luachon != 0);
}

int main(){
	Menu();
	system("pause");
}

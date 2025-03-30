#include <bits/stdc++.h>
using namespace std;

struct fraction
{
	int tu, mau;
} fr[1000]; int n;

void input(fraction &fr)
{
	cout<<"numerator: "; cin>>fr.tu;
	cout<<"denominator: "; cin>>fr.mau;
}
void show(fraction fr)
{
	cout<<fr.tu<<"/"<<fr.mau<<endl;
}

void input_arr(fraction fr[], int &n)
{
	
	do{
		cout<<"nhap phan tu: "; cin>>n;
	}while(n <= 0 || n > 10000 );	
	for (int i = 0; i < n; i++)
	{
		cout<<"\n\tfraction "<<i+1<<endl;
		input(fr[i]);
	}
}
void show_arr(fraction fr[], int n){
	for (int i = 0; i < n; i++)
	{
		cout<<"\nfraction "<<i+1<<"\t"; 
		show(fr[i]);
	}
}

bool cpm1(fraction a, fraction b){
	return  (a.tu * b.mau)  < (b.tu * a.mau) ;
}

void max_num(fraction fr[], int n){
	int max = 0;
	for(int i = 1; i < n; i++){
		if( fr[i].tu * fr[max].mau > fr[max].tu * fr[i].mau)
			max = i;
	}
	cout<<endl<<"phan so lon nhat "<<fr[max].tu<<"/"<<fr[max].mau<<endl;
}

void min_num(fraction fr[], int n){
	int min = 0;
	for(int i = 1; i < n; i++){
		if( fr[i].tu * fr[min].mau < fr[min].tu * fr[i].mau)
			min = i;
	}
	cout<<endl<<"phan so be nhat "<<fr[min].tu<<"/"<<fr[min].mau<<endl;
}

void max_product(fraction fr[], int n){
	int max_product = 0;
	int max_product1, max_product2;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int product = fr[i].tu * fr[j].tu;
			if( product > max_product){
				max_product = product;
				max_product1 = i;
				max_product2 = j;
			}
		}
	}
	cout<<endl<<"hai phan so co tich lon nhat "<<fr[max_product1].tu<<"/"<<fr[max_product1].mau
	<<" va "<<fr[max_product2].tu<<"/"<<fr[max_product2].mau;
}

int UCLN(int x, int y)
{
	int r;
	while( x % y!= 0 ){
        r=x%y;
        x=y;
        y=r;
	}
	return y;
}
void Rut_Gon_Phan_So(fraction &fr)
{
		int ucln = UCLN(fr.tu, fr.mau);
		fr.tu = fr.tu / ucln;
		fr.mau = fr.mau / ucln;
}

void Rut_Gon_Danh_Sach_Phan_So()
{
	cout<<endl<<"phan so da toi gian"<<endl;
	for (int i = 0; i < n; i++){
		Rut_Gon_Phan_So(fr[i]);
	}
}

void sort_fracttion(fraction fr[], int n){
	sort(fr,fr+n,cpm1);
	cout<<endl<<"phan so tang dan: ";
    
    for(int i = 0; i < n; i++){
    	cout<<fr[i].tu<<"/"<<fr[i].mau<<" ";
    } cout<<endl;
}

int main(){
	input_arr(fr,n);
	Rut_Gon_Danh_Sach_Phan_So();
	show_arr(fr,n);

	max_num(fr,n);
	min_num(fr,n);

	sort_fracttion(fr,n);

    max_product(fr,n);
}
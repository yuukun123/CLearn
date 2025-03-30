#include <iostream>
#include <climits>
using namespace std;

struct OXY{
	int dai, rong;
}toado[100]; int n;

void nhapOXY(OXY &toado){
	cout<<"nhap chieu dai: "; cin>>toado.dai;
	cout<<"nhap chieu rong: "; cin>>toado.rong;
}
void xuatOXY(OXY toado){
	cout<<"chieu dai: "<<toado.dai<<endl;
	cout<<"chieu rong: "<<toado.rong;
}
void nhap(OXY toado[], int &n ){
	cout<<"nhap n "; cin>>n;
	for(int i = 0; i < n; i++){
		cout<<endl<<"	hinh chu nhat "<<i+1<<endl;
		nhapOXY(toado[i]);
	}
}
void xuat(OXY toado[], int n){
	for(int i = 0; i < n; i++){
		cout<<endl<<"	hinh chu nhat "<<i+1<<endl;
		xuatOXY(toado[i]); cout<<endl;
	}
}

void dientich_max(OXY toado[], int n){
	int temp = INT_MIN;
	for(int i = 0; i < n; i++){
		if ( toado[i].dai * toado[i].rong > temp )
			temp = toado[i].dai * toado[i].rong;
	} cout<<endl<<"dien tich lon nhat "<<temp<<endl;
}
void dientich_sum(OXY toado[], int n){
	float dientich_sum; int s = 0;
	for(int i = 0; i < n; i++){
		dientich_sum = toado[i].dai * toado[i].rong;
		s += dientich_sum;
	} cout<<endl<<"tong dien tich "<<s;
}

int main(){
	nhap(toado,n); xuat(toado, n);
	dientich_max(toado,n);
	dientich_sum(toado,n);

}
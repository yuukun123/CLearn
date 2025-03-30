#include <iostream>
#include <math.h>
using namespace std;

int a[10000]; int n;
long long max(long long a, long long b){
	return a<b? b:a;
}

void nhapmang()
{
	for( int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]: "; cin>>a[i];
	}
}
void xuatmang()
{
	for( int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]:"<<a[i]<<endl;
	}
}
void tongmang()
{
	double s = 0;
	for( int i = 0; i < n; i++)
	{
		s += a[i];
	} cout<<s;
}

bool kiemtra(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int snt( int a[], int n){
	int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (kiemtra(a[i]) == true)
        {
            count++;
        }
    }
    return count;
}

void daytanglientiep(int a[], int n)
{
	int res = 0, cnt = 1;
	for ( int i = 1; i < n; i++)
	{
		if( a[i] > a[i-1]) ++cnt;
		else cnt = 1;
		res = max(res, cnt);
	} cout<<res;
}
int main(){
	cout<<"nhap n: "; cin>>n;
	nhapmang();
	cout<<endl<<"xuat mang"<<endl;
	xuatmang();
	cout<<endl<<"tong mang: ";
	tongmang(); cout<<endl;
	cout<<"co tat ca: "<<snt(a,n)<<" so nguyen to trong mang"<<endl;
	cout<<"chieu dai day con lien tiep tang dai nhat: ";
	daytanglientiep(a,n); cout<<endl;
}
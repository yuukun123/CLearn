#include <iostream>
#include <math.h>
using namespace std;
int a[10]; int n;

//cau a
void nhap(int a[], int &n)
{
	cout<<"nhap n: "; cin>>n;
	if( n <= 0 || n >= 10) cout<<"phan tu <= 10";
	else{
		for( int i = 0; i < n; i++)
		{
			cout<<"a["<<i<<"]: "; cin>>a[i];
		}	
	}
}
void xuat( int a[], int n)
{
	for( int i = 0; i < n; i++)
	{
		cout<<"a["<<i<<"]: "<<a[i];
	}
}

//cau b
bool kiemtra(int &m)
{
	if (m < 2)
	    return false;	
		int s = 0;
	for( int i = m; i > 0; i /= 10){
		
		s += i % 10;
	}
    if( s == 9)
        return true;	
    else{
    	for (int i = 2; i <= sqrt(m); i++)
		{
		    if (m % i == 0)
		    {
		        return false;
		    }return true;
		}		

    }
    
return false;
}	
bool snt(int m){
        if (kiemtra(m) != true)
        {
            return false;
        }
        int reverse_n = 0;
        while(m != 0)
        {
        	reverse_n = reverse_n * 10 + m % 10;
        	m /= 10;
        } return kiemtra(reverse_n);
}

//cau c
bool SoNguyenTo(int soA)
{
	int s = 0;
	for( int i = soA; i > 0; i /= 10){
		
		s += i % 10;
	}
    if ( s == 9)
        return true;
    return false;
}
int DemSoLuongSNT(int b)
{
	int dem = 0;
	for(int i = 1; i <= b; i++){
        if( SoNguyenTo(i) ) dem++;
	}
	return dem;
}
void LietKeSNT(int b)
{
	int i;
   	for( i = 1; i <= b; i++){
     	if( SoNguyenTo(i) ) cout<<i<<'\t';
   	}
}

//cau d
void trungbinh(int a[], int n)
{
	int s = 0;
	for( int i = 0; i < n; i++)
	{
		s += a[i];
	} cout<<endl<<"trung binh mang: "<<s/n;
}

int main(){
	nhap(a,n);

	int m;
	cout<<endl<<"nhap so de ktra: "; cin>>m;
	if ( snt(m)) cout<<"snt"<<endl;
	else cout<<"ko snt"<<endl;

	int b;
	cout<<endl<<"nhap b: "; cin>>b;
	if (b < 9) cout<<"khong so dep";
	else {
		DemSoLuongSNT(b);
		LietKeSNT(b); cout<<endl;
	}

	trungbinh(a,n);

}
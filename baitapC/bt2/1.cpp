#include <iostream>
using namespace std;
int a[100][100]; int i, j;
void nhapmang( int m, int n )
{
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<"a["<<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
		}
	}
}
void xuatmang(int m, int n )
{
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			cout<<a[i][j]<<"\t";
		} cout<<endl;
	} 
}
int main()
{
	int m,n;
	cout<<"nhap so cot: ";
	cin>>m;
	cout<<"nhap so hang: ";
	cin>>n;
	nhapmang(m,n);
	cout<<"ma tran: "<<endl;
	xuatmang(m,n);
}
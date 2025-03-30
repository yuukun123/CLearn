#include <iostream>
using namespace std;
int main()
{
	int a [2][3] ={{1,2,3},{4,5,6}} , i, j;
	for ( i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cout << a[i][j] <<"\t";
		} cout<<endl;
	}
	for(i = 0 ; i < 2; i++)
	{
		int s = 0;
		for ( j = 0; j < 3; j++)
		{
			s +=a[i][j];
		} cout<<"tong phan tu hang "<<i+1<<'\t'<<s<<endl;
	}
	int max = a[0][0];
	for ( i = 0; i < 2; i++)
	{
		max = a[i][0];
		for ( j = 0; j < 3; j++) 
		{
			if (a[i][j] > max)
			{
				max = a[i][0];
			}
		}
	}
	cout<<"phan tu lon nhat cot 1: "<<max;
}
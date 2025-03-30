#include <iostream>
using namespace std;

int main()
{
	int a [2][3] ={{1,2,3},{4,5,6}}, i, j;
	for ( i = 0; i < 2; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			cout<<a[i][j]<<"\t";
		} cout<<endl;
	}
	int max = a[0][0], min = a[0][0];
	for ( i = 0; i < 2; i++)
	{
		max = a[i][0];
		for ( j = 0; j < 3; j++) 
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
			}
			if ( a[i][j] < min )
			{
				min = a[i][j];
			}
		}
	}
	cout<<"phan tu lon nhat: "<<max<<endl;
	cout<<"phan tu nho nhat: "<<min;
}
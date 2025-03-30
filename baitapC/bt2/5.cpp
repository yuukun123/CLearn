#include <iostream>
using namespace std;
int maxdcchinh( int a[][3])
{
	int max=a[0][0];
	for(int i=1;i<3;i++)
	    if(a[i][i]>max)
	    max=a[i][i];
	return max;
}
int main()
{
	int a [3][3] ={{1,2,3},{4,5,6},{7,8,9}};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] <<"\t";
		} cout<<endl;
	}
	cout<<"phan tu lon nhat cua dcc: "<<maxdcchinh(a);
}
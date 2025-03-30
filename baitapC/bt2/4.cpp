#include <iostream>
#include <math.h>
using namespace std;

bool SoNguyenTo(int soA)
{
    if (soA < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt((float)soA); i ++)
        {
            if (soA%i==0)
            {
                return false;
            }
        }
    }
    return true;
}
int DemSoLuongSNT(int a[][3])
{
	int dem = 0;
	for(int i = 0; i < 2; i++)
	    for(int j = 0; j < 3; j++)
	        if(SoNguyenTo(a[i][j])) dem++;
	return dem;
}
void LietKeSNT(int a[][3])
{

   	for(int i = 0; i < 2; i++)
      	for(int j = 0; j < 3; j++)
         	if(SoNguyenTo(a[i][j])) cout<<a[i][j]<<'\t';
}
int main()
{
	int a [2][3] ={{1,2,3},{4,5,6}};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] <<"\t";
		} cout<<endl;
	}
	cout<<"so luong so nguyen to: ";
	cout<<DemSoLuongSNT(a);
	cout<<endl<<"so nguyen to trong mang: ";
	LietKeSNT(a);
}
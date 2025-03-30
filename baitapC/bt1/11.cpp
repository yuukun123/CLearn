#include <iostream>
using namespace std;

void Mang_Nguoc( int array[] , int n)
{
	int loop;
	for(int i = 1 ; i <= n; i++)
   {
   		cout<<"nhap phan tu array["<<i<<"] : ";
   		cin>>array[i];
	} 
   	cout<<"tat ca phan tu cua mang theo chieu dao nguoc: ";
	for(loop = n ; loop > 0; loop--)
	{
		cout<<array[loop]<<" ";
	}
}
int main() {
   int array[10] , n;
   cout<<"nhap so phan tu: ";
   cin>>n;
   Mang_Nguoc(array, n);
}


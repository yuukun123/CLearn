#include<iostream>
#include<cmath>
#define maxn 100
using namespace std;

void nhap(int a[][maxn],int &n)
{
    cout<<"nhap n: ";     cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
         cout<<"A["<<i<<"]["<<j<<"] = ";
            cin>>a[i][j];
        }
}
void xuat(int a[][maxn],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<"   ";
        cout<<endl;
    }
}
int doixung(int a[][maxn],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i][j] != a[j][i]) return false; 
        } 
    }
    return true;
}
int main()
{
    int a[maxn][maxn];
    int n;
    nhap(a,n);
    xuat(a,n);
    if(doixung(a,n)==1)
    cout<<" ma tran co doi xung qua duong cheo chinh";
    else
    cout<<" ma tran khong doi xung qua duong cheo chinh";
}
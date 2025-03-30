#include <iostream>
#include <ctime> 
using namespace std;
#define ROW 100
#define COL 100

void nhapMang(int a[][COL], int &m, int &n)
{
   srand(time(NULL));
   cout << "Nhap so dong: "; cin >> m;
   cout << "Nhap so cot: "; cin >> n;
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         a[i][j] = rand() % 100;
      }
   }
}
void xuatMang(int a[][COL], int m, int n)
{
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << a[i][j] << "\t";
      } cout << endl;  
   }
}
void swap(int &c, int &b)
{
   int temp = c;
   c = b;
   b = temp;
}
void hoanvicot(int a[][COL],int m,int n,int c1,int c2)
{
   if((c1>=0 && c1<n)&&(c2>=0 && c2<n))
   {
      for(int i=0;i<n;i++)
      swap(a[i][c1],a[i][c2]);
   }
   cout<<"2 hang sau khi doi cho: "<<endl;
   xuatMang(a,m,n);
   for (int i=0; i<n;i++)
      swap(a[i][c1],a[i][c2]);
}
void hoanvidong(int a[][COL], int m,int n,int d1,int d2)
{
   if((d1>=0 &&d1<m)&&(d2>=0 && d2<m))
   {
      for(int j=0;j<m;j++)
      swap(a[d1][j],a[d2][j]);
   }
   xuatMang(a,m,n);
}
int main()
{
   int a[ROW][COL]; 
   int c1, c2, d1, d2;
   int m ,n;
   nhapMang(a, m, n);
   xuatMang(a, m, n);
   cout<<"nhap so cot muon hoan doi: "<<endl;
   cin>>c1>>c2;
   hoanvicot(a,m,n,c1,c2);
   cout<<"nhap so dong muon doi: "<<endl;
   cin>>d1>>d2;
   hoanvidong(a,m,n,d1,d2);
}
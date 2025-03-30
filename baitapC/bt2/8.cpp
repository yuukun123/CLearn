#include <iostream>
#include <ctime> 
using namespace std;
#define ROW 100
#define COL 100

void nhapMang(int a[][COL], int &m, int &n)
{
   srand(time(NULL));
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
      }cout << endl;
   }
}
void congMaTran(int a[][COL], int b[][COL], int m, int n){
   int c[ROW][COL];
   for(int i = 0;i<m;i++){
      for(int j = 0;j<n;j++){
         c[i][j] = a[i][j] + b[i][j];
      }
   }
   cout<<endl<<"CONG 2 MA TRAN A B"<<endl;
   xuatMang(c,m,n);
}
int main()
{
   int a[ROW][COL];  
   int m ,n;   
   cout<<"ma tran 1: "<<endl;
   cout<<"Nhap so dong: "; cin>>m;
   cout<<"Nhap so cot: "; cin>>n;
   nhapMang(a, m, n);
   xuatMang(a, m, n);

   int b[ROW][COL];
   int m1 ,n1;   
   cout<<endl<<"ma tran 2: "<<endl;
   cout<<"Nhap so dong: "; cin>>m1;
   cout<<"Nhap so cot: "; cin>>n1;
   nhapMang(b, m1, n1);
   xuatMang(b, m1, n1);

   cout<<endl<<"------MA TRAN A-----"<<endl;
   xuatMang(a,m,n);
   cout<<endl<<"------MA TRAN B-----"<<endl;
   xuatMang(b,m1,n1);

   if(m == m1 && n == n1){
      congMaTran(a,b,m,n);
   }else{
     cout<<endl<<"So hang va so cot 2 ma tran khong bang nhau, khong the cong";
   }
}
#include <iostream>
#include <ctime> 
using namespace std;

int a [2][3] ={{1,2,3},{4,5,6}} , i, j;   
void XoaDong(int m, int n, int r)
{
   for( i=0;i<m;i++){
      if ( i+1 != r )
         for( j=0;j<n;j++)
            cout<<a[i][j]<<'\t';
   }
}
void XoaCot(int m, int n, int c)
{
   for( i=0;i<m;i++)
   {
      for( j=0;j<n;j++)
      {
         if (j+1 != c)
            cout<<a[i][j]<<'\t';
      }cout<<endl;
   }
}
int main()
{
   int r, c;
   cout<<"nhap so dong de xoa: ";
   cin>>r;
   cout<<"sau khi xoa 1 dong: "<<endl;
   XoaDong(2,3,r);   

   cout<<endl<<"nhap so cot de xoa: ";
   cin>>c;
   cout<<"sau khi xoa 1 cot: "<<endl;
   XoaCot(2,3,c);
}
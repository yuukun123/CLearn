#include<bits/stdc++.h>
using namespace std;
void nhap(int a[], int &n){
    do{
        cout<<"Nhap n: "; cin>>n;
    }
    while(n<2||n>99);
    for(int i=0; i<n; i++){
        cout<<"a["<<i<<"]: "; cin>>a[i];
    }
}
 
void Count(int a[], int n){
    int b[n];
    int x=1;
    b[0]=a[0];
    int i;
    for( i=1;i<n;i++){
        int dem=0;
        for(int j=0;j<x;j++){
            if(a[i]==b[j])
                dem++;
            
        }
        if(dem==0){
            b[x]=a[i];
            x++;
        }
    } cout<<"\nCo "<<x<<" phan tu khac nhau"<<endl;
}
int main(){
    int a[100];
    int n;
    nhap(a,n);
    Count(a,n);
}
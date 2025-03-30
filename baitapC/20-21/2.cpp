#include <iostream>
using namespace std;

void nhapmang(int a[], int &n){
    cout << "Nhap so luong n: ";
    cin >> n;
    for ( int i = 0; i < n; i++)
        cin>>a[i];

    int max = a[0];
    for( int i = 1; i < n; i++){
        if( a[i] > max )
            max = a[i];     
    } cout<<endl<<"so lon nhat mang "<<max<<endl;
}

int sum_arr(int a[], int n)
{
    int sum = 0;
    for ( int i = 0; i < n; i++)
    {
        for( int j = a[i]; j > 0; j /= 10)
            sum += j % 10;
    }
    return sum;
}
void sapxep(int a[], int n)
{
    int b;
    for ( int i = 0; i < n - 1; i++)
    {
        for( int j = i + 1; j < n; j++){
            if( a[i] > a[j])
            {
                b = a[i];
                a[i] = a[j];
                a[j] = b; 
            }
        }
    }
    cout<<endl<<"mang sap xep lai ";
    for ( int i = 0; i < n; i++)
        cout<<a[i]<<' ';
}

int main (){
    int n; int a[100];
    nhapmang(a,n);

    int s = sum_arr(a,n);
    cout<<"tong mang "<<s;

    sapxep(a,n);   
}
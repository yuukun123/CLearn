#include<iostream>
using namespace std;

void nhap(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao phan tu a[" << i << "] : ";
		cin >> a[i];
	}
}
void xuat(int a[], int n) 
{
	for (int i = 0; i < n; i++) 
		cout<<a[i]<<" "<<endl;
}

int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

int min(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];
    return min;
}

int main(){
	int a[1000], n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	nhap(a, n);
	cout << "Xuat mang: " << endl;
	xuat(a, n);
	cout<<"so lon nhat trong phan tu: "<<max(a,n)<<endl;
	cout<<"so nho nhat trong phan tu: "<<min(a,n)<<endl; 
}

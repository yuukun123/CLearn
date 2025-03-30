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
		cout<<a[i]<<" ";
}

int main(){
	int a[1000];
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	nhap(a, n);
	cout << "Xuat mang: " << endl;
	xuat(a, n);
}

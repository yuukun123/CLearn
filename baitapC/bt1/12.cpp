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
	int s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i]; 
	cout<<(float)s/n;
}

int main(){
	int a[1000];
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	nhap(a, n);
	cout << "gia tri trung binh cua phan tu: " << endl;
	xuat(a, n);
}

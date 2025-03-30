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

void swap(int &a, int &b){
    int tg = a;
    a = b;
    b = tg;
}

void SapXep(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                swap(a[i], a[j]);
            }
        }        
    }
}

int FindBySort(int a[], int n){
    SapXep(a, n);
    return a[1];
}
int main(){
	int a[1000];
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	nhap(a, n);
	cout << "Xuat mang: " << endl;
	xuat(a, n);
	cout<<"phan tu lon thu 2 cua mang la:"<<FindBySort(a,n); 
}

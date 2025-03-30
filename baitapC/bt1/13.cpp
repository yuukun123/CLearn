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

void TimKiem(int a[],int n, int phantu){
    int j;
    for(int i = 0; i < n; i++){
        if(phantu == a[i]){
        	j = i;
			break; 
		}
	}
    if( j != NULL ){
    	cout<<"TIM THAY PHAN TU TAI VI TRI "<<j;
	}
	else{
		cout<<"KHONG THAY PHAN TU ";
	}	
}

int main(){
	int a[1000];
	int n;
	cout << "Nhap so phan tu: ";
	cin >> n;
	nhap(a, n);
	cout << "Xuat mang: " << endl;
	xuat(a, n);
	int phantu;
    cout<<"\nNHAP PHAN TU CAN TIM KIEM: ";
    cin>>phantu;
    TimKiem(a,n,phantu);
}

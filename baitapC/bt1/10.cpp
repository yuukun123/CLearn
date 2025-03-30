#include<iostream>
using namespace std;
int UCLN(int a, int b){
	if(a==b) return a;
	if(a>b) 
		UCLN(a-b,b);
	else
		UCLN(a,b-a);
}

int BCNN(int a, int b){
	return ( (a * b)/UCLN(a,b)  );
}
void NhapMang(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<"Nhap a["<<i<<"]: ";
		cin>>a[i];	
	}
}
int BCNN_Mang(int a[],int n){
	int bcnn = BCNN(a[0], a[1] );
	for(int i=2;i<n;i++){
		bcnn = BCNN(bcnn, a[i]);	
	}
return bcnn;
}

int UCLN_Mang(int a[], int n){
	int ucln = a[0];
	for ( int i = 1; i < n; i++){
		ucln = UCLN(ucln, a[i]);
	}
return ucln;
}
int main(){
	int a[1000];
	int n;
	cout<<"Nhap vao n: ";
	cin>>n;
	NhapMang(a,n);
	cout<<"BCNN la: "<<BCNN_Mang(a,n)<<endl;
	cout<<"UCLN la: "<<UCLN_Mang(a,n);
	return 0;
}

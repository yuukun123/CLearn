#include <bits/stdc++.h>
using namespace std;

void input_arr(int **a, int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin>> *(*(a+i)+j) ;
		}
	}
}
void show_arr(int **a, int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout<< *(*(a+i)+j) <<" ";
		} cout<<"\n";
	}
}

void sum_row(int **a, int r, int c){ // tôngr hàng ma trận
	for(int i = 0 ; i < r; i++)
	{
		int s = 0;
		for (int j = 0; j < c; j++)
		{
			s +=a[i][j];
		} cout<<"tong phan tu hang: "<<i+1<<' '<<s<<endl;
	}
}
void swap_r_c(int **a, int r, int c){ // ma trận chuyển vị
	for(int i = 0; i < c; i++){
		for(int j = 0; j < r; j++){
			cout<< *(*(a+j)+i) <<" ";
		} cout<<"\n";
	}	
}

int main(){
	int r; cin>>r; 
	int c; cin>>c;

	int **a = new int* [r]; //cấp phát bộ nhớ động cho hàng 
	for(int i = 0; i < r; i++)
	   a[i] = new int[c]; //cấp phát bộ nhớ động cho cột

	input_arr(a,r,c);
	show_arr(a,r,c);
	sum_row(a,r,c);
	swap_r_c(a,r,c);


	for(int i = 0; i < r; i++)
	   delete []a[i];
	delete []a;
}
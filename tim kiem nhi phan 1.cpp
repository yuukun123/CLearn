#include <bits/stdc++.h>
using namespace std;

void binary_search(int a[], int x, int n){
	int left = -1, right = -1;
	
	int l = 0, r = n - 1;
// left 	
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] == x){
			left = mid;
			r = mid - 1;
		} 
		else if (a[mid] < x){
			l = mid + 1;
		}
		else r = mid - 1;
	}

	l = 0; r = n - 1;
//right
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] == x){
			right = mid ;
			l = mid + 1;
		} 
		else if (a[mid] < x){
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout<<"["<<left<<","<<right<<"]";
}

void input_arr(int a[], int &n){
	for(int i = 0; i < n; i++)
		cin>>a[i]; 
}

void out_arr(int a[], int n){
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
}

int main(){
	int n ; cin>>n;
	int a[n+1]; 
	input_arr(a,n);
	out_arr(a,n); cout<<endl;

	int x;
	cin>>x;
	binary_search(a,x,n);
}
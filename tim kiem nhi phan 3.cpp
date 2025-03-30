#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int n, int x){
    int l = 0, r = n - 1; int result = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if( a[mid] == x ) {
            return mid;
            r = mid - 1;
        }
        else if( a[mid] < x ){
            result = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return result;
}

void input_arr(int a[], int n){
	for(int i = 0; i < n; i++){
		cin>>a[i];

    }
}
void out_arr(int a[], int n){
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" ";
    }
}

int main(){
    int n; cin>>n; 
	int a[n+1]; 
	input_arr(a,n);
    sort(a,a+n);
	out_arr(a,n); cout<<endl;
    int x; cin>>x;
    cout<<binary_search(a,n,x); 
}

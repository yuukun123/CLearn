#include <bits/stdc++.h>
using namespace std;
float X(int n);
float Y(int n);

// Xn = Xn-1/3 + Yn-1/2 + 27
// Yn = Xn-1/5 + Yn-1/7 + 11

//a
float X(int n){
	if(n == 0)  return 1;
	return X(n-1)/3 + Y(n-1)/2 + 27;
}
float Y(int n){
	if(n == 0) return 2;
	return X(n-1)/5 + Y(n-1)/7 + 11;
}

//b
void X_Y(int n){
	float x = 1, y = 2;
	for(int i = 1; i <= n; i++){
		float temp = x;
		x = x/3 + y/2 + 27;
		y = temp/5 + y/7 + 11;
	} cout<<x<<endl<<y;
}


int main(){
	int n; cin>>n;
	cout<<X(n)<<endl<<Y(n)<<endl;
	X_Y(n);
}
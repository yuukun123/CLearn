#include <bits/stdc++.h>
using namespace std;
char str[50], x[50]; 

int strLen(char h[]){
	int i = 0;      
	while(x[i] != '\0') {
	    i++;
	} return i;
}

int cnt_str(char str[], char x[]){
	for(int i = 0; i < strLen(str); i++){
		for(int j = 0; j < strLen(x); j++){
			if( str[i] != ' ' && str[i] == x[j]){
				return i;
			}
		}
	} return -1;
}

void cnt(char str[], char x[]){
	int cnt2 = 0;
	int str_ = 0, x_ = 0;
	while( str[str_] != '\0') str_++;
	while( x[x_] != '\0') x_++;
	
	for(int i = 0; i < str_ - x_; i++){
		bool found = true;
		for(int j = 0; j < x_; j++){
			if( str[i+j] != x[j]){
				found = false; break;
			}
		}
		if(found) cnt2++;
	} cout<<x<<" xuat hien "<<cnt2;
}

int main(){
	gets(str); gets(x);
	cout<<cnt_str(str,x)<<endl;
	cnt(str,x);
}
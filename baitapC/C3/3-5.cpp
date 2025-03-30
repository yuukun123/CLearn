#include<bits/stdc++.h>
using namespace std;
char str[50], x = {0};
int cnt[256] = {0};

int strLen(char x[]){
	int i = 0;      
	while(x[i] != '\0') {
	    i++;
	} return i;
}

void findMax(){
	int max = 0;
	for(int i = 0; i < strLen(str); i++)
		cnt[str[i]]++;
	for(int i = 0; i < 256; i++){	
		if( cnt[i] > max){ 
			x = char(i);
			max = cnt[i];
		}
	} cout<<"ky tu"<<x<<" xuat hien nhieu nhat "<<max<<" lan";
}

int main(){
	gets(str);
	findMax();
}
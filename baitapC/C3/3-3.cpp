#include<bits/stdc++.h>
using namespace std;
char str[50], str1[50], str2[50]; int p;

int strLen(char x[]){
	int i = 0;      
	while(x[i] != '\0') {
	    i++;
	} return i;
}

void delete_str(){
	for(int i = p ; i < strLen(str); i++){
		str[i-1] = str[i];
	} str[strLen(str) - 1] = '\0';
	cout<<str<<endl;
}

void add_str(){
	for(int i = strLen(str1) - 1; i >= p ; i--)
		str1[i+strLen(str2)] = str1[i];
	for(int i = 0; i < strLen(str2); i++)
		str1[p+i] = str2[i];
	cout<<str1;
}

int main(){
	gets(str); cin>>p;
	delete_str();
	fflush(stdin);
	gets(str1); gets(str2);
	cin>>p;
	add_str();
}
#include <bits/stdc++.h>
using namespace std;
char str[50], t[50]; 

int strLen(char x[]){
	int i = 0;      
	while(x[i] != '\0') {
	    i++;
	} return i;
}

void strnCpy(char s1[], char s2[], int l){
	int length = 0;
	while(s1[length] != '\0') {
	    s2[length] = s1[length];
	    length++;
    } s2[length] = '\0';
}

void cnt_string(char str[]){
    int i = 0, cnt = 0, cnt1 = 0;
    while ( str[i] != '\0' ) {
        if( str[i] >= 'A' && str[i] <= 'Z' ) cnt++;
        if( str[i] >= 'a' && str[i] <= 'z' ) cnt1++;
        i++;
    }
    cout<<"co "<<cnt<<" chu hoa"<<endl;
    cout<<"co "<<cnt1<<" chu thuong"<<endl;
}

void findASCII(char str[]){
	strnCpy(str ,t ,0);
	for(int i = 0; i < strLen(str); i++){
		if( t[i] >= 'A' && t[i] <= 'Z' )
			 cout<<t[i]<<": "<<int(t[i])<<endl;
        if( t[i] >= 'a' && t[i] <= 'z' ) 
        	cout<<t[i]<<": "<<int(t[i])<<endl;
	}
}

void change_string(char str[]){
	strnCpy(str , t, 0);
	for(int i = 0; i < strLen(str); i++){
        if (t[i] >= 'A' && t[i] <='Z' )
            t[i] = tolower(t[i]);
        if (t[0] >= 'a' && t[0] <= 'z' )
            t[0] = toupper(t[0]);
	}cout<<t<<endl;
}

void cnt_str(char str[]){
	int cnt2 = 1;
	for(int i = 0; i < strLen(str); i++){
		if( str[i] == ' ' && str[i+1] != ' ')
			cnt2 ++;
	} cout<<cnt2<<" tu"<<endl;
}

void cnt(char str[]){
	int cnt3 = 0;
	for(int i = 0; i < strLen(str); i++){
		if( str[i] != ' ')
			cnt3 ++;
	} cout<<cnt3<<" ky tu"<<endl;
}

void findWord(char str[]){
	char first[50], last[50];
	int left = 0, right = 0;

	for(int i = 0; str[i] != ' '; i++){
		first[left++] = str[i];
	} first[left] = '\0';

	int start = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == ' ')
			start = i++;
	}
	for(int i = start; str[i] != '\0'; i++){
		last[right++] = str[i];
	} last[right] = '\0';
	cout<<"tu dau tien ben trai: "<<first<<endl;
	cout<<"tu dau tien ben phai: "<<last<<endl;
}

int main(){	
	gets(str);
	cnt_string(str);
	findASCII(str);
	change_string(str);
	cnt_str(str);
	cnt(str);
	findWord(str);
}
#include <iostream>
#include <string.h>
using namespace std;

void hoasangthuong(){
	int i; 
	char str[] = "HOC"; cout<<str;
	int l = strlen(str);
	for(i=0;i < l ;i++){
	    if(str[i]>=65&&str[i]<=90)
        	str[i]=str[i]+32;
   } cout<<endl<<"chuyen hoa sang thuong: "<<str<<endl;
}
void cattudau(){
	char b[] = "dai hoc sai gon";
	char t[64];
	strncpy(t, b + 0, 3);
	t[3] = '\0';
	cout<<endl<<b<<endl<<"tu dau tien: ";
	cout<<t<<endl;
}
void thuongsanghoa(){
	int i; 
	char str[] = "hoc"; cout<<endl<<str;
	int l = strlen(str);
	for( i=0; i <= l; i++){
		if( str[i]>=97 && str[i]<=122 )
		 str[i] =  str[i]-32;
	} cout<<endl<<"chuyen thuong sang hoa: "<<str<<endl<<endl;
}

int main(){
	hoasangthuong();
	cattudau();
	thuongsanghoa();
}
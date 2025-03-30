#include <iostream>
#include <cstring>
using namespace std;

void mang(int i , char c[] )
{
	int cnt [256] ={0};
	for (i = 0; i < strlen(c); i++)
	{
		cnt[c[i]]++;
	}
	int res = 0;
	char kt;
	for ( i = 0 ; i < 256; i++)
	{
		if(cnt[i]){
			if(cnt[i]>= res){
				res = cnt[i];
				kt = (char)(i);
				}
			}
	}
	cout<<"ky tu: "<<kt<<endl<<"xuat hien: "<<res;
}
int main() {
	char c[1000], i;
	cout<<"nhap ky tu: ";
	gets(c);
	mang(i,c);
	
}

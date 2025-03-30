#include <iostream>
using namespace std;

void sosanh(char s1[], char s2[])
{
	int i =0 ; 
	while(s1[i] != '\0') {
    i++;
   	}
        if(s1[i] < s2[i]) cout<<"chuoi 2 dai hon";
        else if( s1[i] > s2[i] ) cout<<"chuoi 1 dai hon";
        else cout<<"2 chuoi bang nhau";
}
int main()
{
    char s1[20], s2[20];               
    cout<<"chuoi s1: ";
    gets(s1);
    cout<<"chuoi s2: ";
    gets(s2);
	sosanh(s1,s2);
    return 0;
}

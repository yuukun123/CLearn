#include <iostream>
#include <string.h >
using namespace std;

int main(){
	
	char s1[20], s2[20];               
	int i =0 ;  
   cout<<"Enter s1: ";
   gets(s1);
   cout<<"Enter s2: ";
   gets(s2);
   int j = 0, n1, n2;
   n1 = strlen(s1);
   n2 = strlen(s2);
   
   for(i = n1; i<n1+n2; i++ ) {
      s1[i] = s2[j];
      j++;
   }
   s1[i] = '\0';
   cout<<endl<<"Ket qua sau khi noi chuoi la: "<<s1;
 
   return 0;
}




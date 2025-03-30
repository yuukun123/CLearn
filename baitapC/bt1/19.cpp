#include <iostream>
using namespace std;
int main() {
   char s1[] = "lap trinh";    
   char s2[10];                 
   int length = 0;
   while(s1[length] != NULL) {
      s2[length] = s1[length];
      length++;
   }
   s2[length] = NULL;
   cout<<"Chuoi s1: "<<s1<<endl;
   cout<<"Chuoi duoc sao chep = "<<s2;
 
   return 0;
}


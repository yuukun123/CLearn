#include<iostream>
using namespace std;

void str_reverse(char str[]) {
  int lo = 0, length;
  for (length = 0; str[length] != NULL ; length++) {} 
  while ( lo < length ) {
    --length;
    char tmp = str[lo];
    str[lo] = str[length];
    str[length] = tmp;
    ++lo;
  }
}

int main() {
    char str[100];
    cout << "Nhap chuoi: ";
    cin >>  str;
    str_reverse(str);
    cout << "Chuoi viet nguoc: "<< str;
    return 0;
}

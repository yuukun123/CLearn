#include<bits/stdc++.h>
using namespace std;
char str[50], x[50], y[50];

void replace_str(){
	int s_ = 0, x_ = 0,  y_ = 0;
	while(str[s_] != '\0') s_++;
	while(x[x_] != '\0') x_++;
	while(y[y_] != '\0') y_++;

	for(int i = 0; i <= s_ - x_; i++){
		bool find = true;
		for(int j = 0; j < x_; j++){
			if( str[i+j] != x[j] ){
				find = false;
				break;
			}
		}
		if(find){
			for(int j = 0; j < y_; j++){
				str[i+j] = y[j];
			}
			for(int j = i + y_; j <= s_ - x_ + y_; j++){
				str[j] = str[j + x_ - y_ ];
			}
			s_ = s_ - x_ + y_;
			i += y_ - 1;
		}
	} str[s_] = '\0';
	cout<<str<<endl;
}

int main(){
	fflush(stdin);
	gets(str); gets(x); gets(y);
	replace_str();
}
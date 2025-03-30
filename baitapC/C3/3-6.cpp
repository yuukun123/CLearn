#include<bits/stdc++.h>
using namespace std;

#define SWAP(type,x,y) do{type tmp = x; x = y; y = tmp;} while(0)
struct SV{
	int id;
	char lastName[50], firstName[50];
}; int n; 

void in_arr(SV *x){
	for(int i = 0; i < n; i++){
		cout<<"  id: "; cin>>(x+i)->id; 
		cout<<"  last name: "; cin>>(x+i)->lastName;
		cout<<"  first name: "; cin>>(x+i)->firstName;
		cout<<endl;
	} 
}

void out_arr(SV* x){
	for(int i = 0; i < n; i++){
		cout<<"-------------------Thong tin-------------------"<<endl<<endl;
		cout<<"  id: "<<(x+i)->id<<endl; 
		cout<<"  last name: "<<(x+i)->lastName<<endl;
		cout<<"  first name: "<<(x+i)->firstName<<endl<<endl<<endl;
	}
}

int strLen(char x[]){
	int i = 0;      
	while(x[i] != '\0') {
	    i++;
	} return i;
}

int strCmp(char *s, char *t){
    int len1 = strLen(s), len2 = strLen(t);
    int min_len = len1 < len2 ? len1 : len2;
    for(int i = 0; i < min_len; i++){
        if(s[i] != t[i]){
            if(s[i] > t[i])
                return 1;
            else  return -1;
        }
    }
    if(len1 < len2) return -1;
    else if(len1 > len2) return 1;
    else return 0;
}

void sort(SV* x){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++)
			if( strCmp( (x+i)->firstName, (x+j)->firstName ) < 0 )
				SWAP(SV, *(x+i), *(x+j) );
	}
	cout<<" sau khi sap xep theo ten tang dan: "<<endl<<endl;
	out_arr(x);
}

int main(){
	cin>>n; cout<<endl;
	SV* x = new SV[n+1];
	in_arr(x); out_arr(x);
	sort(x);
	delete x;
}
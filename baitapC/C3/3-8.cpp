#include<bits/stdc++.h>
using namespace std;

#define SWAP(type,x,y) do{type tmp = x; x = y; y = tmp;} while(0)
struct SV{
	int markE, markN, markC, sumMark, sumMark1;
	char id[50], name[50];
}; int n; 

void in_arr(SV* x){
	for(int i = 0; i < n; i ++){
		cout<<" id: "; cin>>(x+i)->id;
		cout<<" name: "; cin>>(x+i)->name;
		cout<<" markE: "; cin>>(x+i)->markE;
		cout<<" markN: "; cin>>(x+i)->markN;
		cout<<" markC: "; cin>>(x+i)->markC;
		(x+i)->sumMark = (x+i)->markE + (x+i)->markN + (x+i)->markC;
		cout<<endl;
	}
}

void out_arr(SV* x){
	cout<<" -----------------thong tin-----------------"<<endl<<endl;
	for(int i = 0; i < n; i ++){
		cout<<"  id: "<<(x+i)->id<<endl;
		cout<<"  name: "<<(x+i)->name<<endl;
		cout<<"  markE: "<<(x+i)->markE<<endl;
		cout<<"  markN: "<<(x+i)->markN<<endl;
		cout<<"  markC: "<<(x+i)->markC<<endl;
		cout<<"  sum mark: "<<(x+i)->sumMark<<endl<<endl;
		cout<<"--------------------------------------------"<<endl<<endl;
	}
}

void findMark(SV* x){
	cout<<"Sinh vien co diem trong 3 mon nho hon 5"<<endl<<endl;
	for(int i = 0; i < n; i++){
		if( (x+i)->markE < 5 || (x+i)->markN < 5 || (x+i)->markC < 5 ){
			cout<<"  id: "<<(x+i)->id<<endl;
			cout<<"  name: "<<(x+i)->name<<endl;
			cout<<"  markE: "<<(x+i)->markE<<endl;
			cout<<"  markN: "<<(x+i)->markN<<endl;
			cout<<"  markC: "<<(x+i)->markC<<endl;
			cout<<"  sum mark: "<<(x+i)->sumMark<<endl<<endl;
			cout<<"--------------------------------------------"<<endl<<endl;
		}
	}
}

void compair(SV* x){
	int cnt = 0, cnt1 = 0;
	for(int i = 0; i < n; i++){
		if( (x+i)->markE >= 5 && (x+i)->markN >= 5 && (x+i)->markC >= 5 )
			cnt++;
	} cout<<"Sinh vien co diem 3 mon lon hon hoac bang 5: "<<cnt++<<endl<<endl;

	for(int i = 0; i < n; i++){
		(x+i)->sumMark1 = (x+i)->markC + (x+i)->markN;
		if( (x+i)->sumMark1 >= 12 )
			cnt1++;
	} cout<<"Sinh vien co tong diem 2 mon co ban va co so lon hon 12: "<<cnt1<<endl<<endl;
}

void maxMark(SV* x){
	cout<<"Sinh vien co tong diem 3 mon lon nhat: "<<endl<<endl;
	int max = INT_MIN;
	for(int i = 0; i < n; i++){
		if( (x+i)->sumMark > max )
			max = (x+i)->sumMark;
	}
	for(int i = 0; i < n; i++){
		if( max == (x+i)->sumMark ){
			cout<<"  id: "<<(x+i)->id<<endl;
			cout<<"  name: "<<(x+i)->name<<endl;
			cout<<"  markE: "<<(x+i)->markE<<endl;
			cout<<"  markN: "<<(x+i)->markN<<endl;
			cout<<"  markC: "<<(x+i)->markC<<endl;
			cout<<"  sum mark: "<<(x+i)->sumMark<<endl<<endl;
			cout<<"--------------------------------------------"<<endl<<endl;
		}
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
            else 
                return -1;
        }
    }
    if(len1 < len2) return -1;
    else if(len1 > len2) return 1;
    else return 0;
}

void findSv(SV* x){
	char y[50]; 
	cout<<"nhap id sv: "; cin>>y; 
	cout<<endl;
	for(int i = 0; i < n; i++){
		if( strCmp( (x+i)->id, y ) == 0 ){
			cout<<"  id: "<<(x+i)->id<<endl;
			cout<<"  name: "<<(x+i)->name<<endl;
			cout<<"  markE: "<<(x+i)->markE<<endl;
			cout<<"  markN: "<<(x+i)->markN<<endl;
			cout<<"  markC: "<<(x+i)->markC<<endl;
			cout<<"  sum mark: "<<(x+i)->sumMark<<endl<<endl;
			cout<<"--------------------------------------------"<<endl<<endl;
		}
	}
}

void sortId(SV* x){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++)
			if( strCmp( (x+i)->id ,(x+j)->id ) > 0 )
				SWAP(SV, *(x+i), *(x+j) );
	}
	cout<<endl<<" sau khi sap xep theo id tang dan: "<<endl;
	out_arr(x);
}

int main(){
	cout<<"nhap so sinh vien: "; cin>>n; cout<<endl;
	SV* x = new SV[n+1];
	in_arr(x); out_arr(x);
	cout<<endl;
	findMark(x);
	compair(x);
	maxMark(x);
	findSv(x);
	sortId(x);
	delete x;
}
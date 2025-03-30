#include<bits/stdc++.h>
using namespace std;

#define SWAP(type,x,y) do{type tmp = x; x = y; y = tmp;} while(0)
struct SV{
	int id, mark, mark1, mark2, sumMark;
	char name[50];
}; int n; 

void in_arr(SV* x){
	cout<<"nhap so sinh vien: "; cin>>n; cout<<endl;
	for(int i = 0; i < n; i ++){
		cout<<" id: "; cin>>(x+i)->id;
		cout<<" name: "; cin>>(x+i)->name;
		cout<<" mark: "; cin>>(x+i)->mark;
		cout<<" mark1: "; cin>>(x+i)->mark1;
		cout<<" mark2: "; cin>>(x+i)->mark2;
		(x+i)->sumMark = (x+i)->mark + (x+i)->mark2 + (x+i)->mark2;
		cout<<endl;
	}
}

void out_arr(SV* x){
	cout<<" -----------------thong tin-----------------"<<endl<<endl;
	for(int i = 0; i < n; i ++){
		cout<<"  id: "<<(x+i)->id<<endl;
		cout<<"  name: "<<(x+i)->name<<endl;
		cout<<"  mark: "<<(x+i)->mark<<endl;
		cout<<"  mark1: "<<(x+i)->mark1<<endl;
		cout<<"  mark2: "<<(x+i)->mark2<<endl;
		cout<<"  sum mark: "<<(x+i)->sumMark<<endl<<endl;
		cout<<"--------------------------------------------"<<endl<<endl;
	}
}

void findMark(SV* x){
	for(int i = 0; i < n; i++){
		if( (x+i)->mark < 5 || (x+i)->mark1 < 5 || (x+i)->mark2 < 5 ){
			cout<<endl<<" SV co diem thap hon 5"<<endl;
			cout<<"  id: "<<(x+i)->id<<endl;
			cout<<"  name: "<<(x+i)->name<<endl;
			cout<<"  mark: "<<(x+i)->mark<<endl;
			cout<<"  mark1: "<<(x+i)->mark1<<endl;
			cout<<"  mark2: "<<(x+i)->mark2<<endl;
			cout<<"---------------------------------------------"<<endl<<endl;
		}
	}
}

void findMax(SV* x){
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
			cout<<"  mark: "<<(x+i)->mark<<endl;
			cout<<"  mark1: "<<(x+i)->mark1<<endl;
			cout<<"  mark2: "<<(x+i)->mark2<<endl;
			cout<<"  sum mark: "<<(x+i)->sumMark<<endl<<endl;
			cout<<"--------------------------------------------"<<endl<<endl;
		}
	}
}

void sorfMark(SV* x){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if( (x+i)->sumMark > (x+j)->sumMark )
				SWAP( SV, *(x+i), *(x+j) );
		}
	}
	cout<<"danh sach SV co tong diem 1 va 2 cao nhat"<<endl;
	out_arr(x);
}

int main(){
	SV* x = new SV[5];
	int c;
	do{
		cout<<endl<<endl<<endl;;
		cout<<"-----------------------------------------------------"<<endl;
		cout<<"\t1. nhap sv "<<endl;
		cout<<"\t2. xem danh sach "<<endl;
		cout<<"\t3. SV co diem duoi 5"<<endl;
		cout<<"\t4. SV co tong diem cao nhat"<<endl;
		cout<<"\t5. xep sap 2 mon chuyen nganh tang dan"<<endl;
		cout<<endl<<"chon: "; cin>>c; cout<<endl;
		if( c == 1 ){
			in_arr(x);
		}
		if( c == 2 ){
			out_arr(x);
		}
		if( c == 3 ){
			findMark(x);
		}
		if( c == 4 ){
			findMax(x);
		}
		if( c == 5 ){
			sorfMark(x);
		}
	} while ( c != 0 );
	delete x;
}
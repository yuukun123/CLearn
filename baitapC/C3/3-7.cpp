#include<bits/stdc++.h>
using namespace std;

#define SWAP(type,x,y) do{type tmp = x; x = y; y = tmp;} while(0)
struct EMPLOY{
	int id, born ,salary, reward, netSalary;
	char name[50];
}; int n; 

void in_arr(EMPLOY* x){
	for(int i = 0; i < n; i++){
		cout<<" id: "; cin>>(x+i)->id;
		cout<<" name: "; cin>>(x+i)->name;
		cout<<" born: "; cin>>(x+i)->born;
		cout<<" salary: "; cin>>(x+i)->salary;
		cout<<" reward: "; cin>>(x+i)->reward;
		(x+i)->netSalary = (x+i)->salary + (x+i)->reward;
		cout<<endl;
	}
}

void out_arr(EMPLOY* x){
	cout<<" -----------------thong tin-----------------"<<endl<<endl;
	for(int i = 0; i < n; i ++){
		cout<<"  id: "<<(x+i)->id<<endl;
		cout<<"  name: "<<(x+i)->name<<endl;
		cout<<"  born: "<<(x+i)->born<<endl;
		cout<<"  salary: "<<(x+i)->salary<<endl;
		cout<<"  reward: "<<(x+i)->reward<<endl;
		cout<<"  net salary: "<<(x+i)->netSalary<<endl<<endl;
		cout<<"--------------------------------------------"<<endl<<endl<<endl;
	}	
}

void sortSalary(EMPLOY* x){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++)
			if( (x+i)->salary > (x+j)->salary )
				SWAP(EMPLOY, *(x+i), *(x+j) );
	}
	cout<<" sau khi sap xep theo luong tang dan: "<<endl<<endl;
	out_arr(x);
}

void sortId(EMPLOY* x){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++)
			if( (x+i)->id > (x+j)->id )
				SWAP(EMPLOY, *(x+i), *(x+j) );
	}
	cout<<" sau khi sap xep theo id tang dan: "<<endl<<endl;
	out_arr(x);
}

int main(){
	cout<<"nhap so cong nhan: "; cin>>n; cout<<endl;
	EMPLOY* x = new EMPLOY[n+1];
	in_arr(x); out_arr(x);
	sortSalary(x);
	sortId(x);
	delete x;
}
#include <bits/stdc++.h>
using namespace std;

struct Food {
	char name[50];
	double price;
	int quantity;
}F[20];

struct Employee {
	int id;
	char name[50];
	double salary;
}E[20]; 
int n, u, b[50], p, t; double s = 0, m, c;

//Foods
void add_1_food (Food* x){
	cout<<endl<<"food name: "; fflush(stdin); gets(x->name); 
	cout<<"price: "; cin>>x->price;
	cout<<"quantity: "; cin>>x->quantity;
}
void show_1_food (Food* x){
	if ( x->quantity == 0 )
		cout<<"thuc an nay da het ";
	else {
		cout<<"food name: "<<x->name
		<<"price: "<<x->price
		<<"quantity: "<<x->quantity;
	}

}	
void input_food(Food* x, int &n)
{
	do{
		cout<<"Enter the number of foods: "; cin>>n;
	}while(n <= 0 || n >100 );
	for (int i = 0; i < n; i++){
		cout<<endl<<"	nhap sach thu : "<<i+1;
		add_1_food(F+i);
	}
}
void show_food(Food* x, int n)
{
	for (int i = 0; i < n; i++){
		cout<<endl<<"|    food information "<<i+1<<"    |	";
		show_1_food(F+i);
	}
}

//Employyees
void add_1_employee (Employee* y){
	cout<<endl<<"employee name: "; fflush(stdin); gets(y->name); 
	cout<<"id: "; cin>>y->id;
	cout<<"salary: "; cin>>y->salary;
}
void show_1_employee (Employee* y){
	cout<<"employee name: "<<y->name<<"    |    "
	<<"id: "<<y->id<<"    |    "
	<<"salary: "<<y->salary<<"    |"<<endl;
}
void input_employee(Employee* y, int &p)
{
	do{
		cout<<"\n\n\n"<<"Enter the number of employee: "; cin>>p;
	}while(u <= 0 || u >100);
	for (int i = 0; i < u; i++){
		cout<<endl<<"	employee : "<<i+1;
		add_1_employee(E+i);
	}
}
void show_employee(Employee* y, int u)
{
	for (int i = 0; i < u; i++){
		cout<<endl<<"|    employee information "<<i+1<<"    |";
		show_1_employee(E+i);
	}
}

//ODER FOODS
int gh=0;
void cart(int n,int m){
        gh+=m;
        if(gh>30){cout<<"Gio hang da dat gioi han!!"<<'\n'<<'\n';}
        else {
        	b[n]+=m;
        	s=s+(F->price*m);
	}
}
void order_food(Food* x, int n)
{
	cin>>p;
	if ( p > n ){
		cout<<"khong du sach de mua";
	}
	else{
			
		for( int i = 0; i < p; i++){
			cout<<"chon ma sach: "; cin>>c;
			if ( c > p )
				cout<<"khong co sach trong thu vien ";
			else {
				
				cout<<"nhap so luong: "; cin>>m;
				if( m > x->quantity) cout<<"khong du so luong sach ";
				else cart(c,m);	
			}cout<<"mua thanh cong!!!"<<endl<<endl;
		}
	}
}

//SHOW BILL FOODS
void show_bill(Food* x)
{
	for ( int i = 0; i < p; i++ )
	{
		if ( b[i] != 0)
		{
			show_1_food(F+i); cout<<"so luong mua: "<<b[i]<<endl;				
		}
	} cout<<endl<<"gia tien cua don hang: "<<s<<endl;
	for(int i = 0; i < n; i++){
		if( F[i].quantity >= m ){
			F[i].quantity = F[i].quantity - m;
			cout<<endl<<"so luong sach con lai "<<F->quantity;
		}
	}
}
//MENU SYSTEM
void Menu(){
	input_food(F,n);
	int option;
	system("cls");
	do{					
		cout<<"\n\n\t	   ====Menu===="
		<<"\n\t_________________________________"		
		<<"\n\t|  1. danh sach mon an 		|"
		<<"\n\t|  2. nhap danh sanh nhan vien	|" 
		<<"\n\t|  3. danh sanh nhan vien	|"
		<<"\n\t|  4. dat hang			|"	
		<<"\n\t|  5. xem don hang 		|"
		<<"\n\t|  0. thoat 			|"
		<<"\n\t|_______________________________|"
		<<"\n\n moi ban chon: "; cin>>option;
		switch( option ) {
			case 0: break;
			case 1:{
				cout<<endl<<"\t\t\t\t\t________MENU FOODS________"<<endl<<endl;
				show_food(F,n);
				break;
			}
			case 2:{
				input_employee(E,u);
				break;
			}
			case 3:{
				show_employee(E,u);
				break;
			}
			case 4:{
				cout<<endl<<"\t\t\t\t\t\t________mua sach________"<<endl<<endl;
				cout<<"nhap so luong sach muon mua: ";
				order_food(F,n);
				break;
			}
			case 5:{
				cout<<endl<<"\t\t\t\t________xem don hang________"<<endl<<endl;
				show_bill(F);
				break;
			}
		}
	}while (option != 0);
}

int main() {
	Menu();
}
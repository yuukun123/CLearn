#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

struct book {
	char title[30], author[30];
	double price, quantity;
}a[100]; 
int n, b[100], p, t; double s = 0, money, m, c;

void add_1_book(book &x)
{
	cout<<endl<<"book title: "; fflush(stdin); gets(x.title); 
	cout<<"author name: "; fflush(stdin); gets(x.author);
	cout<<"price: "; cin>>x.price;
	cout<<"quantity: "; cin>>x.quantity;
}
void show_1_book(book x)
{
	cout<<"\t|-------------------------|---------------------|-----------------------|-------------------------|";
	cout<<endl<<"\t|"<<"\tbook title: "<<x.title<<"\t  |"
	<<"\tauthor name: "<<x.author<<"\t|"
	<<"\tprice: "<<x.price<<"\t|"
	<<"\tquantity: "<<x.quantity<<endl;
}
void input_book(book x[], int &n)
{
	do{
		cout<<"Enter the number of books: "; cin>>n;
	}while(n <= 0 || n >100 );
	for (int i = 0; i < n; ++i){
		cout<<endl<<"	nhap sach thu : "<<i+1;
		add_1_book(a[i]);
	}
}

void show_book(book x[], int n)
{
	for (int i = 0; i < n; ++i){
		cout<<"|--------------------------|--------------------|---------------------|----------------------|----------------|-------------------|";
		cout<<endl<<"|    book information "<<i+1<<"    |    "
		<<"book code: "<<i<<"    |    "
		<<"book title: "<<x[i].title<<"    |    "
		<<"author name: "<<x[i].author<<"    |    "
		<<"price: "<<x[i].price<<"    |    "
		<<"quantity: "<<x[i].quantity<<"    |"<<endl;
	}
}

void add_book(book x[], int &n)
{
	cout<<"nhap so sach muon them: "; cin>>t;
	if ( t + n > 100) cout<<"sach trong thu vien da day ";
	else{
		for ( int i = 0; i < t; i++){
			cout<<endl<<"nhap thong tin sach them"<<endl;
			add_1_book(x[n]);
			n++;
		}
	}
}

void find_book(book x[], int n , char tensach[])
{
	int i;
	for( i = 0; i <= n; ++i)
	{
		if( strcmp(x[i].title,tensach) == 0 || strcmp(x[i].author,tensach) == 0)
		{
			cout<<endl<<"cac sach hoac tac gia co ten: "<<tensach<<endl<<endl;
			show_1_book(x[i]);
		}
	}	if (i > n ) cout<<"khong co sach hoac tac gia muon tim";
}

void donate_money()
{
	do{
		cout<<"nhap so tien nap vao: "; cin>>money; cout<<endl;
	}while(money < 0);
}
void show_money()
{
	cout<<endl<<"so tien trong vi "<<money;
}

int gh=0;
void cart(int n,int m){
        gh+=m;
        if(gh>30){cout<<"Gio hang da dat gioi han!!"<<'\n'<<'\n';}
        else {
        	b[n]+=m;
        	s=s+(a[n].price*m);
	}
}

void order_book(book x[], int n)
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
				if( m > x[i].quantity) cout<<"khong du so luong sach ";
				else cart(c,m);
			}cout<<"mua thanh cong!!!";
		}
	}
}

void show_bill()
{
	for ( int i = 0; i < p; i++ )
	{
		if ( b[i] != 0)
		{
			cout<<endl<<"quyen sach "<<i<<endl;
	 		cout<<"ten sach: "<<a[i].title<<endl;
	 		cout<<"tac gia: "<<a[i].author<<endl;
	 		cout<<"gia tien: "<<a[i].price<<endl;
	 		cout<<"so luong: "<<b[i]<<endl;
		}
	} cout<<endl<<"gia tien cua don hang: "<<s<<endl;
	for(int i = 0; i < n; i++){
		if( a[i].quantity > m ){
			a[i].quantity = a[i].quantity - m; 
			cout<<endl<<"so luong sach con lai "<<a[i].quantity;
		}
	}
	if( money > s ){
		money -= s;
		cout<<endl<<"so tien con lai trong vi "<<money;	
	}

	else
		cout<<endl<<"ban khong du tien de mua sach ";
}

void Menu(){
	donate_money();
	input_book(a,n);
	int option;
	system("cls");
	do{					
		cout<<"\n\n\t	   ====Menu===="
		<<"\n\t_________________________________"		
		<<"\n\t|  1. nhap sach muon them 	|" 
		<<"\n\t|  2. danh sach quyen sach 	|"
		<<"\n\t|  3. xem tien trong vi		|" 
		<<"\n\t|  4. tim kiem sach 		|"
		<<"\n\t|  5. dat hang 			|"
		<<"\n\t|  6. xem don hang 		|"
		<<"\n\t|  0. thoat 			|"
		<<"\n\t|_______________________________|"
		<<"\n\n moi ban chon: "; cin>>option;
		switch( option ) {
			case 0: break;
			case 1:{
				add_book(a,n);
				break;
			}
			case 2:{
				cout<<endl<<"\t\t\t\t\t\t________thong tin sach________"<<endl<<endl;
				show_book(a,n);
				break;
			}
			case 3:{
				show_money();
				break;
			}
			case 4:{
				cout<<endl<<"\t\t\t\t\t\t________tim kiem sach________"<<endl<<endl;
				char tensachmuontim[20];
				cout<<endl<<"nhap ten sach hoac tac gia: ";
				fflush(stdin); gets(tensachmuontim);
				find_book(a,n,tensachmuontim);
				break;
			}
			case 5:{
				cout<<endl<<"\t\t\t\t\t\t________mua sach________"<<endl<<endl;
				cout<<"nhap so luong sach muon mua: ";
				order_book(a,n);
				break;
			}
			case 6:{
				cout<<endl<<"\t\t\t\t\t\t________xem don hang________"<<endl<<endl;
				show_bill();
				break;
			}
		}
	}while (option != 0);
}

int main() {
	Menu();
}
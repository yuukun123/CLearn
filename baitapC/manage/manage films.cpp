#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct Films {
	char name[50];
	char title[100];
	char genre[50];
	char filePath[50];
};
int n, t; int m;

void add_1_films(Films* x){
	cout<<endl<<"films name: "; fflush(stdin); gets(x->name);
	cout<<"title: "; fflush(stdin); gets(x->title);
	cout<<"moive genre: "; gets(x->genre);
}

void show_1_films (Films* x){
	cout<<endl<<endl<<"\tfilms name: "<<x->name<<endl
	<<"\ttitle: "<<x->title<<endl
	<<"\tgenre: "<<x->genre<<endl<<endl;
}

void input_films(Films* x){
	for (int i = 0; i < n; i++){
		cout<<endl<<"	Enter number of films: "<<i+1;
		add_1_films(x+i);
	} 
}

void show_films(Films* x){
	for (int i = 0; i < n; i++){
		cout<<endl<<"  |    food information "<<i+1<<"    |	";
		show_1_films(x+i);
	}cout<<endl;
}

void find_films(Films *x, char films_name[]){
	cout<<endl<<"cac sach hoac tac gia co ten: "<<films_name<<endl<<endl;
	for(int i = 0; i <= n; i++){
		if( strcmp((x+i)->name,films_name) == 0 ) 
			show_1_films(x+i);
		else {
			cout<<"  khong co sach hoac tac gia muon tim"; break;
		}
	}	
}

void delete_films(Films* x){
	int u;
	cout<<endl<<endl<<"nhap film muon xoa: "; cin>>u;
	for(int i = u - 1; i < n-1; i++){
		*(x+i) = *(x+i+1);
	} --n;
	show_films(x);
}

void add_films(Films* x){
	cout<<endl<<endl<<"nhap so film muon them: "; cin>>t;
	if ( t + n > 100) cout<<"film trong thu vien da day ";
	else{
		for( int i = 0; i < t; i++){
			cout<<endl<<"nhap thong tin film them"<<endl;
			add_1_films(x+n);
			n++;
		}
	}
}

void repair_title(Films* x){
	int found = 0;
	cout<<"nhap vi tri films muon thay doi tieu de: ";cin>>t;
	for(int i = 0; i < n; i++){
		if( i == t - 1){
			found = 1;
			cin>>(x+i)->genre;
			break;
		}
	}
	if(found == 0) cout<<"khong co the loai do ";
}

void find_filmsTitle(Films* x){
	char nameTitle[50]; 
	cout<<endl<<endl<<"nhap tieu de muon tim kiem: "; cin>>nameTitle;
	for(int i = 0; i < n; i++){
		if( strcmp( (x+i)->title,nameTitle ) == 0)
			show_1_films(x+i);
		else cout<<"khong co film tieu de "<<nameTitle;
	} 
}

//MENU SYSTEM
void Menu(){
	do{
		cout<<"Enter the number of films: "; cin>>n;
	} while(n <= 0 || n >100 );
	Films* x = new Films[n+1];
	input_films(x);

	int option;
	system("cls");
	do{					
		cout<<"\n\n\t	  ====Menu===="
		<<"\n\t_________________________________"		
		<<"\n\t|  1. danh sach films 		|"
		<<"\n\t|  2. tim kiem films theo ten	|" 
		<<"\n\t|  3. xoa films khoi danh sach	|"
		<<"\n\t|  4. them films		|"	
		<<"\n\t|  5. chinh sua chu de films 	|"
		<<"\n\t|  6. tim films theo chu de	|"		
		<<"\n\t|  0. thoat 			|"
		<<"\n\t|_______________________________|"
		<<"\n\n moi ban chon: "; cin>>option;
		switch( option ) {
			case 0: break;
			case 1:{
				cout<<endl<<"\t\t\t\t\t________MENU FILMS________"<<endl<<endl;
				show_films(x);
				break;
			}
			case 2:{
				char films_name[50];
				cout<<endl<<"  Enter films name or genre you want find: ";
				fflush(stdin); gets(films_name);
				find_films(x,films_name);
				break;
			}
			case 3:{
				do{
					delete_films(x);
					cout<<endl<<endl<<"chon 'y' tiep tuc 'n' de dung: "<<endl;
					m = getch();
				}while( m == 'y' );
				break;
			}
			case 4:{
				do{
					add_films(x);
					cout<<endl<<endl<<"chon 'y' tiep tuc 'n' de dung: "<<endl;
					m = getch();
				}while( m == 'y' );
				break;
			}
			case 5:{
				do{
					repair_title(x);
					cout<<endl<<endl<<"chon 'y' tiep tuc 'n' de dung: "<<endl;
					m = getch();
				}while( m == 'y' );
				break;
			}
		}
	} while (option != 0);
}

int main() {
	Menu();
}
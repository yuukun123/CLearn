#include <bits/stdc++.h>
using namespace std;

struct book {
	string title, author, book_code, publishing, book_classification;
	int num_of_page;
	float price;
}a[100]; char c;

bool cmp1(book d, book b)
{
	return d.publishing < b.publishing;
}

bool cmp2(book d, book b)
{
	return d.author < b.author;
}
 
void input_book(book a[], int n)
{
	c = getchar();
	for (int i = 0; i < n; ++i){
		// c = getchar();
		// getline(cin,a[i].book_code);
		// getline(cin,a[i].title);
		// getline(cin,a[i].book_classification);
		getline(cin,a[i].publishing);
		getline(cin,a[i].author);
		// cin>>a[i].num_of_page;
		// cin>>a[i].price;
	}
}

void show_book(book a[], int n)
{
	for (int i = 0; i < n; ++i){
		if( a[i].author != a[i-1].author){
			cout<<"\n--------------------------------------\n";
			cout<<"sach cho tac gia: "<<a[i].author<<endl;
		}
		// cout<<endl<<"book code: "<<a[i].book_code<<endl;
		// cout<<"book title: "<<a[i].title<<endl;
		// cout<<"book classification: "<<a[i].book_classification<<endl;
		 cout<<"publishing company: "<<a[i].publishing<<endl;
		cout<<"author name: "<<a[i].author<<endl;
		// cout<<"number of page: "<<a[i].num_of_page<<endl;
		// cout<<"price: "<<a[i].price<<""<<endl;
	}
}

void author_max(book a[], int n)
{
	int i = 0, max = 0, index = 0;
	int frequency;
	while(i < n){
		frequency = 1;
		while( a[i].author == a[i+1].author ){
			frequency++; 
			i++;
		}
		if( max < frequency){
			max = frequency;
			index = i;
		} i++;
	}
	cout<<endl<<"tac gia co nhieu sach nhat: "<<a[index].author;
}

void publishing_max(book a[], int n)
{
	int i = 0, max = 0, index = 0;
	int frequency;
	while(i < n){
		frequency = 1;
		while( a[i].publishing == a[i+1].publishing ){
			frequency++; 
			i++;
		}
		if( max < frequency){
			max = frequency;
			index = i;
		} i++;
	}
	cout<<endl<<"NXB co nhieu sach nhat: "<<a[index].publishing;
}

void num_of_page_max(book a[], int n)
{
	string max_author; 
	int max_num_of_page = 0, i = 0; 
	while( i < n ){
		string current_author = a[i].author;
		int current_num_of_page = a[i].num_of_page;
		for(int j = i + 1; j < n; ++j){
			if( a[i]. author == current_author)
				current_num_of_page += a[i].num_of_page;
		}

		if ( current_num_of_page > max_num_of_page ){
			max_num_of_page = current_num_of_page; 
			max_author = current_author;
		} i++;
	}
	cout<<endl<<"tac gia co tong so trang nhieu nhat: "<<max_author;
}

void book_classification_max(book a[], int n)
{
	string max_book_classification; 
	int max_price = 0, i = 0; 
	while( i < n ){
		string current_book_classification = a[i].book_classification;
		int current_price = a[i].price;
		for(int j = i + 1; j < n; ++j){
			if( a[i].book_classification == current_book_classification)
				current_price += a[i].price;
		}

		if ( current_price > max_price ){
			max_price = current_price; 
			max_book_classification = current_book_classification;
		} i++;
	}
	cout<<endl<<"loai sach co tong gia tri nhieu nhat: "<<max_book_classification;
}

void author_publishing_max(book a[], int n)
{
	int i = 0, max = 0, index = 0;
	int frequency;
	while(i < n){
		frequency = 0;
		while( a[i].publishing == a[i+1].publishing ){
			frequency++; 
			i++;
		}
		if( max < frequency){
			max = frequency;
			index = i;
		} i++;
	}
	cout<<endl<<"tac gia xuat ban o nhieu NXB sach nhat: "<<a[index].author;
}

int main(){
	int n;
	freopen("sach.inp","r",stdin);
	freopen("sach.out","w",stdout);
	cin>>n;
	input_book(a,n);
	sort(a,a+n,cmp2);
	show_book(a,n);

	author_max(a,n);
	publishing_max(a,n);

	num_of_page_max(a,n);
	book_classification_max(a,n);

	author_publishing_max(a,n);
}
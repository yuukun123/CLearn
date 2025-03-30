#include<bits/stdc++.h>
using namespace std;

struct book{
	char id[50], name[50], LoaiS[20] ,NXB[30], author[50];
	int page;
	float price;
}b;

struct Node{
	book data;
	Node* next;
};

Node* makenode(book b){
	Node* p = new Node;

	if (p == NULL){
	     cout<< "\nKhong du bo nho.";
	     return NULL;
	}

	p->data.page = b.page;
	p->data.price = b.price;
	strcpy(p->data.id, b.id);
	strcpy(p->data.name, b.name);
	strcpy(p->data.LoaiS, b.LoaiS);
	strcpy(p->data.NXB, b.NXB);
	strcpy(p->data.author, b.author);
	p->next = NULL;
	return p;
}

struct List {
	Node* head;
	Node* tail;
};

void init(List& l){
	l.head = nullptr;
	l.tail = nullptr;
}

int n;

void insert(List& l, Node* p){
	if(l.head == nullptr && l.tail == nullptr){
		l.head = p;
		l.tail = p;
	}
	l.tail->next = p; 
	l.tail = p;
}

void in_1(book& b){
	cin>>b.id;
	cin>>b.name;
	cin>>b.LoaiS;
	cin>>b.NXB;
	cin>>b.author;
	cin>>b.page;
	cin>>price;
}
void in(List& l, book b){
	cin>>n;
	for(int i = 0; i < n; i++){
		in_1(b);
		Node* p = makenode(b);
		insert(l,p);
	}
}

void out_1(book b){
	cout<<b.id<<endl;
	cout<<b.name<<endl;
	cout<<b.LoaiS<<endl;
	cout<<b.NXB<<endl;
	cout<<b.author<<endl;
	cout<<b.page<<endl;
	cout<<b.price<<endl;
}

void out(List l, book b){
	for(Node* p = l.head; p != nullptr; p = p->next){
		out_1(p->data);
	} cout<<endl;
}

void find(List l){
	Node* p;
	char x[50];
	fflush(stdin);
	gets(x);
	int cnt = 0;
	for(p = l.head; p != nullptr; p = p->next){
		if( strcmp(p->data.name,x) == 0 ){
			cnt++;
		}
	}
	if( cnt!= 0) 
		out_1(p->data);
	else cout<<"khong tim thay";
}

void find_max_page(List l, book b){
	int auBook[100] = {0};
	string auName[100];
	int numAuthor = 0;

	Node *p = l.head;
	while(p != nullptr){
		bool found = false;
		for(int i = 0; i < numAuthor; i++){
			if(auName[i] == p->author){
				auBook[i]++;
				found = true;
				break;
			}
		}
		if(!found){
			auName[numAuthor] = p->author;
			auBook[numAuthor]++;
			numAuthor++;
		} p = p->next;

		int maxBook= = 0;
		string mostProducedAuthor = "";
    for (int i = 0; i < numAuthors; i++) {
        if (authorBooks[i] > maxBooks) {
            maxBooks = authorBooks[i];
            mostProducedAuthor = authorNames[i];
        }
    }
    cout<< mostProducedAuthor;
}

// Hàm tìm nhà xuất bản xuất bản nhiều sách nhất
void findMostProducedPublisher(List l, book b) {
    // Sử dụng một mảng để lưu trữ số lượng sách của mỗi nhà xuất bản
    int publisherBooks[100] = {0};
    string publisherNames[100];
    int numPublishers = 0;
    
    // Đếm số lượng sách của mỗi nhà xuất bản
    Node* current = l.head;
    while (current != NULL) {
        bool found = false;
        for (int i = 0; i < numPublishers; i++) {
            if (publisherNames[i] == current->NXB) {
                publisherBooks[i]++;
                found = true;
                break;
            }
        }
        if (!found) {
            publisherNames[numPublishers] = current->NXB;
            publisherBooks[numPublishers]++;
            numPublishers++;
        }
        current = current->next;
    }
    
    // Tìm nhà xuất bản xuất bản nhiều sách nhất
    int maxBooks = 0;
    string mostProducedPublisher = "";
    for (int i = 0; i < numPublishers; i++) {
        if (publisherBooks[i] > maxBooks) {
            maxBooks = publisherBooks[i];
            mostProducedPublisher = publisherNames[i];
        }
    }
    return mostProducedPublisher;
}


int main(){
	freopen("text.inp","r",stdin);
	freopen("text.out","w",stdout);
	List l;
	init(l);
	in(l,b);
	out(l,b);
	find(l);
	find_max_page(l,b);
	findMostProducedPublisher(l,b);
}
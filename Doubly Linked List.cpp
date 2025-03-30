#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;
    Node(int val) : data(val), next(nullptr),back(nullptr) {}// khởi tạo 1 node mới với giá trị vall
};

void insertLast(Node*& head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if (head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->back = tail;
    tail = newNode;
}

void insertFirst(Node*& head,Node*& tail, int val){
	Node* newNode = new Node(val);
	if(head == nullptr){
		head = newNode;
		tail = newNode;
	}
	head->back = newNode;
	newNode->next = head;
	head = newNode;
}

void printList(Node* head){
	for(Node *p = head; p != nullptr; p = p->next)
        cout<<p->data<<" ";
    cout<<endl<<endl;
}

void search_count(Node *head,int x){
	int cnt = 0;
    for(Node *p = head; p != nullptr; p = p->next){
        if ( p->data == x)
            cnt++;
    }
    cout<<cnt<<endl;
}

void inserMid(Node*& head, int val){
	Node* newNode = new Node(val);
	newNode->next = head;
	if(head == nullptr && head->data > val ){
		while(head != nullptr){
			head->back = newNode;
		}
		head = newNode;
	}
	else{
		Node* p = head;
		while(p->next != nullptr && p->next->data <= val){
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;
	}
}

void deleteX(Node* &head, int x){
	Node *q, *p;
	// bool ok = false;
	while(head->data == x){
		p = head;;
		head = head->next;
		delete p;
		// ok = true;
	}
	p = head;
	while( p->next != NULL ){
		q = p->next;
		if( q->data == x ){
			p->next = q->next;
			delete q;
			// ok = true;
		}
		else p = p->next;
	}
}

void sortList(Node* head){
    for(Node* p = head; p->next != nullptr; p = p->next)
        for(Node* q = p->next; q != nullptr; q = q->next)
            if(p->data>q->data)
                swap(p->data,q->data);
}

void insertSort(Node* head, int x){
	int m; cin>>m;
	for(int j = 0; j < m; j++){
		cin>>x;
		inserMid(head,x);
		sortList(head);
	}
}

void reverse(Node* head ) {
   Node* back   = NULL;
   Node* current = head;
   Node* next;
   while (current != NULL) {
      next = current->next;  
      current->next = back;   
      back = current;
      current = next;
   }
   if(back != nullptr)
	   head = back;
}


int main(){
	Node* head = nullptr, *tail = nullptr;
    int x, n; cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>x;
	    insertLast(head,tail,x);  	
    }
    printList(head);

    cin>>x;
    search_count(head,x);

    cin>>x;
    deleteX(head,x);
    printList(head);

    insertSort(head,x);
    printList(head);

    reverse(head,tail);
    printList(head);
}
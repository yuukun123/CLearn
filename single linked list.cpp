 #include <iostream>
using namespace std;

// Khai báo cấu trúc của một nút trong danh sách liên kết đơn
struct Node {
    int data; float s = data * data;
    Node* next;
    Node(int val): data(val), next(nullptr) {}// khởi tạo 1 node mới với giá trị vall
};

void insertLast(Node*& head,Node *&tail, int val){
    Node *newNode = new Node(val);
    if (head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}

// Hàm để thêm một nút mới vào đầu danh sách liên kết đơn
void insertFirst(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head==nullptr){
        head=newNode;
        return;
    }
    newNode->next=head;
    head = newNode;
}

void inserMid(Node*& head, int val){
	Node* newNode = new Node(val);
	if(head == nullptr && head->data >= val){
		newNode->next = head;
		head = newNode;
	}
	else{
		Node* p = head;
		while(p->next != nullptr && p->next->data < val){
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;
	}
}

void inserList(Node*& head, Node*& tail, int x, int n){
    cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>x;
	    insertLast(head,tail,x);
    }
}

// Hàm để in danh sách liên kết đơn
void printList(Node* head) {
    for(Node *p = head; p != nullptr; p = p->next)
        cout<<p->data<<" ";
    cout<<endl;
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

void count(Node* head, int n, int x, int cnt){
    for(Node* p = head; p != nullptr; p = p->next) { // tìm và đếm phần tử giá trị bằng x
        if( p->data == x ){
            cnt++;
        }
	} cout<<cnt<<endl;
}

void sortA(Node *head){
    Node *p=head,*q;
    for(;p->next!=nullptr;p=p->next)
        for(q=p->next ; q !=nullptr;q=q->next)
            if(p->data > q->data)
                swap(p->data,q->data);
}

void insertSort(Node* head , int val){
	int m; cin>>m;
	for(int j = 0; j < m; j++){
		cin>>val;
		inserMid(head,val);
		sortA(head);
	}
}

void reverse(Node*& head){
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

void find_min(Node* head){
	Node* p = head;
	int pos = 0;
	for( ; p != nullptr; p = p->next){
		if( pos == 1 ){
			cout<<p->data<<endl;
		}
		pos++;
	}
}

void max_k(Node* head){
	int k; cin>>k;
	for(Node* p = head; p != nullptr; p = p->next){
		if(p->data > k)	
			cout<<p->data<<" ";
	} cout<<endl;
}

int solve(Node*& head, int x){
	Node* p = head;
	int cnt = 0;
	while(p != nullptr){
		if(p->data == x) cnt++;
		p = p->next;
	}
	return cnt;
}

int main() {
    Node* head = nullptr, *tail = nullptr;
    int x, n;
    inserList(head,tail,x,n);
    printList(head);

    // int cnt = 0;
	// cin>>x;
	// count(head,n,x,cnt);

	// cin>>x;
	// deleteX(head,x);
	// printList(head);

	cin>>x;
	solve(head,x);

	// sortA(head);
	// printList(head);

	// find_min(head);

	// max_k(head);

	// insertSort(head,x);
	// printList(head);

	// reverse(head);
	// printList(head);
}
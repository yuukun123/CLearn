#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int x) : data(x), next(nullptr) {}
};

struct Queue{
	Node* top;
	Node* tail;
};

void Init(Queue& q){
	q.top = nullptr;
	q.tail = nullptr;
}

int IsEmpty(Queue q){
    if ( q.top == NULL){
        return 1;
    }
    return 0; 
}

// lấy từ đấy lên
void Enqueue(Queue &q, int x){
	Node* newNode = new Node(x);
	if( newNode != nullptr ){
		if( IsEmpty(q) ){
			q.top = newNode;
			q.tail = newNode;
		}
		else{
			q.tail->next = newNode;
			q.tail = newNode;
		}
	}
}

int Deqqueue(Queue &q){ // lấy ra và xóa phần tủ đầu tiên
    if ( IsEmpty(q) )
        return 0;
    Node *p = q.top;
    int x = p->data;
    if(q.top == nullptr){
    	return -1;
    }
    q.top = p->next;
    delete p;
    if (q.top == NULL)
        q.tail = NULL;
    return x;
}

int Front(Queue q)
{
    if ( IsEmpty(q) )
        return 0;
    return q.top->data;
}

void Inser(Queue &q, int n){
	cin>>n;
	for(int i = 0; i < n; i ++){
		int x; cin>>x;
		Enqueue(q,x);
	}
}

void Out(Queue q){
	for(Node* p = q.top; p != nullptr; p = p->next){
		cout<<p->data<<" ";
	} cout<<endl;
}
 
void deleteK(Queue &q, int k){
	for(int i = 0; i < k; i++){
		cout<<Deqqueue(q)<<" ";
	} cout<<endl;
}

int main(){
	Queue q;
	Init(q);


	int n;
	Inser(q,n); // thêm vào đầu hàng
	Out(q);

	int k; cin>>k;
	deleteK(q,k);

	Out(q);
}
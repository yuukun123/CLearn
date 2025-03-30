#include<bits/stdc++.h>
using namespace std;
int n, x;
struct Node{
	int data;
	Node* next;
	Node(int x) : data(x), next(nullptr) {}
};

struct Stack{
	Node* top;
};

void Init(Stack& s){
	s.top = nullptr;
}

int IsEmpty(Stack s){
    if ( s.top == NULL)
        return 1;
    return 0; 
}

void Push(Stack &s, int x){ // lấy từ đỉnh xuống
	Node* newNode = new Node(x);
	if( newNode != nullptr ){
		if( IsEmpty(s) )
			s.top = newNode;
		else{
			newNode->next = s.top;
			s.top = newNode;
		}
	}
}

int Pop(Stack &s){ // lấy phần tử đứng trên đầu ra bỏ 
	if( IsEmpty(s) ) return 0;
	Node* p = s.top;
	int x = p->data;
	s.top = p->next;
	delete p;
	return x; 
}

int Top(Stack s){ // lấy phần tử đứng trên đầu ra nhưng không bỏ
    if ( IsEmpty(s) ) return 0;
    return s.top->data;
}

void Inser(Stack &s, int x, int n){
	cin>>n;
	for(int i = 0; i < n; i ++){
		cin>>x;
		Push(s,x);
	}
}

void Out(Stack s){
	for(Node* p = s.top; p != nullptr; p = p->next)
		cout<<p->data<<" ";
	cout<<endl;
}

void deleteS(Stack& s, int k){
	for(int i = 0; i < k; i++)
		cout<<Pop(s)<<" ";
	cout<<endl;
}

// void sortStack(Stack& s, Stack& temp){
//     while ( !IsEmpty(s) ) {
//         int current = Top(s);
//         Pop(s);

//         if (IsEmpty(temp))
// 	        Push(temp,current);
// 	    else{
// 		    while ( !IsEmpty(temp) && Top(temp) < current) {
// 	            Push(s,Top(temp) );
// 	            Pop(temp);
// 	        }
// 	        Push(temp,current);
// 		}
//     }

//     while( !IsEmpty(temp) ){
//     	cout<<Top(temp)<<" ";
//     	Pop(temp);
//     } cout<<endl;
// }

int main(){
	Stack s, temp;
	Init(s);
	Inser(s,x,n); // thêm vào đầu hàng
	// sortStack(s,temp);
	Out(s);
}
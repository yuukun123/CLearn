#include<bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	Node* next;
	Node(char x) : data(x), next(nullptr) {}
};

struct Stack{
	Node* top;
	Node* tail;
};

void Init(Stack& s){
	s.top = nullptr;
}

int IsEmpty(Stack s){
    if ( s.top == NULL){
        return 1;
    }
    return 0; 
}

// lấy từ đỉnh xuống
void Push(Stack &s, char x)
{
	Node* newNode = new Node(x);
	if( newNode != nullptr ){
		if( IsEmpty(s) ){
			s.top = newNode;
		}
		else{
			newNode->next = s.top;
			s.top = newNode;
		}
	}
}

int Pop(Stack &s){ // lấy phần tử đứng trên đầu ra bỏ 
	if( IsEmpty(s) )
		return 0;
	Node* p = s.top;
	char x = p->data;
	s.top = p->next;
	delete p;
	return x; 
}

int Top(Stack s) // lấy phần tử đứng trên đầu ra nhưng không bỏ
{
    if ( IsEmpty(s) )
        return 0;
    return s.top->data;
}

void Inser(Stack s){
	string st; cin>>st;
	for(int i = 0; i < st.length(); i++){
		if( st[i] == '(' || st[i] == '[' || st[i] == '{' )
			Push(s,st[i]);

		if(st[i] == ')'){
			if(!IsEmpty(s) && s.top->data == '(' ){
				Pop(s);
			}
			else 
			{
				cout<<"N";
				return;
			}
		}

		if(st[i] == ']'){
			if( !IsEmpty(s) && s.top->data == '[' ){
				Pop(s);
				
			}
			else 
			{
				cout<<"N"; 
				return;
			}
		}

		if(st[i] == '}'){
			if(!IsEmpty(s) && s.top->data == '{' ){
				Pop(s);
				
			}
			else 
			{
				cout<<"N";
				return;
			}
		}

	}
	if( IsEmpty(s) ) {
		cout<<"EMPTY";
	}
	else 
	{
		cout<<"wrong";
	}
}

void Out(Stack s){
	for(Node* p = s.top; p != nullptr; p = p->next){
		cout<<p->data<<" ";
	} cout<<endl;
}


int main(){
	Stack s;
	Init(s);

	Inser(s); // thêm vào đầu hàng

}
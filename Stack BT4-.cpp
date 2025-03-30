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

void Inser(Stack s){
	int cnt = 1, cnt1 = 0, cnt2 = 0, anss = 0, j = 0;
	string st; cin>>st;
	
	for(int i = 1; i < st.size(); ++i){
        if(st[i] == st[i-1]) ++anss;
        else {
            j = i;
            break;
        }
    }
    for(int i = j; i < st.size(); ++i){
        if(st[i] == st[i-1]) ++cnt;
        else break;
    }
    anss -= cnt;
    cnt = 0;

	for(int i = 0; i < st.length(); i++){
		if( st[i] == '(' || st[i] == '[' || st[i] == '{' ){
			Push(s,st[i]);

		    if(cnt > 1) anss += (cnt -1);
	        if(cnt1 > 1) anss += (cnt1 -1);
	        if(cnt2 > 1) anss += (cnt2 -1);
			cnt = 0; cnt1 = 0; cnt2 = 0;
		}

		if(st[i] == ')'){
			if(!IsEmpty(s) && s.top->data == '(' ){
				Pop(s);
				cnt++;
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
				cnt1++; 
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
				cnt2++;
			}

				else 
				{
					cout<<"N";
					return;
				}

		}
	}
	if( IsEmpty(s) ) {
		cout<<anss<<endl;
		cout<<"EMPTY";
	}
	else 
		cout<<"wrong";
}

int main(){
	Stack s;
	Init(s);

	Inser(s); // thêm vào đầu hàng

}
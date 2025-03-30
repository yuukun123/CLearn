#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

struct Queue{
    Node *top;
    Node *tail;
};

void temp(Queue &q){
    q.top = nullptr;
    q.tail = nullptr;
}

int IsEmpty(Queue q){
    return q.top == nullptr;
}

void Push(Queue &q, int x){
    Node *newNode = new Node(x);
    if(newNode != nullptr){
        if(IsEmpty(q)){
            q.top = newNode;
            q.tail = newNode;
        }
        else{
            q.tail->next = newNode;
            q.tail = newNode;
        }
    }
}


int DeQueue(Queue &q)
{
    if (IsEmpty(q))
        return 0;
    Node *node = q.top;
    int data = node->data;
    q.top = node->next;
    delete node;
    if (q.top == NULL)
        q.tail = NULL;
    return data;
}

int Front(Queue q)
{
    if (IsEmpty(q))
        return 0;
    return q.top->data;
}

void Insert(Queue &q){
    int n; cin>>n;
    for(int i = 0; i < n; i++){
        int x; cin>>x;
        Push(q,x);
    }
}

int sumEvenPositions(Queue q) {
    if (IsEmpty(q)) {
        return 0;
    }

    Node* current = q.top;
    int position = 0;
    int sum = 0;

    while (current != NULL) {
        if (position % 2 == 0) {
            sum += current->data;
        }
        position++;
        current = current->next;
    }

    return sum;
}


void Out(Queue q){
	for(Node* p = q.top; p != nullptr; p = p->next){
		cout<<p->data<<" ";
	} cout<<endl;
}

int main(){
    Queue q;
    temp(q);
    Insert(q);
    Out(q);
    cout<<sumEvenPositions(q);
}
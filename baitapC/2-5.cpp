#include <bits/stdc++.h>
using namespace std;
int x, n;
struct Node{
	int data;
	Node* left, * right;
	Node(int val): data(val), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int val){
    Node *newNode = new Node(val);
    if (root == nullptr )
    	root = newNode;
    if( val < root->data )
    	root->left = insertNode(root->left,val);
    else if( val > root->data)
    	root->right = insertNode(root->right,val);
    return root;
}

void createTree(Node*& root){
    for(int i = 0; i < n; i++ ){
        cin>>x;
        root = insertNode(root, x);
    }
}

void NLR(Node* root) { // tien to
    if (root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    NLR(root->left);
    NLR(root->right);
}

void LNR(Node* root) { // trung to
    if (root == NULL) {
        return;
    }
    LNR(root->left);
    cout<<root->data<<" ";
    LNR(root->right);
}

void LRN(Node* root) { // hau to
    if (root == NULL) {
        return;
    }
    LRN(root->left);
    LRN(root->right);
    cout<<root->data<< " ";
}

int searchX(Node* root, int x){
    if( root == nullptr) return 0;
    else{
        if(root->data == x) return 1;
        if( x < root->data ) 
            return searchX(root->left,x);
        return searchX(root->right,x);
    } return 0;
}

// void findReplace(Node*& p, Node*& root){
//     if( root->left )
//         findReplace(p,root->left);
//     else {
//         p->data = root->data;
//         p = root;
//         root = root->right;
//     }
// }

void findReplace2(Node*& p, Node*& root){
    if(root->right) 
        findReplace2(p,root->right);
    else {
        p->data = root->data;
        p = root;
        root = root->left;
    }
}

void deleteTree(Node*& root, int x){
    if( root ){
        if( x > root->data ) deleteTree(root->right,x);
        else if( x < root->data ) deleteTree(root->left,x);
        else{
            Node *temp = root;
            if( !root->left )
                root = root->right;
            else if( !root->right )
                root = root->left;
            else 
                findReplace2(temp, root->left);
            delete temp;
        }
    }
    else {
        cout<<"not found";
    }
}

int main(){
    Node* root = nullptr;
	n = 9; 
    createTree(root);
    NLR(root); // tien to
    cout<<endl;
    LNR(root); // trung to
    cout<<endl;
    LRN(root); // hau to
    cout<<endl;
    cin>>x;
    cout<<searchX(root,x)<<endl;
    cin>>x;
    deleteTree(root,x);
    NLR(root);
}
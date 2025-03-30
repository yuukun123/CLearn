#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left, * right;
	int height;
	Node(int val) : data(val), left(nullptr), right(nullptr){}
}; int n, x;

int getHeight(Node* root) {
	if (root == NULL)
		return 0;
	return 1 + max(getHeight(root->left), getHeight(root->right));
}

Node* rightRotate(Node* root){
	Node* x = root->left;

	// Bắt đầu quay phải
	root->left = x->right;
	x->right = root;

	// Thiết lập chiều cao
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));

	// Return x - trả về root mới
	return x;
}

Node* leftRotate(Node* root) {
	Node* y = root->right;

	// Bắt đầu quay trái
	root->right = y->left;
	y->left = root;

	// Thiết lập chiều cao
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));

	// Return y - trả về root mới
	return y;
}


Node* insert(Node*& root, int val){
	Node* newNode = new Node(val);
	if(root == nullptr)  root = newNode;
	if( val > root->data ) root->right = insert(root->right, val);
	if( val < root->data ) root->left = insert(root->left, val); 
	return root;

	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	int valBalance = getHeight(root->left) - getHeight(root->right);
	//leff left
	if (valBalance > 1 && val < root->left->data) return rightRotate(root);
	//right right 
	if(valBalance < -1 && val > root->right->data) return leftRotate(root); 
	//Left Right
	if (valBalance > 1 && value > root->left->data) {
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//Right Left
	if (valBalance < -1 && value < root->right->data) {
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
}

void Tree(Node*& root){
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x;
		root = insert(root,x);
	}
}

void show(Node* root){
	if (root == NULL) return;
    cout<<root->data<<" ";
    show(root->left);
    show(root->right);
}


main(){
	Node* root = nullptr;
	Tree(root);
	show(root);
}
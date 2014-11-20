#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max(int a,int b)
{
	return a > b? a : b;
}

struct Node{
	int val;
	int height;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL),height(0){};
};

int height(Node* root)
{
	if(root == NULL)
		return -1;
	return root->height;
}

Node* LL(Node* root)
{
	Node* l;
	l = root->left;
	root->left = l->right;
	l->right = root;
	root->height = max(height(root->left),height(root->right)) + 1;
	l->height = max(height(l->left),height(l->right)) + 1;
	return l;
}

Node* RR(Node* root)
{
	Node* r;
	r = root->right;
	root->right = r->left;
	r->left = root;
	root->height = max(height(root->left),height(root->right)) + 1;
	r->height = max(height(r->right),height(r->left)) + 1;
	return r;
}

Node* LR(Node* root)
{
	root->left = RR(root->left);
	return LL(root);
}

Node* RL(Node* root)
{
	root->right = LL(root->right);
	return RR(root);
}

Node* insert(Node* root,int val)
{
	if(root == NULL){
		root = new Node(val);
		return root;
	}else{
		if(val < root->val){
			root->left = insert(root->left,val);
			if(height(root->left) - height(root->right) == 2){
				if(val < root->left->val)
					root = LL(root);
				else
					root = LR(root);
			}
		}else{
			root->right = insert(root->right,val);
			if(height(root->right) - height(root->left) == 2){
				if(val > root->right->val)
					root = RR(root);
				else
					root = RL(root);
			}
		}
	}
	root->height = max(height(root->left),height(root->right)) + 1;
	return root;
}

int main()
{
	//vector<int> num;
	int n;
	cin >> n;
	Node* root = NULL;
	for(int i = 0; i < n;i++){
		int k;
		cin >> k;
		root = insert(root,k);
	}
	cout << root->val << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){};
};

Node* buildTree(vector<int>& num,int level, int l, int r)
{
	if(l > r)
		return NULL;
	int rest = pow(2, level-1) - 1;
	int bottom = r - l + 1 - rest;
	int k = pow(2,level - 2);
	int rootFromL;
	if(bottom >= k )
		rootFromL = rest;
	else
		rootFromL = k-1 + bottom;
	Node* root = new Node(num[l+rootFromL]);
	root->left = buildTree(num,level-1,l,rootFromL-1 + l);
	root->right = buildTree(num,level-1,rootFromL + l + 1,r);
	return root;
}

void levelOrder(Node* root)
{
	queue<Node*> q;
	if(root == NULL)
		return ;
	q.push(root);
	bool first = true;
	while(!q.empty()){
		Node* cur = q.front();
		q.pop();
		if(first){
			cout << cur->val;
			first = false;
		}else{
			cout << " " << cur->val;
		}
		if(cur->left)
			q.push(cur->left);
		if(cur->right)
			q.push(cur->right);
	}
}

int main()
{
	vector<int> num;
	int n; 
	cin >> n;
	num.resize(n);
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	sort(num.begin(),num.end());
	int level = log(n) / log(2) + 1;
	Node* root = buildTree(num,level,0,n-1);
	levelOrder(root);
	system("pause");
	return 0;

}

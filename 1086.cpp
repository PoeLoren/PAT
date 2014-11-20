#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){};
};

vector<int> res;

void postOrder(Node* root)
{
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	res.push_back(root->val);
}


int main()
{
	stack<Node*> s;
	int n;
	cin >> n;
	string op;
	Node* pre = NULL;
	Node* root = NULL;
	bool first = true;
	for(int i = 0; i < 2 * n;i++){
		cin >> op;
		if(op == "Push"){
			int k;
			cin >> k;
			Node* cur = new Node(k);
			if(first){
				root = cur;
				pre = root;
				first = false;
			}else{
				if(pre->left == NULL)
					pre->left = cur;
				else
					pre->right = cur;
				pre = cur;
			}
			s.push(cur);
		}else if(op == "Pop"){
			pre = s.top();
			s.pop();
		}
	}
	postOrder(root);
	for(int i = 0; i < res.size(); i++){
		if(i == 0)
			cout << res[0];
		else
			cout << " " << res[i];
	}
	return 0;
}
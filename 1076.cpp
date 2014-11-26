#include <iostream>
#include <VECTOR>
#include <queue>
using namespace std;

int n,l;

vector<int>  user[1001];

void BFS(int s)
{
	
	bool visited[1001];
	for (int i = 0;i <= n;i++)
	{
		visited[i] = false;
	}
	queue<int> q;
	q.push(s);
	visited[s] = true;
	int endNode = s;
	int level = 0;
	int cnt = 0;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		if(level <= l && level > 0)
			cnt++;
		
		for (int i = 0;i < user[cur].size();i++)
		{
			if(visited[user[cur][i]] == false)
			{
				visited[user[cur][i]] = true;//如队列的时候标记访问，可以解决当前访问节点所指向的节点已经入队的情况
				q.push(user[cur][i]);
			}
		}
		if(cur == endNode)
		{
			level++;
			if(!q.empty())
				endNode = q.back();
		}
	}
	cout << cnt << endl;
}
int main()
{
	cin >> n >> l;
	for (int i = 1;i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k;j++)
		{
			int m;
			cin >> m;
			user[m].push_back(i);
		}
	}
	int query;
	cin >> query;
	for (int j = 0;j < query;j++)
	{
		int t;
		cin >> t;
		BFS(t);
	}
	return 0;
}
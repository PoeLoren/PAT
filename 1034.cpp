#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string,vector<string> > adj;
map<string,int> weight;
map<string,bool> visited;
map<string,int> res;
int sum;
int count;
string head;
int maxWeight;
void dfs(string s)
{
	count++;
	sum += weight[s];
	visited[s] = true;
	if(weight[s] > maxWeight)
	{
		head = s;
		maxWeight = weight[s];
	}
	for (int i = 0;i < adj[s].size();i++)
	{
		if(visited[adj[s][i]] == false)
			dfs(adj[s][i]);
	}
}
int main()
{
	int n,k;
	cin >> n >> k;
	string s1,s2;
	for(int i = 0;i < n;i++)
	{
		int t;
		cin >> s1 >> s2 >> t;
		adj[s1].push_back(s2);
		adj[s2].push_back(s1);
		weight[s1] += t;
		weight[s2] += t;
	}
	map<string,vector<string> >::iterator it = adj.begin();
	for(;it != adj.end();it++)
	{
		if(visited[it->first] == false)
		{
			count = 0;
			sum = 0;
			head = "";
			maxWeight = -1;
			dfs(it->first);
			if(sum > k * 2 && count > 2)
			{
				res[head] = count;
			}
		}
	}
	cout << res.size() << endl;
	map<string,int>::iterator itr = res.begin();
	for (;itr != res.end(); itr++)
	{
		cout << itr->first << " " << itr->second << endl;
	}
	
	return 0;
}
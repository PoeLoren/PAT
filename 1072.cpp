#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>
#include <iomanip>

using namespace std;

const int max_num = 1100;
const int inf = 1 << 30;

int n,m,k,ds;
int gragh[max_num][max_num],visited[max_num],dist[max_num];

struct Gas
{
	int min_dist;
	int sum_dist;
	int isNotOK;
	int index;
};

Gas gas[15];

vector<Gas> res;

void dijstra(int index)
{
	int start = index + n;
	memset(dist,0,sizeof(dist));
	memset(visited,0,sizeof(visited));
	for (int i = 1; i <= n + m; i++)
	{
		dist[i] = gragh[start][i];
	}
	dist[start] = 0;
	visited[start] = 1;
	for (int i = 1; i <= n + m; i++)
	{
		int mm = inf,k = -1;
		for (int j = 1; j <= n + m; j++)
		{
			if(!visited[j] && dist[j] < mm){
				mm = dist[j];
				k = j;
			}
		}
		if(k == -1){
			break;
		}else{
			visited[k] = 1;
		}
		for (int x = 1; x <= n+m; x++)
		{
			if(visited[x] == 0){
				if(mm + gragh[k][x] < dist[x])
					dist[x] = mm + gragh[k][x];
			}
		}
	}
}

int trans(string s)
{
	if(s[0] == 'G'){
		string sub = s.substr(1);
		const char *num = sub.c_str();
		return atoi(num) + n;
	}else{
		return atoi(s.c_str());
	}
}

bool cmp(Gas a,Gas b)
{
	if(a.min_dist != b.min_dist){
		return a.min_dist > b.min_dist;
	}else if(a.sum_dist != b.sum_dist){
		return a.sum_dist < b.sum_dist;
	}else{
		return a.index < b.index;
	}
}

int main()
{
	cin >> n >> m >> k >> ds;
	memset(gas,0,sizeof(gas));
	for (int i = 0; i < 15; i++)
	{
		gas[i].index = i;
	}
	for (int i = 1; i <= n+m; i++)
	{
		for (int j = 1; j <= n+m; j++)
		{
			gragh[i][j] = inf;
		}
	}
	for (int i = 0; i < k; i++)
	{
		string s1,s2;
		cin >> s1 >> s2;
		int p1 = trans(s1),p2 = trans(s2);
		cin >> gragh[p1][p2];
		gragh[p2][p1] = gragh[p1][p2];
	}
	for (int i = 1; i <= m; i++)
	{
		dijstra(i);
		int min_dist = inf;
		for (int j = 1; j <= n; j++)
		{
			if(dist[j] > ds)
				gas[i].isNotOK = 1;
			gas[i].sum_dist += dist[j];
			if(dist[j] < min_dist)
				min_dist = dist[j];
		}
		if(gas[i].isNotOK == 0){
			gas[i].min_dist = min_dist;
			res.push_back(gas[i]);
		}
	}
	sort(res.begin(),res.end(),cmp);
	if(res.empty()){
		cout << "No Solution" <<endl;
	}else{
		cout << 'G' << res[0].index << endl;
		cout << setiosflags(ios::fixed) << setprecision(1) << (double)res[0].min_dist << ' ' << (double)res[0].sum_dist / (double)n << endl;
	}
	return 0;
}
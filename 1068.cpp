#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define INT_MIN -1000000
vector<int> w;
int f[10001][101];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	int n,m;
	cin >> n >> m;
	int i;
	w.resize(n+1);
	for(i = 1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	for(i = 0;i <= m;i++){
		f[0][i] = 0;
		f[i][0] = 0;
	}
	sort(w.begin() + 1,w.end(),cmp);
	
	f[0][0] = 0;
	for(i = 1; i <= n;i++)
		for(int j = 1;j <= m;j++)
		{
			if(j < w[i])
				f[i][j] = f[i-1][j];
			else if(f[i-1][j] > f[i-1][j-w[i]] + w[i])
				f[i][j] = f[i-1][j];
			else
				f[i][j] = f[i-1][j-w[i]] + w[i];
		}
	if(f[n][m] != m)
	{
		cout << "No Solution" << endl;
		return 0;
	}
	i = n;
	int j = m;
	while(j > 0)
	{
		if(f[i][j] == f[i-1][j-w[i]] + w[i])
		{
			cout << w[i];
			j -= w[i];
			i--;
			if(j != 0)
				cout << " ";
		}else
			i--;
	}
	return 0;
}
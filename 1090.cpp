#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAXNUM = 100000 + 5;
vector<int> a[MAXNUM];
int main()
{
	
	int n;
	double p,r;
	cin >> n >> p >> r;
	int i = 0;
	for(;i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a[tmp + 1].push_back(i + 1);
	}
	
	queue<int> q;
	q.push(0);
	int endNode = 0;
	int level = 0;
	int num = 0;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		++num;
		int j = 0;
		for(;j < a[cur].size(); ++j)
		{
			q.push(a[cur][j]);
		}
		if(cur == endNode)
		{
			level++;
			if(!q.empty())
			{
				endNode = q.back();
				num = 0;
			}
		}
	}

	double res = p * pow((1.0 + r / 100), level-2);
	printf("%.2f %d", res, num);
	return 0;
}
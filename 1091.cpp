#include <iostream>
#include <queue>

using namespace std;

int b[65][1300][130];
bool visited[65][1300][130];
int res = 0;
int m,n,l,t;
struct pts
{
	int x;
	int y;
	int z;
	pts(int i,int j,int k):x(i),y(j),z(k){};
};

int bfs(int i,int j,int k)
{
	int sum = 1;
	visited[i][j][k] = true;
	queue<pts> q;
	pts p(i,j,k);
	q.push(p);
	while(!q.empty())
	{
		pts cur = q.front();
		q.pop();
		if(cur.x != 0 && b[cur.x - 1][cur.y][cur.z] == 1 && visited[cur.x - 1][cur.y][cur.z] == false)
		{
			pts next(cur.x -1,cur.y,cur.z);
			visited[cur.x - 1][cur.y][cur.z] = true;
			sum++;
			q.push(next);
		}
		if(cur.x != l && b[cur.x + 1][cur.y][cur.z] == 1 && visited[cur.x + 1][cur.y][cur.z] == false)
		{
			pts next(cur.x +1,cur.y,cur.z);
			visited[cur.x + 1][cur.y][cur.z] = true;
			sum++;
			q.push(next);
		}
		if(cur.y != 0 && b[cur.x ][cur.y- 1][cur.z] == 1 && visited[cur.x ][cur.y - 1][cur.z] == false)
		{
			pts next(cur.x ,cur.y - 1,cur.z);
			visited[cur.x ][cur.y - 1][cur.z] = true;
			sum++;
			q.push(next);
		}
		if(cur.y != m && b[cur.x ][cur.y+ 1][cur.z] == 1 && visited[cur.x ][cur.y+ 1][cur.z] == false)
		{
			pts next(cur.x ,cur.y+1,cur.z);
			visited[cur.x ][cur.y+ 1][cur.z] =true;
			sum++;
			q.push(next);
		}
		if(cur.z != 0 && b[cur.x ][cur.y][cur.z - 1] == 1 && visited[cur.x][cur.y][cur.z - 1] == false)
		{
			pts next(cur.x ,cur.y,cur.z - 1);
			visited[cur.x][cur.y][cur.z - 1] = true;
			sum++;
			q.push(next);
		}
		if(cur.z != n && b[cur.x ][cur.y][cur.z+ 1] == 1 && visited[cur.x ][cur.y][cur.z+ 1] == false)
		{
			pts next(cur.x,cur.y,cur.z +1);
			sum++;
			visited[cur.x ][cur.y][cur.z+ 1] = true;
			q.push(next);
		}
	}
	return sum;

}

int main()
{
	int i,j,k;
	
	cin >> m >> n >> l >> t;
	for(i = 0;i < l;i++)
		for(j = 0;j < m;j++)
			for(k = 0;k < n;k++)
			{
				scanf("%d",&b[i][j][k]);
				visited[i][j][k]= false;
			}
	for(i = 0;i < l;i++)
		for(j = 0;j < m;j++)
			for(k = 0;k < n;k++)
			{
				if(b[i][j][k] == 1 && visited[i][j][k] == false)
				{
					int sum = bfs(i,j,k);
					if(sum >= t)
						res += sum;
				}
				
			}
	cout << res;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>

#define INT_MAX 10000000
#define INT_MIN -10000000
using namespace std;

map<string,int> str2int;
map<int,string> int2str;
vector<string> city;
vector<int> all[201];
vector<int> res;
bool visited[201];
int dist[201][201];
int happy[201];
int n,k;
int minDist[201];
int resCount = 0;
int happyMax = INT_MIN;
int happyAveMax = INT_MIN;
void dijkstra()
{
	int i,j;
	for(i = 1;i< n;i++){
		minDist[i] = dist[0][i];
		visited[i] = false;
		if(dist[0][i] < INT_MAX)
			all[i].push_back(0);
	}
	minDist[0] = 0;
	visited[0] = true;
	for(i = 0;i < n;i++){
		int k = -1;
		int mind = INT_MAX;
		for(j = 0;j < n;j++){
			if(visited[j] == false){
				if(minDist[j] < mind){
					k = j;
					mind = minDist[j];
				}
			}
		}
		if(k == -1)
			break;
		visited[k] = true;
		for(int p = 0;p < n;p++){
			if(visited[p] == false){
				if(minDist[k] + dist[k][p] < minDist[p]){
					minDist[p] = minDist[k] + dist[k][p];
					all[p].clear();
					all[p].push_back(k);
				}else if(minDist[k] + dist[k][p] == minDist[p]){
					all[p].push_back(k);
				}
			}
			
		}
	}
}

void findPath(int k,vector<int>& tmpRes,int h)
{
	if(all[k][0] == 0){
		tmpRes.push_back(0);
		resCount++;
		if(h > happyMax){
			res.clear();
			res = tmpRes;
			happyAveMax = h / tmpRes.size();
			tmpRes.pop_back();
			happyMax = h;
			
			return;
		}else if(h == happyMax){
			int tmpAve = happyMax / tmpRes.size();
			if(tmpAve > happyAveMax){
				res.clear();
				res = tmpRes;
				tmpRes.pop_back();
				happyAveMax = tmpAve;
				return;
			}
		}
	}else{
		for(int j = 0;j < all[k].size();j++){
			int pre = all[k][j];
			tmpRes.push_back(pre);
			findPath(all[k][j],tmpRes,h + happy[pre]);
			tmpRes.pop_back();
		}
	}
}

void print()
{
	int des = str2int["ROM"];
	cout << resCount << " " << minDist[des] << " " << happyMax;
	cout << " " << happyAveMax << endl;
	for(int i = res.size()-1;i>=0;i--){
		string ct = (int2str.find(res[i]))->second;
		cout << ct << "->";

	}
	cout << "ROM";
}

int main()
{

	string s;
	cin >> n >> k >> s;
	str2int[s] = 0;
	int2str[0] = s;
	int i,j;
	for(i = 0; i < n;i++)
		for(j = 0;j < n;j++){
			dist[i][j] = INT_MAX;
		}
		i = 1;
		for(; i < n;i++){
			string tmp;
			int h;
			cin >> tmp >> h;
			str2int[tmp] = i;
			int2str[i] = tmp;
			happy[i] = h;
		}
		for(i = 0;i < k;i++){
			string s1,s2;
			int d;
			cin >> s1 >> s2 >> d;
			int idx1 = str2int[s1];
			int idx2 = str2int[s2];
			dist[idx1][idx2] = dist[idx2][idx1] = d;
		}
		dijkstra();
		vector<int> tmpRes;
		int h = 0;
		int dest = str2int["ROM"];
		findPath(dest,tmpRes,h + happy[dest]);
		print();
		return 0;
}
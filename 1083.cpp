#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Stu
{
	string name;
	string id;
	Stu(string n,string i):name(n),id(i){};
};

vector<Stu> stu[101];
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string name;
		string id;
		int k;
		cin >> name >> id >> k;
		Stu s(name,id);
		stu[k].push_back(s);
	}
	int low,high;
	cin >> low >> high;
	vector<Stu> res;
	for(int l = high; l >= low;l--)
	{
		if(!stu[l].empty())
			res.push_back(stu[l][0]);
	}
	if(res.empty())
		printf("NONE");
	else
	{
		for(int i = 0; i < res.size();i++)
		{
			cout << res[i].name << " " << res[i].id << endl;
		}
	}
	return 0;
}
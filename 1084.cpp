#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	set<char> s,set2;
	string ss1,ss2;
	ss1.resize(s1.size());
	ss2.resize(s2.size());
	transform(s1.begin(),s1.end(),ss1.begin(),::toupper);
	transform(s2.begin(),s2.end(),ss2.begin(),::toupper);
	for(int i = 0; i < ss2.size();i++){
		s.insert(ss2[i]);
	}
	for(int i = 0; i < ss1.size();i++){
		if(s.find(ss1[i]) == s.end() && set2.find(ss1[i]) == set2.end()){
			cout << ss1[i];
			set2.insert(ss1[i]);
		}
	}
	return 0;
}
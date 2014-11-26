#include <iostream>
#include <vector>

using namespace std;

vector<int> prime;

bool isPrime[10050];

void countPrime()
{
	for (int k = 0;k < 10050;k++)
	{
		isPrime[k] = true;
	}
	for(int i = 2;i < 10050;i++)
		for (int j = i * i;j < 10050;j += i)
		{
			isPrime[j] = false;
		}
	for (int j = 2;j < 10050;j++)
	{
		if(isPrime[j])
			prime.push_back(j);
	}
}


int main()
{
	int m,n;
	cin >> m >> n;
	int i = 0;
	countPrime();
	while(m > prime[i])
	{
		i++;
	}
	m = prime[i];
	vector<bool> res(m,false);
	for (int j = 0;j < n;j++)
	{
		int h;
		cin >> h;
		int r = h % m;
		if(res[r] == false)
		{
			res[r] = true;
			if(j == 0)
			{
				printf("%d",r);
			}
			else
			{
				printf(" %d",r);
			}
		}
		else
		{
			int a = 1;
			int nr = r;
			while(res[r] == true && a <= m)
			{
				r = (nr + a * a) % m;
				a++;
			}
			if(a > m)
			{
				printf(" -");
			}
			else
			{
				res[r] = true;
				printf(" r");
			}
		}
	}

	return 0;
}
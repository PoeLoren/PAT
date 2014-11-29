#include <iostream>
#include <vector>

using namespace std;
struct Num
{
	long long a;
	long long b;
};

long long lgd(long long a, long long b)
{
	return b? lgd(b, a%b):a;
}

void simply(Num& n)
{
	long long l = lgd(abs(n.a),abs(n.b));
	n.a /= l;
	n.b /= l;
}

void print(Num n)
{
	if(n.a == 0)
	{
		cout << "0";
		return;
	}
	long long k = n.a / n.b;
	bool neg = false;
	if(n.a < 0)
	{
		neg = true;
		if(k != 0)
			n.a = -n.a;
		cout << "(";
	}
	if(k != 0)
		cout << k;
	if(n.a % n.b != 0)
	{
		if(k != 0)
			cout << " ";
		cout << n.a % n.b << "/" << n.b;
	}
	if(neg)
		cout << ")";
}

void add(Num n1,Num n2)
{
	print(n1);
	cout << " + ";
	print(n2);
	cout << " = ";
	Num res;
	res.a = n1.a * n2.b + n2.a * n1.b;
	res.b = n1.b * n2.b;
	simply(res);
	print(res);
}

void mns(Num n1,Num n2)
{
	print(n1);
	cout << " - ";
	print(n2);
	cout << " = ";
	Num res;
	res.a = n1.a * n2.b - n2.a * n1.b;
	res.b = n1.b * n2.b;
	simply(res);
	print(res);
}

void multy(Num n1,Num n2)
{
	print(n1);
	cout << " * ";
	print(n2);
	cout << " = ";
	Num res;
	res.a = n1.a * n2.a;
	res.b = n1.b * n2.b;
	simply(res);
	print(res);
}

void divide(Num n1, Num n2)
{
	print(n1);
	cout << " / ";
	print(n2);
	cout << " = ";
	if(n2.a == 0)
	{
		cout << "Inf";
		return;
	}
	Num res;
	res.a = n1.a * n2.b;
	res.b = n1.b * n2.a;
	if(res.b < 0)
	{
		res.a = -res.a;
		res.b = -res.b;
	}
	simply(res);
	print(res);
}
int main()
{
	Num n1,n2;
	scanf("%lld/%lld %lld/%lld",&n1.a,&n1.b,&n2.a,&n2.b);
	simply(n1);
	simply(n2);
	add(n1,n2);
	cout << endl;
	mns(n1,n2);
	cout << endl;
	multy(n1,n2);
	cout << endl;
	divide(n1,n2);
	return 0;
}
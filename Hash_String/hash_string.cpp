#include <iostream>
#include <string>
using namespace std;
const long long base = 311;
const long long MOD = 1e9 + 3;
const int maxn = 1e6 + 5;
string p, t;
long long hashp;
long long Pow[maxn];
long long hasht[maxn];
int main()
{
	cin >> t >> p;
	int lent = t.size();
	int lenp = p.size();
	t = " " + t;
	p = " " + p;
	//
	Pow[0] = 1;
	for (int i = 1; i <= lent; ++i)
		Pow[i] = (Pow[i - 1] * base) % MOD;
	//tính hashp
	for (int i = 1; i <= lenp; ++i)
		hashp = (hashp * base + p[i]) % MOD;
	//tính hasht , hasht[i] lưu giá trị hash của xâu [1..i]
	for (int i = 1; i <= lent; ++i)
		hasht[i] = (hasht[i - 1] * base + t[i]) % MOD;
	//kiểm tra và in kết quả 
	for (int i = 1; i <= lent - lenp + 1; ++i)
		if (hashp == (hasht[i + lenp - 1] - hasht[i - 1] * Pow[lenp] + MOD * MOD) % MOD)
			cout << i << " ";
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 100;
vector <int> e[maxn];
stack <int> s;
int m, n, cx[maxn];

void dfs(int x)
{
	s.push(x);
	cx[x] = 1;
	while (!s.empty())
	{
		int u = s.top();
		s.pop();
		cout << u << " ";
		for(auto v: e[u])
			if (cx[v] == 0)
			{
				s.push(v);
				cx[v] = 1;
			}
	}
}

int main()
{
	int u, v;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1);
}

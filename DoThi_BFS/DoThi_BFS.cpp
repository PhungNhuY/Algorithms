#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int maxn = 100;
int m, n, cx[maxn];
vector <int> e[maxn];
queue <int> s;

void bfs(int x)
{
	s.push(x);
	cx[x] = 1;
	while (!s.empty())
	{
		int u = s.front();
		s.pop();
		cout << u << " ";
		for(auto v:e[u])
			if (cx[v] == 0)
			{
				cx[v] = 1;
				s.push(v);
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
	bfs(1);
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int oo = INT_MAX;
vector <pair<int, int > >e[1000];
int n, m;
int d[1000];
void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
	for (int i = 1; i <= n; ++i)
		d[i] = oo;
	d[1] = 0;
	pq.push(make_pair(0, 1));
	while (pq.size())
	{
		int u = pq.top().second;
		int du = pq.top().first;
		pq.pop();
		if (du != d[u])
			continue;
		for (auto i : e[u])
		{
			int v = i.second;
			int uv = i.first;
			if (d[v] > du + uv)
			{
				d[v] = du + uv;
				pq.push(make_pair(d[v], v));
			}
		}
	}
}
int main()
{
	int p, q, w;
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> p >> q >> w;
		e[p].push_back(make_pair(w, q));
		e[q].push_back(make_pair(w, p));
	}
	dijkstra();

}


//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int maxn = 1000;
//int m, n, pa[maxn];
//int layed[maxn];
//struct edge
//{
//	int u, v, w;
//}ed[maxn];
//bool cmp(edge a, edge b)
//{
//	return a.w < b.w;
//}
//int toTien(int x)//tim to tien
//{
//	if (pa[x] == x)
//		return x;
//	else
//		return toTien(pa[x]);
//}
//
//int main()
//{
//	ios::sync_with_stdio; cin.tie(0); cout.tie(0);
//	cin >> n >> m;
////nhap
//	for (int i = 1; i <= m; i++)
//		cin >> ed[i].u >> ed[i].v >> ed[i].w;
////xap xep theo trong so
//	sort(ed + 1, ed + m + 1, cmp);
////khoi tao parent
//	for (int i = 1; i <= n; ++i)
//		pa[i] = i;
//
//	int cnt = 0;
//	for (int i = 1; i <= m; ++i)
//		if (cnt < n - 1)    //neu cnt=n-1 => da tao thanh cay khung
//		{
//			if (toTien(ed[i].u) != toTien(ed[i].v))
//			{
//				layed[i] = 1;
//				pa[toTien(ed[i].u)] = pa[toTien(ed[i].v)];
//				cnt++;
//			}
//		}
//		else
//			break;
//	if (cnt < n - 1)
//		cout << "-1";
//	else
//		for (int i = 1; i <=m; ++i)
//			if (layed[i] == 1)
//				cout << ed[i].u << " " << ed[i].v << "\n";
//}


#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int n, m, cx[maxn], pa[maxn];
struct edge
{
	int u, v, w;
}ed[maxn];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int toTien(int x)
{
	if (pa[x] == x)
		return x;
	else
		return toTien(pa[x]);
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	}
	sort(ed + 1, ed + n + 1, cmp);
	for (int i = 1; i <= n; ++i)
		pa[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m; ++i)
		if (cnt < n - 1)
		{
			if (toTien(ed[i].u) != toTien(ed[i].v))
			{
				cnt++;
				cx[i] = 1;
				pa[toTien(ed[i].u)] = pa[toTien(ed[i].v)];
			}
		}
		else
			break;
	if (cnt != n - 1)
		cout << "-1";
	else
		for (int i = 1; i <= m; ++i)
			if (cx[i] == 1)
				cout << ed[i].u << " " << ed[i].v << endl;
}

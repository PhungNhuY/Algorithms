//#include <stdio.h>
//
//const int oo = 1000111000;
//int a[239][239];
//int n, m;
//
//void minimize(int& a, int b) {
//    if (a > b)
//        a = b;
//}
//
//int main() {
//    scanf("%d%d", &n, &m);
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            a[i][j] = oo;
//    for (int i = 1; i <= n; i++)
//        a[i][i] = 0;
//
//    for (int i = 1; i <= m; i++) {
//        int p, q, w;
//        scanf("%d%d%d", &p, &q, &w);
//        a[p][q] = a[q][p] = w;
//    }
//
//    for (int k = 1; k <= n; k++)
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= n; j++)
//                minimize(a[i][j], a[i][k] + a[k][j]);
//
//    printf("%d\n", a[1][n]);
//}


#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000;
int n, m, u, v, w;
int a[maxn][maxn];
int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		a[u][v] = w;
	}	
	for (int i = 1; i <= n; ++i)
		a[i][i] = 0;
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	cout << a[1][n];
}
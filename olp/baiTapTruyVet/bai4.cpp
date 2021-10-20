#include <iostream>
#include <algorithm>
using namespace std;
int n, a[101][101], b[101][101], i, j, sol;
int main()
{

    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    for (i = 2; i <= n; ++i)
        for (j = 1; j <= i; ++j)
            a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
    char c[101];
    sol = 0;
    int vt=1;
    for(i=1;i<=n;++i)
        if (sol < a[n][i])
        {
            sol = a[n][i];
            vt = i;
        }
    for (i = n-1; i >= 1; --i)
    {
        if (a[i][vt] > a[i][vt - 1])
        {
            c[i] = 'R';
        }
        else
        {
            c[i] = 'L';
            vt--;
        }
    }
    for (i = 1; i <= n - 1; ++i)
        cout << c[i];
}
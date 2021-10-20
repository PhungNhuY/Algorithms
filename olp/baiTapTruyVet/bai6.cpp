#include <iostream>
#define MAX 10000
using namespace std;
int n, s, sum, a[MAX], i, j;
bool f[MAX][MAX];
int main()
{
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    s = sum / 2;
    for (i = 0; i <= n; ++i)
        f[i][0] = true;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= s; ++j)
        {
            if (f[i - 1][j] == true)
                f[i][j] = true;
            else if (j >= a[i] && f[i - 1][j - a[i]] == true)
                f[i][j] = true;
        }
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= s; ++j)
            cout << f[i][j] << " ";
        cout << endl;
    }
    for (i = s; i >= 0; --i)
    {
        if (f[n][i] == true)
        {
            cout << sum - i * 2<<endl;
            s = i;
            break;
        }
    }
    int c[10000];
    for (i = 1; i <= n; ++i)
        c[i] = 0;
    for (i = n; i >= 1; --i)
    {
        if (f[i][s] != f[i - 1][s])
        {
            c[i] = 1;
            s -= a[i];
        }
    }
    for (i = 1; i <= n; ++i)
        if (c[i] == 1)
            cout << i << " ";
    cout << endl;
    for (i = 1; i <= n; ++i)
        if (c[i] == 0)
            cout << i << " ";
    return 0;
}
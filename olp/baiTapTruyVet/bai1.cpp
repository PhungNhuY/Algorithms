#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, a[1000], f[1000], i, j,m,c[1000],dem,vt;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    fill(f + 1, f + 1 + n, 1);
    for (i = 2; i <= n; ++i)
        for (j = 1; j <= i; ++j)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    m = 0;
    vt = 0;
    for (i = 1; i <= n; ++i)
        if (m < f[i])
        {
            m = f[i];
            vt = i;
        }
    cout << m << endl;
    c[m] = a[vt];
    dem = m;
    while (vt > 1)
    {
        vt--;
        if (f[vt] == m - 1 && a[vt] < c[m])
        {
            c[m - 1] = a[vt];
            m--;
        }
    }
    for (i = 1; i <= dem; ++i)
        cout << c[i] << " ";
}
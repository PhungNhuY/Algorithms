#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1000], i, j, f[1000][2], c[1000],vt,dem,m,trai,phai;
int main()
{
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i)
    {
        f[i][0] = 1;
        f[i][1] = 1;
    }

    for(i=2;i<=n;++i)
        for (j = 1; j < i; ++j)
        {
            if (a[i] > a[j])
                f[i][0] = max(f[i][0], f[j][0] + 1);
        }
    for (i = n - 1; i >= 1; --i)
        for (j = n; j > i; --j)
            if (a[i] > a[j])
                f[i][1] = max(f[i][1], f[j][1] + 1);
    m = 0;
    for (i = 1; i <= n; ++i)
        if (m < (f[i][0] + f[i][1] - 1))
        {
            m = f[i][0] + f[i][1] - 1;
            vt = i;
            trai = f[i][0];
            phai = f[i][1];
        }
    c[trai] = vt;
    dem = trai-1;
    for (i = vt-1; i >= 1; --i)
    {
        if (f[i][0] == dem)
        {
            c[dem] = i;
            dem--;
        }
    }
    dem = phai - 1;
    for (i = vt + 1; i <= n; ++i)
    {
        if (f[i][1] == dem)
        {
            c[m - dem + 1] = i;
            dem--;
        }
    }
    cout << m<<endl;
    for (i = 1; i <= m; ++i)
        cout << c[i]<<" ";
}
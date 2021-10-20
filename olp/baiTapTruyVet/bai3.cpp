#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, b;
int f[1000][1000], i, j;
int main()
{
    getline(cin, a);
    getline(cin, b);
    for (i = 1; i <= a.size(); ++i)
        for (j = 1; j <= b.size(); ++j)
            if (a[i - 1] == b[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    cout << f[a.size()][b.size()]<<endl;
    int m, n;
    string s = "";
    m = a.size();
    n = b.size();
    while (m * n != 0)
    {
        if (a[m - 1] == b[n - 1])
        {
            s.push_back(a[m - 1]);
            m--;
            n--;
        }
        else if (f[m][n] == f[m - 1][n]) 
            m--;
        else
            n--;
    }
    for (int i = s.length() - 1; i >= 0; --i)
        cout << s[i];
}
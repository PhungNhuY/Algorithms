#include <iostream>
using namespace std;
int a[20],dem=0,N;
bool kiemTra(int x)
{
    for (int i = 1; i < x; ++i)
        if (a[i] == a[x] || a[i] - i == a[x] - x || a[x] + x == a[i] + i)
            return 0;
    return 1;
}
void xuat()
{
    /*dem++;*/
    cout << ++dem << ". ";
    for (int i = 1; i <= N; ++i)
        cout << a[i] << " ";
    cout << endl;
}
void xepHau(int x)
{
    if (x > N)
        xuat();
    for (int i = 1; i <= N; ++i)
    {
        a[x] = i;
        if (kiemTra(x))
            xepHau(x + 1);
    }
}
int main()
{
    cin >> N;
    xepHau(1);
    //cout << dem;
}


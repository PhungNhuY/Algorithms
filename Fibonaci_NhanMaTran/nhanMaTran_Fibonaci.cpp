/*#include <iostream>
using namespace std;
const long long base = 1e9+7;

struct MaTran
{
    long long c[2][2];
    MaTran()
    {
        c[0][0] = 0;
        c[0][1] = 1;
        c[1][0] = 1;
        c[1][1] = 1;
    }
};

MaTran operator * (MaTran a, MaTran b)
{
    MaTran res;
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
        {
            res.c[i][j] = 0;
            for (int k = 0; k <= 1; k++)
                res.c[i][j] = (res.c[i][j] + a.c[i][k] * b.c[k][j]) % base;
        }
    return res;
}

MaTran powermod(MaTran a, long long n)
{
    if (n == 1)
        return a;
    if (n % 2 != 0)
        return powermod(a, n - 1) * a;
    MaTran tmp = powermod(a, n / 2);
    return tmp * tmp;
}

int main()
{
    long long n;
    cin >> n;
    MaTran A;
    A = powermod(A, n);
    cout << A.c[0][1];
    return 0;
} */


#include <iostream>
using namespace std;
const long long MOD = 1000000007;
struct Matrix
{
    long long m[2][2];
    Matrix()
    {
        m[0][0] = 0;
        m[0][1] = 1;
        m[1][0] = 1;
        m[1][1] = 1;
    }
    Matrix(long long x, long long y, long long z, long long t)
    {
        m[0][0] = x;
        m[0][1] = y;
        m[1][0] = z;
        m[1][1] = t;
    }
};
Matrix operator *(Matrix a, Matrix b)
{
    Matrix c(0,0,0,0);
    for (long long i = 0; i <= 1; ++i)
        for (long long j = 0; j <= 1; ++j)
        {
            for (long long k = 0; k <= 1; ++k)
                c.m[i][j] += a.m[i][k] * b.m[k][j];
            c.m[i][j] %= MOD;
        }
    return c;
}
Matrix Pow(Matrix a, long long n)
{
    if (n == 1)
        return a;

    Matrix term;
    term = Pow(a, n / 2);
    term = term * term;
    if (n % 2 == 1)
        term = term * a;
    return term;
}
int main()
{
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    Matrix a;
    a=Pow(a, n);
    cout << a.m[0][1];
}
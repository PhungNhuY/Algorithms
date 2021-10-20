#include <iostream>
using namespace std;
const int maxn = 2009;
int n;
class matrix
{
public:
	long long val[2][2];
	matrix()
	{
		val[0][0] = 1;
		val[0][1] = 1;
		val[1][0] = 1;
		val[1][1] = 1;
	}
	matrix(long long x, long long y, long long a, long long b)
	{
		val[0][0] = x;
		val[0][1] = y;
		val[1][0] = a;
		val[1][1] = b;
	}
	matrix operator * (matrix a)
	{
		matrix re;
		for(int i=0;i<=1;++i)
			for(int j=0;i<=1;++j)
				for(int k=0;k<=1;++k)
					re.val[i][j]+=
	}
};
int main()
{
		
}
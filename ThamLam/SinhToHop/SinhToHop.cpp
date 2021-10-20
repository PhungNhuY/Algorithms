//sinh to hop khong lap
#include <iostream>

using namespace std;
int n, k, mang[20];
void ghi()
{
	for (int i = 1; i <= k; ++i)
		cout << mang[i]<<" ";
	cout << endl;
}
void toHop(int x)
{
	for (int i = mang[x-1]+1; i <= n - k + x; ++i)
	{
		mang[x] = i;
		if (x == k)
			ghi();
		else
			toHop(x + 1);
	}
}
int main()
{
	cin >> n >> k;
	toHop(1);
}

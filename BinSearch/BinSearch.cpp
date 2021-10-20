#include <iostream>
#include <algorithm>
using namespace std;
int n, k, a[10000];
int binary_search(int left, int right)
{
	if (left == right)
		return left;
	int mid = (left + right) / 2;
	if (a[mid] < k)
		return binary_search(mid + 1, right);
	else
		return binary_search(left, mid);
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	cout << binary_search(1, n);
}
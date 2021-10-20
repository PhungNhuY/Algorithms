#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int >a(n + 1);
	vector <int> b(n + 1, INT_MAX);// b[i] = INT_MAX
	b[0] = INT_MIN;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		//tim trong mang b[] phan tu b[k] nho nhat >= a[i], thay the b[k] = a[i]
		int k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		b[k] = a[i];
		ans = max(ans, k);
	}
	cout << ans;
}
//https://vietcodes.github.io/algo/lis
// goi b[i] la gia tri ket thuc cua day con co do dai i
// b la day tang dan (co the chung minh duoc)

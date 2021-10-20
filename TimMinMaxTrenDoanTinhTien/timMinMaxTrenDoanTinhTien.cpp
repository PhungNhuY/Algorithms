#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void xuat(int a[], int l, int r)
{
	for (int i = l; i <= r; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n, a[30005], l[30005], r[30005];
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		vector<int>stack;
		for (int i = 1; i <= n; i++)
		{
			while (!stack.empty() && a[stack.back()] >= a[i])
				stack.pop_back();
			if (!stack.empty())
				l[i] = stack.back() + 1;
			else
				l[i] = 1;
			stack.push_back(i);
		}

		stack.clear();
		for (int i = n; i >= 1; i--)
		{
			while (!stack.empty() && a[stack.back()] >= a[i])
				stack.pop_back();
			if (!stack.empty())
				r[i] = stack.back() - 1;
			else
				r[i] = n;
			stack.push_back(i);
		}

		//xuat(l, 1, n);
		//xuat(r, 1, n);

		int vt = 1;
		for (int i = 2; i <= n; i++)
			if (a[vt] * (r[vt] - l[vt] + 1) < a[i] * (r[i] - l[i] + 1))
				vt = i;
		cout << a[vt] * (r[vt] - l[vt] + 1) << " " << l[vt] << " " << r[vt] << "\n";
	}
}
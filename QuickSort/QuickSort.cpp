#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void quickSort(vector<int>& a, int l, int r)
//chon Key la phan tu chinh giua mid = (l + r) / 2;
//sau khi xep cac phan tu lon hon key o ben phai,  nho hon key o ben trai
{
	if (l >= r)
		return;
	int key = a[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (a[i] < key)
			i++;
		while (a[j] > key)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	quickSort(a, l, j);
	quickSort(a, i, r);
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	quickSort(a, 1, n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
}
//chon Key la phan tu chinh giua mid = (l + r) / 2;
//https://www.stdio.vn/giai-thuat-lap-trinh/quick-sort-hlmLf1
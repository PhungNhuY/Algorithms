#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void sapXep(vector<int>& a, int n, int node)
{
	int newNode = node;
	if (node * 2 <= n && a[node*2] > a[newNode])
		newNode = node * 2;
	if (node * 2 + 1 <= n && a[node*2+1] > a[newNode])
		newNode = node * 2 + 1;
	if (newNode != node)
	{
		swap(a[node], a[newNode]);
		sapXep(a, n, newNode);
	}
}
void makeHeap(vector<int>& a, int n)
{
	for (int i = n / 2; i >= 1; i--)
		sapXep(a, n, i);
}
void pushHeap(vector<int>& a, int& n, int value)
{
	n++;
	a.push_back(value);
	int node = n;
	while (node != 1)
	{
		if (a[node] > a[node / 2])
		{
			swap(a[node], a[node / 2]);
			node /= 2;
		}
		else
			break;
	}
}
int popHeap(vector<int>& a, int& n)
{
	if (n != 0)
	{
		int ans = a[1];
		a[1] = a[n];
		a.pop_back();
		n--;
		sapXep(a, n, 1);
		return ans;
	}
	return INT_MIN;
}
void heapSort(vector<int>& a, int n)
{
	makeHeap(a, n);
	for (int i = n; i >= 1; i--)
	{
		swap(a[1], a[i]);
		sapXep(a, i - 1, 1);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	heapSort(a, n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
}
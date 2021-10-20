#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100005;
int n, t, x, l, r;
int a[maxn], tree[4 * maxn];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = min(tree[node * 2], tree[node * 2+1]);
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start || end < l)
        return INT_MAX;
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
}
void update(int node, int start, int end, int node_update, int value)
{
    if (node_update<start || node_update>end)
        return;
    if (start == end) 
    {
        tree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    if (mid >= node_update)
        update(node * 2, start, mid, node_update, value);
    else
        update(node * 2 + 1, mid + 1, end, node_update, value);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);
    cin >> t;
    while (t--)
    {
        cin >> x >> l >> r;
        if (x == 1)
            update(1, 1, n, l, r);
        else
            cout << query(1, 1, n, l, r) << endl;
    }
}
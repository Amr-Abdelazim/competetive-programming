/*
ID: amr_abdelazim
LANG: C++
TASK: heritage
*/
#ifndef LOCAL
#include <bits/stdc++.h>
// For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(...) 8
#else
#include "precompiled.h"
#include "debug.h"
#endif

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define bit(mask, i) (((mask) >> (i)) & 1)

template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 5e5 + 5, M = 26, infint = 2e9;
const ll infll = 2e18;

string in, pre;
int dx[M];
array<int, 2> gr[M];
int solve(int l, int r)
{
    if (l > r)
        return -1;
    int mn = l;
    for (int i = l; i <= r; i++)
    {
        if (dx[in[i] - 'A'] < dx[in[mn] - 'A'])
            mn = i;
    }
    gr[mn][0] = solve(l, mn - 1);
    gr[mn][1] = solve(mn + 1, r);
    return mn;
}
void dfs(int u)
{
    if (u == -1)
        return;
    dfs(gr[u][0]);
    dfs(gr[u][1]);
    cout << in[u];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);

    cin >> in >> pre;
    int n = in.size();
    rep(i, n)
    {
        dx[pre[i] - 'A'] = i;
    }
    int root = solve(0, n - 1);
    dfs(root);
    cout << "\n";

    return 0;
}
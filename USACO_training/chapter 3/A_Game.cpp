/*
ID: amr_abdelazim
LANG: C++
TASK: game1
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
const int N = 200 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;
int dp[N][N];
int a[N];
int fun(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return a[l];
    int &ans = dp[l][r];
    if (ans != -1)
        return ans;
    return ans = max(a[l] + min(fun(l + 2, r), fun(l + 1, r - 1)), a[r] + min(fun(l, r - 2), fun(l + 1, r - 1)));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);

    int n, sm = 0;
    cin >> n;
    rep(i, n) cin >> a[i], sm += a[i];
    memset(dp, -1, sizeof(dp));
    int first = fun(0, n - 1);
    cout << first << " " << sm - first << "\n";

    return 0;
}
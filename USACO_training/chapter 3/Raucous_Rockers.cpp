/*
ID: amr_abdelazim
LANG: C++
TASK: rockers
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
const int N = 20 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;
int n, t, m;
int dp[N][N][N];
int a[N];
int fun(int i, int rem, int cnt)
{
    if (i >= n)
        return 0;
    int &ans = dp[i][rem][cnt];
    if (ans != -1)
        return ans;
    ans = fun(i + 1, rem, cnt);
    if (rem >= a[i])
        ans = max(fun(i + 1, rem - a[i], cnt) + 1, ans);
    else if (cnt > 0)
        ans = max(ans, fun(i, t, cnt - 1));
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);

    cin >> n >> t >> m;
    rep(i, n)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << fun(0, t, m - 1) << "\n";

    return 0;
}
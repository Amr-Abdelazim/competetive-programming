/*
ID: amr_abdelazim
LANG: C++
TASK: nuggets
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
const int N = 2e6 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;
int dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    dp[0] = 1;
    int ans = 0;
    rep(cur, N)
    {
        rep(i, n)
        {
            if (a[i] <= cur)
            {
                dp[cur] = max(dp[cur], dp[cur - a[i]]);
            }
        }
        if (!dp[cur])
            ans = cur;
    }
    if (ans > (int)1e6)
        ans = 0;
    cout << ans << "\n";

    return 0;
}
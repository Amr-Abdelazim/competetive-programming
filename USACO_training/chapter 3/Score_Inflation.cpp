/*
ID: amr_abdelazim
LANG: C++
TASK: inflate
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
#define rep(i, n) for (int i = 0; i < n; i++)
#define bit(mask, i) (((mask) >> (i)) & 1)

template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 5e5 + 5, infint = 2e9;
const ll infll = 2e18;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    int m, n;
    cin >> m >> n;
    vector<int> P(n), M(n);
    rep(i, n)
    {
        cin >> P[i] >> M[i];
    }
    vector<int> dp(m + 1);
    rep(i, n)
    {
        vector<int> cur(m + 1);
        for (int j = 1; j <= m; j++)
        {
            cur[j] = dp[j];
            if (j >= M[i])
                cur[j] = max({cur[j - M[i]] + P[i], dp[j - M[i]] + P[i], cur[j]});
        }
        dp = cur;
    }
    cout << dp[m] << "\n";
    return 0;
}
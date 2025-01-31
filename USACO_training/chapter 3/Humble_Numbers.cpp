/*
ID: amr_abdelazim
LANG: C++
TASK: humble
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
const int N = 5e5 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);

    int k, n;
    cin >> k >> n;
    vector<ll> p(k), dp(n + 1, infll), lst(k);
    rep(i, k) cin >> p[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        rep(j, k)
        {
            while (lst[j] < i)
            {
                if (dp[lst[j]] * p[j] > dp[i - 1])
                {
                    break;
                }
                lst[j]++;
            }
            dp[i] = min(dp[i], dp[lst[j]] * p[j]);
        }
    }
    cout << dp[n] << "\n";

    return 0;
}
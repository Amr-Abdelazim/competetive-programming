/*
ID: amr_abdelazim
LANG: C++
TASK: nocows
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
const int N = 200 + 5, M = 20, infint = 2e9, mod = 9901;
const ll infll = 2e18;

int n, K;
int dp[N][N][2];
int Solve()
{

    cin >> n >> K;
    for (int i = 0; i < K; i++)
        dp[0][i][0] = 1;
    dp[0][K - 1][1] = 1;

    // dp[i][k][0]  Number of trees with exactly i + 1 nodes, height <= k.
    // dp[i][k][1]  Number of trees with exactly i + 1 nodes, height = k.
    for (int k = K - 2; k >= 0; k--)
    {
        for (int i = 2; i < n; i += 2)
        {

            for (int j = 0; j <= i - 2; j += 2)
            {
                dp[i][k][0] += (1ll * dp[i - j - 2][k + 1][0] * dp[j][k + 1][0]) % mod;

                dp[i][k][1] += (1ll * dp[i - j - 2][k + 1][1] * dp[j][k + 1][0]) % mod;
                dp[i][k][1] += (1ll * dp[i - j - 2][k + 1][0] * dp[j][k + 1][1]) % mod;
                dp[i][k][1] -= (1ll * dp[i - j - 2][k + 1][1] * dp[j][k + 1][1]) % mod;

                dp[i][k][0] %= mod;
                dp[i][k][1] %= mod;
            }
        }
    }
    cout << dp[n - 1][0][1] << "\n";

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
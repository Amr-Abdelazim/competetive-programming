/*
ID: amr_abdelazim
LANG: C++
TASK: kimbits
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
const int N = 5e5 + 5, M = 50, infint = 2e9;
const ll infll = 2e18;
ll memo[M][M];
ll ncr(ll n, ll r)
{
    if (n == 0)
        return 1;
    if (r <= 0)
        return 1;
    if (memo[n][r] != -1)
        return memo[n][r];
    ll ans = 1, cur = n, d = 1;
    for (int i = 1; i <= n - r; i++)
    {
        ans *= cur;
        cur--;
        d *= i;
        if (ans % d == 0)
            ans /= d, d = 1;
    }
    if (n < r)
        ans = 0;
    return memo[n][r] = ans + ncr(n, r - 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    memset(memo, -1, sizeof(memo));
    ll n, l, k;
    cin >> n >> l >> k;
    string ans;
    rep(i, n)
    {
        int sz = n - i;

        ll val = ncr(sz - 1, l);
        if (val >= k)
        {
            ans += "0";
        }
        else
        {
            k -= val;
            ans += "1";
            l--;
        }
    }
    cout << ans << "\n";
    return 0;
}
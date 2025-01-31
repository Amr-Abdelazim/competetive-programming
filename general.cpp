/*
ID: amr_abdelazim
LANG: C++
TASK: test
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
const int N = 1e6 + 5, M = 20, infint = 2e9, mod = 998244353;
const ll infll = 2e18;

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];
    if (n == 1)
    {
        ll lc = 0;
        rep(j, m) lc = lcm(lc, b[j]);
        if (lc != a[0])
        {
            int bb = 0;
            rep(i, m)
            {
                if (b[i] == a[0])
                    bb = 1;
            }
            rep(i, m)
            {
                if (a[0] % b[i])
                    bb = 0;
            }
            if (!bb)
                return cout << "No\n", 0;
        }
        cout << "Yes\n";
        rep(j, m) cout << b[j] << " ";
        return 0;
    }
    if (m == 1)
    {
        int g = 0;
        rep(i, n) g = __gcd(g, a[i]);
        if (g != b[0])
        {
            return cout << "No\n", 0;
        }
        cout << "Yes\n";
        rep(i, n) cout << a[i] << "\n";
        return 0;
    }
    vector<vector<int>> ans(n, vector<int>(m));
    rep(i, n)
    {
        rep(j, m)
        {
            if (a[i] % b[j])
                return cout << "No\n", 0;
            if (i == j)
                ans[i][j] = a[i];
            else
                ans[i][j] = b[j];
        }
    }
    cout << "Yes\n";
    rep(i, n)
    {
        rep(j, m)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
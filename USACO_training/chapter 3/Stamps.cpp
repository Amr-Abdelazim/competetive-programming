/*
ID: amr_abdelazim
LANG: C++
TASK: stamps
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
const int N = 2e6 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;
int B[N];
int Solve()
{
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, N) B[i] = infint;
    rep(i, n)
    {
        cin >> a[i];
        B[a[i]] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        for (auto j : a)
        {
            if (j <= i)
                B[i] = min(B[i - j] + 1, B[i]);
        }
    }
    int ans = 0, c = 0;
    rep(i, N)
    {
        if (B[i] <= k)
            c++;
        else
        {
            ans = max(ans, c);
            c = 0;
        }
    }
    ans = max(ans, c);
    cout << ans << "\n";
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
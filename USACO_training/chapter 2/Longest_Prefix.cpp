/*
ID: amr_abdelazim
LANG: C++
TASK: prefix
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

int Solve()
{
    set<string> vs;
    string in;
    while (cin >> in)
    {
        if (in == ".")
            break;
        vs.insert(in);
    }
    string s;
    while (cin >> in)
    {
        s += in;
    }
    vector<int> dp(s.size() + 1);
    iota(all(dp), 0);
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int sz = 1; sz <= 10 && i + sz <= s.size(); sz++)
        {
            if (vs.count(s.substr(i, sz)))
                dp[i] = max(dp[i], dp[i + sz]);
        }
    }
    cout << dp[0] << "\n";

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
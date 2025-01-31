/*
ID: amr_abdelazim
LANG: C++
TASK: agrinet
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

    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> p(n);
    iota(all(p), 0);

    auto find = [&](auto &self, int u)
    {
        if (u == p[u])
            return u;
        return p[u] = self(self, p[u]);
    };

    vector<vector<int>> edges;
    rep(i, n)
    {
        rep(j, n)
        {
            int x;
            cin >> x;
            edges.push_back({x, i, j});
        }
    }
    sort(all(edges));
    ll ans = 0;
    for (auto e : edges)
    {
        int fa = find(find, e[1]);
        int fb = find(find, e[2]);
        if (fa != fb)
        {
            p[fa] = fb;
            ans += e[0];
        }
    }
    cout << ans << "\n";

    return 0;
}
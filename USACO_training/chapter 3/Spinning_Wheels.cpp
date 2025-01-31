/*
ID: amr_abdelazim
LANG: C++
TASK: spin
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
const int N = 1e5, M = 20, infint = 2e9;
const ll infll = 2e18;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);

    vector<vector<pii>> v(5);
    vector<int> speed(5);
    rep(i, 5)
    {
        cin >> speed[i];
        int k;
        cin >> k;
        rep(j, k)
        {
            int st, sz;
            cin >> st >> sz;
            v[i].push_back({st, sz});
        }
    }
    for (int time = 0; time < N; time++)
    {
        vector<int> cnt(360);
        rep(i, 5)
        {
            for (auto p : v[i])
            {
                int cur = (p.first + speed[i] * time) % 360;
                rep(k, p.second + 1)
                {
                    cnt[cur]++;
                    cur++;
                    cur %= 360;
                }
            }
        }
        rep(i, cnt.size())
        {
            if (cnt[i] == 5)
                return cout << time << "\n", 0;
        }
    }
    cout << "none\n";

    return 0;
}
/*
ID: amr_abdelazim
LANG: C++
TASK: fact4
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
const int N = 5e5 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);

    int n;
    cin >> n;
    int ans = 1;
    vector<int> cnt(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x = i;
        for (int j = 2; j * j <= x; j++)
        {
            while (x % j == 0)
            {
                x /= j;
                cnt[j]++;
            }
        }
        if (x > 1)
            cnt[x]++;
    }
    int mn = min(cnt[2], cnt[5]);
    cnt[2] -= mn;
    cnt[5] -= mn;
    rep(i, n + 1)
    {
        while (cnt[i]--)
        {
            ans = (ans * i) % 10;
        }
    }
    cout << ans << "\n";

    return 0;
}
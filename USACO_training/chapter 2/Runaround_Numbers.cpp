/*
ID: amr_abdelazim
LANG: C++
TASK: runround
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
string s, cur;
ll ans = infll;
void solve()
{
    int dx = 0;
    vector<int> vis(10);
    int cnt = 0;
    while (!vis[dx])
    {
        cnt++;
        vis[dx]++;
        dx += (cur[dx] - '0');
        dx %= cur.size();
    }
    if (cnt == cur.size() && dx == 0)
    {
        ans = min(ans, stoll(cur));
    }
}
int sz;
void fun(int i, int c, int msk)
{
    if (i == sz && c)
    {
        solve();
        return;
    }
    char bg = '1';
    if (!c)
        bg = s[i];
    for (char ch = bg; ch <= '9'; ch++)
    {
        if (bit(msk, ch - '1'))
            continue;
        int nc = (c || ch > bg);
        cur += ch;
        fun(i + 1, nc, msk ^ (1 << (ch - '1')));
        cur.pop_back();
    }
}

int Solve()
{

    cin >> s;
    sz = s.size();
    while (sz <= 9)
    {
        fun(0, sz > s.size(), 0);
        sz++;
    }
    cout << ans << "\n";

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
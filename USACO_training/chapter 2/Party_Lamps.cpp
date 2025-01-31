/*
ID: amr_abdelazim
LANG: C++
TASK: lamps
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
const int N = 100 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;
int n;
int fstate[N], vis[10000 + 5][20];
vector<vector<int>> ans;
void fun(int c, int msk)
{
    if (vis[c][msk])
        return;
    vis[c][msk] = 1;
    if (!c)
    {
        vector<int> cstate(n, !bit(msk, 0));
        if (bit(msk, 1))
        {
            for (int i = 0; i < n; i += 2)
                cstate[i] ^= 1;
        }
        if (bit(msk, 2))
        {
            for (int i = 1; i < n; i += 2)
                cstate[i] ^= 1;
        }
        if (bit(msk, 3))
        {
            for (int i = 0; i * 3 + 1 <= n; i++)
                cstate[i * 3] ^= 1;
        }
        int bb = 1;
        for (int i = 0; i < n; i++)
        {
            if (fstate[i] != -1 && fstate[i] != cstate[i])
            {
                bb = 0;
                break;
            }
        }
        if (bb)
            ans.push_back(cstate);
        return;
    }
    rep(i, 4)
    {
        fun(c - 1, msk ^ (1 << i));
    }
}
int Solve()
{
    int c;
    cin >> n >> c;
    memset(fstate, -1, sizeof(fstate));
    int x;
    while (cin >> x)
    {
        if (x == -1)
            break;
        fstate[x - 1] = 1;
    }
    while (cin >> x)
    {
        if (x == -1)
            break;
        fstate[x - 1] = 0;
    }
    fun(c, 0);
    if (ans.empty())
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    sort(all(ans));
    for (auto v : ans)
    {
        for (auto i : v)
            cout << i;
        cout << "\n";
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
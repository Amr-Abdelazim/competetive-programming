/*
ID: amr_abdelazim
LANG: C++
TASK: ttwo
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
const int N = 10 + 1, M = 20, infint = 2e9, limit = 160001;
const ll infll = 2e18;

vector<string> a(10);
int n = 10;
//   dir = {up : 0, right : 1, down : 2, left : 3}
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void move(int &i, int &j, int &dir)
{
    int ni = i + dy[dir];
    int nj = j + dx[dir];
    if (ni < 0 || ni >= n || nj < 0 || nj >= 10 || a[ni][nj] == '*')
    {
        dir = (dir + 1) % 4;
        return;
    }
    i = ni;
    j = nj;
}
int Solve()
{
    rep(i, n) cin >> a[i];
    pii Fdx, Cdx;
    rep(i, n)
    {
        rep(j, n)
        {
            if (a[i][j] == 'F')
                Fdx = {i, j};
            if (a[i][j] == 'C')
                Cdx = {i, j};
        }
    }

    int ans = 0;
    int Cdir = 0, Fdir = 0;
    rep(d, limit)
    {
        // debug(Cdx, Fdx, Cdir, Fdir);
        if (Fdx == Cdx)
        {
            ans = d;
            break;
        }
        move(Fdx.first, Fdx.second, Fdir);
        move(Cdx.first, Cdx.second, Cdir);
    }
    cout << ans << "\n";

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
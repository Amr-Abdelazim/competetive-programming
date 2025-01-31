/*
ID: amr_abdelazim
LANG: C++
TASK: cowtour
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
const int N = 150 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;
const double EPS = 1e-9;
int x[N], y[N];

double min_dis[N][N], farest[N];
int connected[N][N];

double distance(int i, int j)
{
    return (double)sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (double)(y[i] - y[j]) * (y[i] - y[j]));
}
int Solve()
{
    int n;
    cin >> n;
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {
            connected[i][j] = (s[j] - '0');
            min_dis[i][j] = infint;
            if (connected[i][j])
                min_dis[i][j] = distance(i, j);
        }
    }

    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                min_dis[i][j] = min({min_dis[i][j], min_dis[i][k] + min_dis[k][j]});
            }
        }
    }

    double ans = 0;
    rep(i, n)
    {
        rep(j, n)
        {

            if (min_dis[i][j] < infint - EPS && i != j)
            {
                ans = max(ans, min_dis[i][j]);
                farest[i] = max(farest[i], min_dis[i][j]);
            }
        }
    }

    // debug(ans);
    double mn = infint;
    rep(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (min_dis[i][j] < infint - EPS)
                continue;
            mn = min(mn, farest[i] + distance(i, j) + farest[j]);
        }
    }
    cout << fixed << setprecision(6) << max(ans, mn) << "\n";

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
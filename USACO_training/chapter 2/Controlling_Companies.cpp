/*
ID: amr_abdelazim
LANG: C++
TASK: concom
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
const int N = 101, M = 20, infint = 20000;
const ll infll = 2e18;
int own[N][N], control[N][N];

void addcontroller(int a, int b)
{
    if (control[a][b])
        return;
    control[a][b] = 1;
    for (int i = 1; i < N; i++)
    {
        own[a][i] += own[b][i];
    }
    for (int i = 1; i < N; i++)
    {
        if (control[b][i] || own[a][i] > 50)
            addcontroller(a, i);
    }
}

void addowner(int a, int b, int c)
{
    for (int i = 1; i < N; i++)
    {
        if (control[i][a])
        {
            own[i][b] += c;
        }
        if (own[i][b] > 50)
            addcontroller(i, b);
    }
}

int Solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < N; i++)
    {
        control[i][i] = 1;
    }
    rep(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        addowner(a, b, c);
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (i == j || !control[i][j])
                continue;
            cout << i << " " << j << "\n";
        }
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
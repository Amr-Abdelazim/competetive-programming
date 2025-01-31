/*
ID: amr_abdelazim
LANG: C++
TASK: ratios
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
const int N = 5e5 + 5, M = 101, infint = 2e9;
const ll infll = 2e18;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);

    vector<array<int, 3>> v(4);
    rep(i, 4)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    array<int, 4> ans = {-1, -1, -1, -1};
    int mn = infint;
    for (int a = 0; a <= M; a++)
    {
        for (int b = 0; b <= M; b++)
        {
            for (int c = 0; c <= M; c++)
            {
                set<int> st;
                int A = a * v[1][0] + b * v[2][0] + c * v[3][0];
                int B = a * v[1][1] + b * v[2][1] + c * v[3][1];
                int C = a * v[1][2] + b * v[2][2] + c * v[3][2];
                vector<int> ar = {A, B, C};
                int bb = 1, val = -1;
                rep(k, 3)
                {
                    if (v[0][k] == 0)
                    {
                        if (ar[k] != 0)
                            bb = 0;
                    }
                    else
                    {
                        if (ar[k] == 0 || ar[k] % v[0][k])
                            bb = 0;
                        else
                        {
                            int cur = ar[k] / v[0][k];
                            if (val == -1)
                                val = cur;
                            else
                            {
                                if (val != cur)
                                    bb = 0;
                            }
                        }
                    }
                }
                if (bb)
                {
                    if (a + b + c < mn)
                    {
                        ans = {a, b, c, val};
                        mn = a + b + c;
                    }
                }
            }
        }
    }
    if (ans[0] == -1)
    {
        cout << "NONE";
    }
    else
        rep(i, 4)
        {
            cout << ans[i];
            if (i != 3)
                cout << " ";
        }
    cout << "\n";

    return 0;
}
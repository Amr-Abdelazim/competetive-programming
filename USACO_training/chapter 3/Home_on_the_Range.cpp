/*
ID: amr_abdelazim
LANG: C++
TASK: range
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

    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);

    int n;
    cin >> n;
    vector<vector<int>> sm(n, vector<int>(n));
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {
            sm[i][j] += s[j] - '0';
            if (j)
                sm[i][j] += sm[i][j - 1];
            if (i)
                sm[i][j] += sm[i - 1][j];
            if (i && j)
                sm[i][j] -= sm[i - 1][j - 1];
        }
    }
    vector<int> ans(n + 1);
    rep(i, n)
    {
        rep(j, n)
        {
            for (int sz = 2; sz <= n; sz++)
            {
                int ei = i + sz - 1, ej = j + sz - 1;
                if (ei >= n || ej >= n)
                    break;
                int cur = sm[ei][ej];
                if (i)
                    cur -= sm[i - 1][ej];
                if (j)
                    cur -= sm[ei][j - 1];
                if (i && j)
                    cur += sm[i - 1][j - 1];
                if (cur == sz * sz)
                {
                    ans[sz]++;
                }
            }
        }
    }
    rep(i, n + 1)
    {
        if (ans[i] != 0)
            cout << i << " " << ans[i] << "\n";
    }

    return 0;
}
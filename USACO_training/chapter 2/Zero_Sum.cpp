/*
ID: amr_abdelazim
LANG: C++
TASK: zerosum
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
int n;
string cur;
vector<string> ans;
void fun(int i)
{
    if (i > n)
    {
        int sn = 1, tot = 0, lst = 0;
        for (auto c : cur)
        {
            if (c == ' ')
                continue;
            if (c >= '1' && c <= '9')
            {
                lst = lst * 10 + (c - '0');
            }
            else
            {
                tot += sn * lst;
                lst = 0;
                if (c == '-')
                    sn = -1;
                else
                    sn = 1;
            }
        }
        tot += sn * lst;
        if (tot == 0)
            ans.push_back(cur);

        return;
    }
    cur += "+" + to_string(i);
    fun(i + 1);
    cur.pop_back();
    cur.pop_back();
    cur += "-" + to_string(i);
    fun(i + 1);
    cur.pop_back();
    cur.pop_back();
    cur += " " + to_string(i);
    fun(i + 1);
    cur.pop_back();
    cur.pop_back();
}
int Solve()
{
    cin >> n;
    cur += "1";
    fun(2);
    sort(all(ans));
    for (auto s : ans)
        cout << s << "\n";

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
/*
ID: amr_abdelazim
LANG: C++
TASK: preface
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
vector<pair<int, string>> roman = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
int cnt[30];
void solve(int x)
{
    for (auto cur : roman)
    {
        int c = x / cur.first;
        for (auto j : cur.second)
            cnt[j - 'A'] += c;
        x -= c * cur.first;
    }
}

int Solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        solve(i);
    string s = "IVXLCDM";
    for (auto i : s)
    {
        if (!cnt[i - 'A'])
            continue;
        cout << i << " " << cnt[i - 'A'] << "\n";
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
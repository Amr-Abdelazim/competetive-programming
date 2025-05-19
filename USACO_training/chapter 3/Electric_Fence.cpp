/*
ID: amr_abdelazim
LANG: C++
TASK: fence9
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
int calc(int a, int b, int c, int d)
{
    return abs(__gcd(c - a, d - b));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);

    int n, m, p;
    cin >> n >> m >> p;
    int A = (p * m);
    int B = calc(0, 0, n, m);
    B += calc(0, 0, p, 0);
    B += calc(p, 0, n, m);
    A -= B;
    A += 2;

    cout << A / 2 << "\n";

    return 0;
}
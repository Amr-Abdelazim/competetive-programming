/*
ID: amr_abdelazim
LANG: C++
TASK: shopping
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
const int N = 1000 + 5, M = 20, infint = 2e9;
const ll infll = 2e18;

int offerPrice[N], offerscnt;
vector<pii> offers[N];
int originalPrice[N];
vector<int> targetProducts;
int idx[N];
int calc(vector<int> &a)
{
    int ans = 0;
    rep(i, a.size())
    {
        ans += a[i] * originalPrice[i];
    }
    return ans;
}
int dp[500000];
int fun(vector<int> a)
{

    int msk = 0, cur = 1;
    rep(i, a.size())
    {
        msk += cur * a[i];
        cur *= 6;
    }
    if (dp[msk] != -1)
        return dp[msk];
    dp[msk] = calc(a);

    rep(i, offerscnt)
    {
        auto tmp = a;
        int bb = 1;
        for (auto v : offers[i])
        {
            if (idx[v.first] == -1)
            {
                bb = 0;
                continue;
            }
            if (a[idx[v.first]] >= v.second)
            {
                a[idx[v.first]] -= v.second;
            }
            else
                bb = 0;
        }
        if (bb)
        {
            dp[msk] = min(dp[msk], fun(a) + offerPrice[i]);
        }
        a = tmp;
    }
    return dp[msk];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);

    cin >> offerscnt;
    rep(i, offerscnt)
    {
        int n;
        cin >> n;
        rep(j, n)
        {
            int c, k;
            cin >> c >> k;
            offers[i].push_back({c, k});
        }
        cin >> offerPrice[i];
    }
    int b;
    cin >> b;
    vector<int> a(b);
    targetProducts = vector<int>(b);
    memset(idx, -1, sizeof(idx));
    rep(i, b)
    {
        int p;
        cin >> targetProducts[i] >> a[i] >> p;
        originalPrice[i] = p;
        idx[targetProducts[i]] = i;
    }
    memset(dp, -1, sizeof(dp));

    cout << fun(a) << "\n";
    return 0;
}
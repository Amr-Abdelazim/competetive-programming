/*
ID: amr_abdelazim
LANG: C++
TASK: butter
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

    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);

    int n, p, c;
    cin >> n >> p >> c;
    vector<int> cnt(p);
    rep(i, n)
    {
        int x;
        cin >> x;
        cnt[x - 1]++;
    }
    vector<vector<array<int, 2>>> gr(p);
    rep(i, c)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        gr[a].push_back({b, w});
        gr[b].push_back({a, w});
    }
    int ans = infint;
    rep(start, p)
    {
        vector<int> dis(p, infint), vis(p);
        dis[start] = 0;
        priority_queue<pii, vector<pii>, greater<>> q;
        q.push({0, start});
        while (q.size())
        {
            int cur = q.top().second;
            q.pop();
            if (vis[cur])
                continue;
            vis[cur] = 1;
            for (auto i : gr[cur])
            {
                int u = i[0], w = i[1];
                if (!vis[u] && dis[u] > dis[cur] + w)
                {
                    dis[u] = dis[cur] + w;
                    q.push({dis[u], u});
                }
            }
        }
        int res = 0;
        rep(i, p)
        {
            res += dis[i] * cnt[i];
        }
        ans = min(ans, res);
    }
    cout << ans << "\n";

    return 0;
}
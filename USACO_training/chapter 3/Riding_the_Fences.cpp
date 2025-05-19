/*
ID: amr_abdelazim
LANG: C++
TASK: fence
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
const int N = 500 + 5, M = 1024 + 5, infint = 2e9;
const ll infll = 2e18;
vector<pii> gr[N];
int vis[M];
vector<int> path;
void dfs(int u)
{
    while (gr[u].size())
    {
        auto cur = gr[u].back();
        gr[u].pop_back();
        if (vis[cur.second])
            continue;
        vis[cur.second] = 1;
        dfs(cur.first);
    }
    path.push_back(u);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    int m;
    cin >> m;
    set<int> st;
    vector<int> deg(N);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;

        st.insert(a);
        st.insert(b);
        deg[a]++;
        deg[b]++;
        gr[a].push_back({b, i});
        gr[b].push_back({a, i});
    }
    rep(i, N) sort(rall(gr[i]));
    int bb = 0;
    for (auto i : st)
    {
        if (deg[i] & 1)
        {
            bb = 1;
            dfs(i);
            break;
        }
    }
    if (!bb)
    {
        dfs(*st.begin());
    }
    reverse(all(path));
    for (auto i : path)
        cout << i << "\n";
    return 0;
}
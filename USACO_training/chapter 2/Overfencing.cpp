/*
ID: amr_abdelazim
LANG: C++
TASK: maze1
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
//   dir = {up : 0, right : 1, down : 2, left : 3}
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int dx2[] = {0, 2, 0, -2};
int dy2[] = {-2, 0, 2, 0};
int Solve()
{
    int n, m;
    cin >> m >> n;
    vector<string> grid(2 * n + 1);
    cin.ignore();
    rep(i, grid.size())
    {
        getline(cin, grid[i]);
        if (grid[i].size() != 2 * m + 1)
            grid[i] += "  ";
    }
    vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), infint));
    auto onEdge = [&](int i, int j)
    {
        if (i <= 0 || i >= (int)grid.size() - 1 || j <= 0 || j >= (int)grid[0].size() - 1)
            return true;
        return false;
    };
    auto bfs = [&](int si, int sj)
    {
        queue<pii> q;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size()));
        q.push({si, sj});
        vis[si][sj] = 1;
        int curent_distance = 1;
        while (q.size())
        {
            int sz = q.size();
            while (sz--)
            {
                auto cur = q.front();
                q.pop();
                distance[cur.first][cur.second] = min(curent_distance, distance[cur.first][cur.second]);
                rep(k, 4)
                {
                    int ni = cur.first + dy[k], nj = cur.second + dx[k];
                    int ni2 = cur.first + dy2[k], nj2 = cur.second + dx2[k];
                    if (!onEdge(ni2, nj2) && grid[ni2][nj2] == ' ' && !onEdge(ni, nj) && grid[ni][nj] == ' ' && !vis[ni2][nj2])
                    {
                        q.push({ni2, nj2});
                        vis[ni2][nj2] = 1;
                    }
                }
            }
            curent_distance++;
        }
    };
    // debug(onEdge(5, 10), grid[5].size());
    rep(i, grid.size())
    {
        rep(j, grid[0].size())
        {
            if (grid[i][j] == ' ' && onEdge(i, j))
            {
                if (i == 0)
                    bfs(i + 1, j);
                else if (j == 0)
                    bfs(i, j + 1);
                else if (i == (int)grid.size() - 1)
                    bfs(i - 1, j);
                else if (j == (int)grid[0].size() - 1)
                    bfs(i, j - 1);
                // debug(i, j);
            }
        }
    }
    int ans = 1;
    rep(i, distance.size())
    {
        rep(j, distance[0].size())
        {
            if ((i & 1) && (j & 1) && grid[i][j] == ' ')
            {
                // debug(distance[i][j]);
                ans = max(ans, distance[i][j]);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
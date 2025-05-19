/*
ID: amr_abdelazim
LANG: C++
TASK: camelot
*/
/* #pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,sse4a,avx,avx2,popcnt,tune=native") */
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
const int N = 30, M = 26, infint = 2e9;
const ll infll = 2e18;

int dkx[] = {1, 1, -1, -1, 2, -2, 2, -2};
int dky[] = {2, -2, 2, -2, 1, 1, -1, -1};
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dis[N][M][N][M];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    pii king;
    char _;
    cin >> _ >> king.first;
    king.second = (_ - 'A');
    king.first--;
    vector<pii> knights;
    while (cin >> _)
    {
        int x;
        cin >> x;
        knights.push_back({x - 1, _ - 'A'});
    }
    fill(&dis[0][0][0][0], &dis[0][0][0][0] + N * M * N * M, infint);
    rep(s1, n)
    {
        rep(s2, m)
        {
            dis[s1][s2][s1][s2] = 0;
            queue<pii> q;
            q.push({s1, s2});
            while (q.size())
            {
                auto cur = q.front();
                q.pop();
                rep(k, 8)
                {
                    int ni = cur.first + dkx[k], nj = cur.second + dky[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || dis[s1][s2][ni][nj] <= dis[s1][s2][cur.first][cur.second] + 1)
                        continue;
                    dis[s1][s2][ni][nj] = dis[s1][s2][cur.first][cur.second] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }

    queue<pii> q;
    q.push(king);
    int lv = 1;
    vector<vector<int>> disK(n, vector<int>(m, infint));
    disK[king.first][king.second] = 0;
    vector<pii> points;
    while (q.size())
    {
        int sz = q.size();
        rep(ss, sz)
        {
            auto cur = q.front();
            q.pop();
            points.push_back(cur);
            rep(k, 8)
            {
                int ni = cur.first + dx[k], nj = cur.second + dy[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || disK[ni][nj] <= lv)
                    continue;
                disK[ni][nj] = lv;
                q.push({ni, nj});
            }
        }
        lv++;
    }
    int ans = infint;
    rep(t1, n)
    {

        rep(t2, m)
        {
            int sm = 0;
            bool valid = true;
            for (auto cur : knights)
            {
                int d = dis[cur.first][cur.second][t1][t2];
                if (d >= infint)
                    valid = false;
                sm += d;
            }
            if (!valid)
                continue;
            ans = min(ans, sm + disK[t1][t2]);
            int cc = 100;
            for (auto point : points)
            {
                if (disK[point.first][point.second] >= disK[t1][t2])
                    break;
                cc--;
                if (cc <= 0)
                    break;

                for (auto cur : knights)
                {
                    if (dis[cur.first][cur.second][point.first][point.second] >= infint)
                        continue;
                    int d = dis[cur.first][cur.second][point.first][point.second] + dis[point.first][point.second][t1][t2] + disK[point.first][point.second];
                    ans = min(ans, sm - dis[cur.first][cur.second][t1][t2] + d);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
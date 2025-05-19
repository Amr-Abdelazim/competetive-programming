/*
ID: amr_abdelazim
LANG: C++
TASK: test
*/
#include <bits/stdc++.h>
// For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug(...) 8

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
const int EMPTY = -1;
const int DO_NOTHING = -1;
const int STATION = 0;
const int RAIL_HORIZONTAL = 1;
const int RAIL_VERTICAL = 2;
const int RAIL_LEFT_DOWN = 3;
const int RAIL_LEFT_UP = 4;
const int RAIL_RIGHT_UP = 5;
const int RAIL_RIGHT_DOWN = 6;
const int COST_STATION = 5000;
const int COST_RAIL = 100;
const int RAIL_DIR[4][4] = {
    {-1, RAIL_RIGHT_UP, RAIL_VERTICAL, RAIL_LEFT_UP},      // up
    {RAIL_RIGHT_UP, -1, RAIL_RIGHT_DOWN, RAIL_HORIZONTAL}, // right
    {RAIL_VERTICAL, RAIL_RIGHT_DOWN, -1, RAIL_LEFT_DOWN},  // down
    {RAIL_LEFT_UP, RAIL_HORIZONTAL, RAIL_LEFT_DOWN, -1}};  // left
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx8[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int distance(pii a, pii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
vector<array<int, 3>> actions;
int mony;
struct Grid
{
    int n;
    vector<vector<pii>> p;
    vector<vector<int>> cel;
    Grid() {};
    void init(int n)
    {
        this->n = n;
        p = vector<vector<pii>>(n, vector<pii>(n));
        cel = vector<vector<int>>(n, vector<int>(n, EMPTY));
        rep(i, n)
        {
            rep(j, n)
            {
                p[i][j] = {i, j};
            }
        }
    }
    bool valid(int i, int j)
    {
        return !(i < 0 || i >= n || j < 0 || j >= n);
    }
    pii find(int u, int v)
    {
        if (p[u][v] == make_pair(u, v))
            return p[u][v];
        return p[u][v] = find(p[u][v].first, p[u][v].second);
    }
    void connect_cells(int i1, int j1, int i2, int j2)
    {
        if (!valid(i1, j1) || !valid(i2, j2))
            return;
        pii f1 = find(i1, j1);
        pii f2 = find(i2, j2);
        if (f1 == f2)
            return;
        p[f1.first][f1.second] = f2;
    }
    bool is_same(int i1, int j1, int i2, int j2)
    {
        pii f1 = find(i1, j1);
        pii f2 = find(i2, j2);
        return (f1 == f2);
    }
    void bld_station(int i, int j)
    {
        mony -= COST_STATION;
        rep(k, 4)
        {
            int ni = dx[k] + i, nj = dy[k] + j;
            connect_cells(i, j, ni, nj);
        }
        cel[i][j] = STATION;
        actions.push_back({cel[i][j], i, j});
    }
    void bld_rail(int type, int i, int j)
    {
        mony -= COST_RAIL;
        if (type == RAIL_HORIZONTAL)
        {
            connect_cells(i, j, i, j + 1);
            connect_cells(i, j, i, j - 1);
            cel[i][j] = RAIL_HORIZONTAL;
        }
        else if (type == RAIL_VERTICAL)
        {
            connect_cells(i, j, i + 1, j);
            connect_cells(i, j, i - 1, j);
            cel[i][j] = RAIL_VERTICAL;
        }
        else if (type == RAIL_LEFT_DOWN)
        {
            connect_cells(i, j, i, j - 1);
            connect_cells(i, j, i + 1, j);
            cel[i][j] = RAIL_LEFT_DOWN;
        }
        else if (type == RAIL_LEFT_UP)
        {
            connect_cells(i, j, i, j - 1);
            connect_cells(i, j, i - 1, j);
            cel[i][j] = RAIL_LEFT_UP;
        }
        else if (type == RAIL_RIGHT_UP)
        {
            connect_cells(i, j, i, j + 1);
            connect_cells(i, j, i - 1, j);
            cel[i][j] = RAIL_RIGHT_UP;
        }
        else if (type == RAIL_RIGHT_DOWN)
        {
            connect_cells(i, j, i, j + 1);
            connect_cells(i, j, i + 1, j);
            cel[i][j] = RAIL_RIGHT_DOWN;
        }
        else
        {
            debug(type);
            assert(false);
        }
        actions.push_back({cel[i][j], i, j});
    }
} grid;

struct process
{
    pii src, dist, prev;
    bool running, first_run;
    process(pii src, pii dist)
    {
        this->src = src;
        this->dist = dist;
        this->running = true;
        this->first_run = true;
        this->prev = {-1, -1};
    }
    int getDir(pii from, pii to)
    {
        int dir = 0;
        if (from.first != to.first)
        {
            if (from.first < to.first)
                dir = 0; // up
            else
                dir = 2; // down
        }
        else
        {
            if (from.second < to.second)
                dir = 3; // left
            else
                dir = 1; // right
        }
        return dir;
    }
    void bld(pii a, pii b, pii c)
    {
        if (first_run)
        {
            first_run = false;
            if (mony < COST_STATION)
            {
                actions.push_back({-1, -1, -1});
                running = false;
                return;
            }
            grid.bld_station(src.first, src.second);

            return;
        }
        if (grid.cel[b.first][b.second] != EMPTY)
        {
            if (mony < COST_STATION)
            {
                actions.push_back({-1, -1, -1});
                running = false;
                return;
            }
            grid.bld_station(b.first, b.second);
            return;
        }
        if (mony < COST_RAIL)
        {
            actions.push_back({-1, -1, -1});
            running = false;
            return;
        }
        int prevDir = getDir(a, b);
        int curDir = getDir(c, b);
        int type = RAIL_DIR[prevDir][curDir];
        grid.bld_rail(type, b.first, b.second);
    }
    void run()
    {

        if (src == dist)
        {
            if (mony < COST_STATION)
            {
                actions.push_back({-1, -1, -1});
                running = false;
                return;
            }
            grid.bld_station(src.first, src.second);
            running = false;
            return;
        }
        int mn = infint;
        int resi = -1, resj = -1;
        rep(k, 4) // i can make this selection beter
        {
            int ni = src.first + dx[k], nj = src.second + dy[k];
            if (!grid.valid(ni, nj))
                continue;
            int cur_dis = distance({ni, nj}, dist);
            if (cur_dis <= mn)
            {
                resi = ni;
                resj = nj;
                mn = cur_dis;
            }
            /* else if (cur_dis == mn && grid.cel[ni][nj] == STATION || grid.cel[ni][nj] == EMPTY)
            {
                resi = ni;
                resj = nj;
                mn = cur_dis;
            } */
        }
        bld(prev, src, {resi, resj});
        prev = src;
        src = {resi, resj};
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // freopen("test.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, m, q;
    cin >> n >> m >> mony >> q;
    grid.init(n);
    vector<pii> home(m), work(m);
    rep(i, m)
    {
        cin >> home[i].first >> home[i].second;
        cin >> work[i].first >> work[i].second;
    }
    auto walk2 = [](pii a)
    {
        vector<pii> ans;
        queue<pii> q;
        q.push(a);
        ans.push_back(a);
        set<pii> vis;
        vis.insert(a);
        while (q.size())
        {
            auto cur = q.front();
            q.pop();
            rep(k, 4)
            {
                int ni = cur.first + dx8[k], nj = cur.second + dy8[k];
                if (!grid.valid(ni, nj) || vis.count({ni, nj}) || distance(a, {ni, nj}) > 2)
                    continue;
                q.push({ni, nj});
                vis.insert({ni, nj});
                ans.push_back({ni, nj});
            }
        }
        return ans;
    };
    auto is_connected = [&](pii x, pii y)
    {
        vector<pii> a = walk2(x);
        vector<pii> b = walk2(y);
        int bb = 0;
        for (auto x : a)
        {
            if (bb)
                break;
            for (auto y : b)
            {
                if (bb)
                    break;
                if (grid.cel[x.first][x.second] == STATION && grid.cel[y.first][y.second] == STATION && grid.is_same(x.first, x.second, y.first, y.second))
                {
                    return true;
                }
            }
        }
        return false;
    };
    auto collect_mony = [&]()
    {
        rep(i, m)
        {
            vector<pii> a = walk2(home[i]);
            vector<pii> b = walk2(work[i]);
            int bb = 0;
            for (auto x : a)
            {
                if (bb)
                    break;
                for (auto y : b)
                {
                    if (bb)
                        break;
                    if (grid.cel[x.first][x.second] == STATION && grid.cel[y.first][y.second] == STATION && grid.is_same(x.first, x.second, y.first, y.second))
                    {
                        bb = 1;
                        mony += distance(home[i], work[i]);
                    }
                }
            }
        }
    };
    auto calc_income = [&]()
    {
        int ans = 0;
        rep(i, m)
        {
            vector<pii> a = walk2(home[i]);
            vector<pii> b = walk2(work[i]);
            int bb = 0;
            for (auto x : a)
            {
                if (bb)
                    break;
                for (auto y : b)
                {
                    if (bb)
                        break;
                    if (grid.cel[x.first][x.second] == STATION && grid.cel[y.first][y.second] == STATION && grid.is_same(x.first, x.second, y.first, y.second))
                    {
                        bb = 1;
                        ans += distance(home[i], work[i]);
                    }
                }
            }
        }
        return ans;
    };
    deque<int> ord(m), vis(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j)
         { return distance(home[i], work[i]) > distance(home[j], work[j]); });

    int rem = q;
    auto is_worth = [&](int cur)
    {
        if (vis[cur])
            return false;
        int tot_cost = distance(home[ord[cur]], work[ord[cur]]) * COST_RAIL + 2 * COST_STATION;
        if (tot_cost >= mony)
            return false;
        if (is_connected(home[ord[cur]], work[ord[cur]]))
            return false;
        int cnt = rem - distance(home[ord[cur]], work[ord[cur]]);
        if (cnt * distance(home[ord[cur]], work[ord[cur]]) > tot_cost)
        {
            rem -= distance(home[ord[cur]], work[ord[cur]]);
            return true;
        }
        return false;
    };
    int optMony = 0, optSz = 0;
    queue<process> processes;
    while (q--)
    {

        while (processes.size() && !processes.front().running)
        {
            processes.pop();
        }
        int cur = 0;
        if (processes.empty())
        {
            int tot = calc_income() * (q + 1) + mony;
            if (tot > optMony)
            {
                optMony = tot;
                optSz = actions.size();
            }
            bool is_it_realy_worth = is_worth(cur);
            while (cur < m && !is_it_realy_worth)
            {
                cur++;
                if (cur < m)
                    is_it_realy_worth = is_worth(cur);
            }
            if (cur < m && is_it_realy_worth)
            {
                processes.push(process(home[ord[cur]], work[ord[cur]]));
                vis[cur] = 1;
            }
        }
        if (processes.empty())
        {
            actions.push_back({-1, -1, -1});
        }
        else
            processes.front().run();
        if (actions.back()[0] == -1)
            rem--;
        collect_mony();
    }
    if (optMony > mony)
    {
        mony = optMony;
        for (int i = optSz; i < actions.size(); i++)
        {
            actions[i] = {-1, -1, -1};
        }
    }
    for (auto v : actions)
    {
        if (v[0] == -1)
            cout << "-1\n";
        else
            cout << v[0] << " " << v[1] << " " << v[2] << "\n";
    }
    // cout << "score = " << mony << "\n";

    return 0;
}
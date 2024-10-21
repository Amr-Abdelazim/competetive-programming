#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
// For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#else
#include "precompiled.h"
#endif
#define ll long long
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 5e5 + 5;
int color[N][2], vis[N], k, a[N], b[N];
vector<int> gr[N][2];
void dfs(int u, int c, int dx)
{
    color[u][dx] = c;
    vis[u] = 1;
    for (auto i : gr[u][dx])
    {
        if (vis[i])
            continue;
        dfs(i, (c + 1) % k, dx);
    }
}

vector<int> z_function(vector<int> s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
map<int, int> shft;
bool solve(vector<int> x, vector<int> y)
{
    if (x.empty() && y.empty())
        return true;
    if (x.size() != y.size())
        return false;
    vector<int> c1(k), c2(k);
    for (auto i : x)
    {
        c1[i]++;
    }
    for (auto i : y)
    {
        c2[i]++;
    }
    for (int i = 0; i < k; i++)
    {
        cerr << c1[i] << " ";
    }
    for (int i = 0; i < k; i++)
        c1.push_back(c1[i]);
    for (auto i : c1)
        c2.push_back(i);
    vector<int> z = z_function(c2);
    bool ans = false;
    for (int i = k; i < z.size(); i++)
    {

        if (z[i] == k)
        {
            ans = true;
            shft[i - k]++;
        }
    }
    cerr << "\n";
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        shft.clear();
        int n;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            gr[i][0].clear();
            gr[i][1].clear();
            color[i][0] = color[i][1] = vis[i] = 0;
        }
        int m1;
        cin >> m1;
        for (int i = 0; i < m1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            gr[u][0].push_back(v);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int m2;
        cin >> m2;
        for (int i = 0; i < m2; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            gr[u][1].push_back(v);
        }
        dfs(0, 0, 0);
        for (int i = 0; i < n; i++)
            vis[i] = 0;
        dfs(0, 0, 1);

        vector<int> x, y;
        for (int i = 0; i < n; i++)
        {
            if (a[i])
                x.push_back(color[i][0]);
            if (!b[i])
                y.push_back(color[i][1]);
        }
        if (!solve(x, y) && !(x.size() == n && y.size() == n))
        {
            cout << "NO\n";
            continue;
        }
        x.clear();
        y.clear();
        for (int i = 0; i < n; i++)
        {
            if (!a[i])
                y.push_back(color[i][0]);
            if (b[i])
                x.push_back(color[i][1]);
        }
        if (!solve(x, y) && !(x.size() == n && y.size() == n))
        {
            cout << "NO\n";
            continue;
        }
        bool yes = false;
        for (auto i : shft)
        {
            if (!t)
                cerr << i.first << " " << i.second << "\n";
            if (i.second == 2)
                yes = true;
        }
        if (yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
/*
ID: amr_abdelazim
LANG: C++
TASK: contact
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

int Solve()
{
    int l, r, n;
    cin >> l >> r >> n;
    string t, s;
    while (cin >> t)
    {
        s += t;
    }
    map<string, int> mp;
    rep(i, s.size())
    {
        string cur;
        for (int j = i; j < min((int)s.size(), i + r); j++)
        {
            cur += s[j];
            if (cur.size() >= l)
                mp[cur]++;
        }
    }
    vector<pair<int, string>> v;
    for (auto i : mp)
        v.push_back({i.second, i.first});
    sort(all(v));
    map<int, vector<string>> ans;
    rep(i, v.size())
    {
        ans[v[i].first].push_back(v[i].second);
    }
    auto it = ans.end();
    it--;
    while (n > 0)
    {
        cout << it->first << "\n";
        sort(all(it->second), [](string a, string b)
             {
            if(a.size()!=b.size())return a.size()<b.size();
            return a<b; });
        rep(i, (it->second).size())
        {

            cout << (it->second)[i];
            if (i == (it->second).size() - 1)
                break;
            if ((i + 1) % 6 == 0)
                cout << "\n";
            else
                cout << " ";
        }
        cout << "\n";
        n--;
        if (it == ans.begin())
            break;
        it--;
    }

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}
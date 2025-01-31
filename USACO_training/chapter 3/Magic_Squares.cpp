/*
ID: amr_abdelazim
LANG: C++
TASK: msquare
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
const int N = 8, M = 20, infint = 2e9;
const ll infll = 2e18;
void A(vector<int> &a)
{
    rep(i, N / 2) swap(a[i], a[N - i - 1]);
}
void B(vector<int> &a)
{
    for (int i = N / 2 - 1; i > 0; i--)
    {
        swap(a[i], a[i - 1]);
    }
    for (int i = N / 2; i < N - 1; i++)
        swap(a[i], a[i + 1]);
}
void C(vector<int> &a)
{
    swap(a[1], a[2]);
    swap(a[5], a[6]);
    swap(a[1], a[5]);
}
vector<int> target(N), a(N);
int mn = infint;
string res;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    rep(i, N) cin >> target[i], a[i] = i + 1;
    queue<pair<vector<int>, string>> q;
    set<vector<int>> st;
    q.push({a, ""});
    while (q.size())
    {
        auto cur = q.front();
        q.pop();
        if (cur.first == target)
        {
            res = cur.second;
            break;
        }
        if (st.count(cur.first))
            continue;
        st.insert(cur.first);
        vector<int> tmp = cur.first;
        A(cur.first);
        cur.second += "A";
        if (!st.count(cur.first))
            q.push(cur);
        cur.first = tmp;
        cur.second.pop_back();
        B(cur.first);
        cur.second += "B";
        if (!st.count(cur.first))
            q.push(cur);

        cur.first = tmp;
        cur.second.pop_back();
        C(cur.first);
        cur.second += "C";
        if (!st.count(cur.first))
            q.push(cur);

        cur.first = tmp;
        cur.second.pop_back();
    }

    cout << res.size() << "\n";
    rep(i, res.size())
    {
        if (i && i % 60 == 0)
            cout << "\n";
        cout << res[i];
    }
    cout << "\n";

    return 0;
}
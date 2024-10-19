#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
// For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#else
#include "precompiled.h"
#endif

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ^(.*)$   "$1",
vector<long long> fact, inv_fact;

long long mod_pow(long long a, long long b, int mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

void precompute_factorials(int n, int mod)
{
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
    }

    for (int i = n; i >= 0; --i)
    {
        inv_fact[i] = mod_pow(fact[i], mod - 2, mod);
    }
}

long long nCr(int n, int r, int mod)
{
    if (r > n || r < 0)
        return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

signed main()
{
    int t, mod;
    cin >> t >> mod;
    precompute_factorials(1e7, mod);
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << nCr(n, k, mod) << "\n";
    }

    return 0;
}
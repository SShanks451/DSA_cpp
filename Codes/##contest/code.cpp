#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define ff first
#define ss second
#define tc(t) \
    ll t;     \
    cin >> t; \
    while (t--)
#define vi vector<ll>
#define vii vector<pair<ll, ll>>
#define vid vector<ld>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define sz(s) s.size()
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define lb lower_bound
#define ub upper_bound
#define prec(n) fixed << setprecision(n)
#define nline "\n"

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll binaryExp(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return a * binaryExp(a * a, b / 2);
    return binaryExp(a * a, b / 2);
}
bool comparator_func(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.ff == b.ff)
        return a.ss > b.ss;
    return a.ff < b.ff;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
#include <bits/stdc++.h>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL)
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define vl vector<ll>
#define vll vector<pair<ll, ll>>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define AUTO(a, b) for (auto &a : b)
using namespace std;
const ll MAX = 1000000;
bool is_prime[MAX + 1];
ll sum[MAX + 1];

int main()
{
    fastio;

    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for (ll i = 2; i <= MAX; i++)
    {
        if (is_prime[i] == true)
        {
            for (ll j = i; j <= MAX; j += i)
            {
                if (j > i)
                {
                    is_prime[j] = false;
                }
                sum[j] += i;
            }
        }
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        ll a = sum[n];
        cout << a << endl;
    }

    return 0;
}

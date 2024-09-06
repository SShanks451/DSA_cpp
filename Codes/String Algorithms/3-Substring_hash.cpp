#include <bits/stdc++.h>
#define lli long long int
#define REP(i,n) for(int i=1; i<=n; i++)
#define mod 1000000007
using namespace std;

lli dp[1000001];
lli inv[1000001];  // inv[i] stores the inverse modulo of p^i


lli power(lli a, lli n) {
    lli result = 1;
    while(n) {
        if(n & 1) result = (result * a) % mod;

        n >>= 1;
        a = (a * a) % mod;
    }

    return result;
}


void init(string input_string) {
    lli p = 31;
    lli p_power = 1;
    inv[0] = 1;
    dp[0] = (input_string[0] - 'a' + 1);

    for(int i=1; i<input_string.size(); i++) {
        char ch = input_string[i];

        p_power = (p_power * p) % mod;
        inv[i] = power(p_power, mod-2);

        dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
    }
}


lli substringHash(int L, int R) {
    int result = dp[R];

    if(L > 0) result -= dp[L-1];

    result = (result * inv[L]) % mod;

    return result;
}


int main() {

    string input_string;
    int tc, L, R;

    cin >> input_string;
    init(input_string);

    cin >> tc;

    REP(i, tc){
        cin >> L >> R;
        cout << substringHash(L, R) << endl;
    }

    return 0;
}
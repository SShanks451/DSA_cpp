// Find the count of numbers between L and R which have a sum of digits = X.
// 1 <= L <= R <= 10^18
// 1 <= X <= 180

// dp state :- dp[N][X][1] = count of numbers having n digtis and (sum == x) and under tight constraints. Here 1 shows tight constraints and 0 shows no tight constraints.

#include <bits/stdc++.h>
using namespace std;

int dp[55][155][2];

int solve(int n, int x, int t, string s)
{
    if (x < 0)
        return 0;
    if (n == 0)
    {
        if (x == 0)
            return 1;
        return 0;
    }

    if (dp[n][x][t] != -1)
        return dp[n][x][t];

    int ub;
    if (t)
    {
        ub = s[s.size() - n] - '0';
    }
    else
    {
        ub = 9;
    }
    int cnt = 0;
    for (int i = 0; i <= ub; i++)
    {
        cnt += solve(n - 1, x - i, t & (i == ub), s);
    }

    dp[n][x][t] = cnt;
    return dp[n][x][t];
}

int main()
{

    string l, r;
    int x;
    cin >> l >> r;
    cin >> x;

    for (int i = 0; i < 55; i++)
    {
        for (int j = 0; j < 155; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    // for simplicity here, take l = "0"

    int ans = solve(r.size(), x, 1, r);

    cout << ans;

    return 0;
}
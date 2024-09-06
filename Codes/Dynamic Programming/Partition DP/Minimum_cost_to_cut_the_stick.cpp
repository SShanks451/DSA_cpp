// question link :- https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &dp, int l, int r, vector<int> &cuts, int start, int end)
{
    int m = cuts.size();
    if (r < l)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = INT_MAX;
    for (int i = l; i <= r; i++)
    {
        int gt = (end - start) + func(dp, l, i - 1, cuts, start, cuts[i]) + func(dp, i + 1, r, cuts, cuts[i], end);
        ans = min(ans, gt);
    }
    return dp[l][r] = ans;
}

int main()
{

    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> cuts(c);
    for (int i = 0; i < c; i++)
    {
        cin >> cuts[i];
    }
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 5, vector<int>(c + 5, -1));
    cout << func(dp, 0, c - 1, cuts, 0, n);

    return 0;
}
// You are given a tree consisting of n nodes.
// A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?

// question link :- https://cses.fi/problemset/task/1130

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> gr;
int dp[200005][3];
// dp[vr][prev] = ans for tress rooted at 'vr' and if it is picked by its parent or not i.e. prev = 0 or 1

int func(int vr, int prev, int par)
{
    if (dp[vr][prev] != -1)
    {
        return dp[vr][prev];
    }
    int sum = 0;
    int res = 0;
    for (auto child : gr[vr])
    {
        if (child != par)
        {
            sum += func(child, 0, vr);
        }
    }
    res = sum;
    if (prev != 1)
    {
        for (auto child : gr[vr])
        {
            if (child != par)
            {
                int take = 1 + func(child, 1, vr);
                int not_take = func(child, 0, vr);
                res = max(res, sum - not_take + take);
            }
        }
    }
    dp[vr][prev] = res;
    return dp[vr][prev];
}

signed main()
{
    int n;
    cin >> n;
    gr.resize(n + 5);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 0; i < 200005; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = func(1, 2, 1);
    cout << ans;

    return 0;
}
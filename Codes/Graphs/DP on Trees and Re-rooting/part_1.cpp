// a tree is given. you have to paint each vertex in color black or white. you are not allowed to paint two adjacent vertices both in black. find the no of ways in which the vertices can be painted.

// question link :- https://atcoder.jp/contests/dp/tasks/dp_p

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> gr;
int dp[100005][3] = {-1};

// dp[vr][prev_col] = no of ways to colour tree whose root is 'vr' and the parent of vr is coloured in 'prev_col'

int func(int vr, int prev_col, int par)
{
    if (dp[vr][prev_col] != -1)
    {
        return dp[vr][prev_col];
    }

    int resw = 1;
    int resb = 1;
    for (auto child : gr[vr])
    {
        if (child != par)
        {
            resw = ((resw % MOD) * (func(child, 0, vr) % MOD)) % MOD;
            resb = ((resb % MOD) * (func(child, 1, vr) % MOD)) % MOD;
        }
    }
    if (prev_col == 1)
    {
        resb = 0;
    }
    dp[vr][prev_col] = ((resw % MOD) + (resb % MOD)) % MOD;
    return dp[vr][prev_col];
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
    for (int i = 0; i < 100005; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = func(1, 2, 1);
    cout << ans << endl;

    return 0;
}
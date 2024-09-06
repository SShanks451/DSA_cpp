// Given a tree of n nodes, rooted at node 1, find the sum of distances of all nodes from node 1.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<int> cnt; // cnt[i] = no. of nodes in subtree of i
vector<int> dp;  // dp[i] = sum of distances of all the nodes in subtree of node i from node i

void dfs(int vr, int par)
{
    cnt[vr] = 1;
    for (auto child : gr[vr])
    {
        if (child != par)
        {
            dfs(child, vr);
            cnt[vr] += cnt[child];
            dp[vr] += dp[child] + cnt[child];
        }
    }
}

int main()
{

    int n;
    cin >> n;
    gr.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    cnt.resize(n + 1);
    dp.resize(n + 1);

    dfs(1, -1);

    cout << dp[1];

    return 0;
}
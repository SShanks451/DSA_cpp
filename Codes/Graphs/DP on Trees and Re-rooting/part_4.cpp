// Re-rooting technique

// Given a tree of n nodes. Your task is to determine for each node the sum of the distances from the node to all other nodes
// question link :- https://cses.fi/problemset/task/1133

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> gr;
vector<int> cnt;
vector<int> dp; // dp[i] = sum of distance of all the nodes from root of a subtree rooted at 'i'
vector<int> ans;

void dfs_1(int vr, int par)
{
    cnt[vr] = 1;
    for (auto child : gr[vr])
    {
        if (child != par)
        {
            dfs_1(child, vr);
            cnt[vr] += cnt[child];
            dp[vr] += dp[child] + cnt[child];
        }
    }
}

void dfs_2(int vr, int par)
{
    ans[vr] = dp[vr];
    int cnt_temp = cnt[vr];
    int dp_temp = dp[vr];
    for (auto child : gr[vr])
    {
        if (child != par)
        {
            int cnt_temp_child = cnt[child];
            int dp_temp_child = dp[child];
            cnt[vr] -= cnt[child];
            dp[vr] -= (dp[child] + cnt[child]);
            cnt[child] += cnt[vr];
            dp[child] += (dp[vr] + cnt[vr]);

            dfs_2(child, vr);

            cnt[vr] = cnt_temp;
            dp[vr] = dp_temp;
            cnt[child] = cnt_temp_child;
            dp[child] = dp_temp_child;
        }
    }
}

signed main()
{
    int n;
    cin >> n;
    gr.resize(n + 1);
    cnt.resize(n + 1);
    dp.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs_1(1, -1);
    dfs_2(1, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
// finding distance between two nodes
// Time complexity :- O(log N) per query

// question link :- https://cses.fi/problemset/task/1135

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
int pre_calc[500002][30];
int depth[500002];

void dfs(int vr, int par)
{
    pre_calc[vr][0] = par;
    for (int i = 1; i <= 28; i++)
    {
        pre_calc[vr][i] = pre_calc[pre_calc[vr][i - 1]][i - 1];
    }

    for (auto child : gr[vr])
    {
        if (child != par)
        {
            depth[child] = 1 + depth[vr];
            dfs(child, vr);
        }
    }
}

int find_kth(int n, int k)
{
    int ans = n;
    for (int i = 28; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            ans = pre_calc[ans][i];
        }
    }
    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;
    gr.resize(n + 5);

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    depth[1] = 0;
    dfs(1, 1);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int x = depth[a];
        int y = depth[b];
        if (depth[a] > depth[b])
        {
            int z = a;
            a = b;
            b = z;
        }
        int dif = depth[b] - depth[a];
        b = find_kth(b, dif);
        int lca;
        if (b == a)
        {
            lca = a;
        }
        else
        {
            for (int i = 28; i >= 0; i--)
            {
                if (pre_calc[a][i] != pre_calc[b][i])
                {
                    a = pre_calc[a][i];
                    b = pre_calc[b][i];
                }
            }
            lca = pre_calc[a][0];
        }
        int ans = x + y - 2 * depth[lca];
        cout << ans << endl;
    }

    return 0;
}
// bipartite graph -> that can be coloured using 2 colors such that no two adjacent nodes have same color.
// If a graph has odd length cycle then it is not a bipartite graph and if a graph have even length cycle then it is bipartite.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool bipartiteDfs(int node, vector<int> adj[], int color[])
{
    if (color[node] == -1)
    {
        color[node] = 1;
    }

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartiteDfs(it, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == color[node])
        {
            return false;
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n)
{
    int color[N];
    memset(color, -1, sizeof(color));

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteDfs(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[N];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
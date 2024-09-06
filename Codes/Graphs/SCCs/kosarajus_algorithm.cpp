// SCCs => Strongly Connected Components

// 1. Run dfs on given graph G and find the nodes in decreasing  order of finish time (Topological sorting).
// 2. Create a new graph Gt, which has all the edges reversed from the original graph.
// 3. Start DFS in this new graph Gt, in the topological order of the original graph.

#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> g, gr;
stack<int> st;
vector<int> component;
vector<vector<int>> sccs;

void dfs1(int i)
{
    vis[i] = true;
    for (auto it : g[i])
    {
        if (!vis[it])
        {
            dfs1(it);
        }
    }
    st.push(i);
}

void dfs2(int i)
{
    vis[i] = true;
    for (auto it : gr[i])
    {
        if (!vis[it])
        {
            dfs2(it);
        }
    }
    component.push_back(i);
}

int main()
{

    int n, m;
    cin >> n >> m;
    g.resize(n + 5);
    gr.resize(n + 5);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs1(i);
        }
    }
    vis.assign(n + 1, false);
    while (!st.empty())
    {
        int t = st.top();
        st.pop();
        if (vis[t])
        {
            continue;
        }
        component.clear();
        dfs2(t);
        sccs.push_back(component);
    }

    for (int i = 0; i < sccs.size(); i++)
    {
        for (int j = 0; j < sccs[i].size(); j++)
        {
            cout << sccs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


bool bfsCycle(int srcNode, vector<vector<int>> &graph, vector<bool> &vis) {
    queue<pair<int, int>> q;
    q.push({srcNode, -1});
    vis[srcNode] = 1;

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto child : graph[node]) {
            if(!vis[child]) {
                q.push({child, node});
                vis[child] = 1;
            }else if(parent != child){
                return true;
            }
        }
    }

    return false;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n+5);

    bool ans = false;

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            if(bfsCycle(i, graph, vis)) {
                ans = true;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
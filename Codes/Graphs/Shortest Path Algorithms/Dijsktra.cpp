#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;
vector<pair<int,int>> g[N];
vector<int> dist(N, INF);
vector<bool> vis(N, false);


int main(){

    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y,wt;
        cin >> x >> y >> wt;
        g[x].push_back({y,wt});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[1] = 0;
    pq.push({dist[1], 1});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto child : g[u]){
            int v = child.first;
            int w = child.second;
            if((!vis[v]) && (dist[u] + w < dist[v])){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << "The shortest distance from sorce node 1 to node " << i << " is " << dist[i] << endl;
    }

    return 0;
}
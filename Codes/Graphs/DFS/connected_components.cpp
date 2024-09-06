// question link :- https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
bool vis[N];

vector<vector<int>> cc; // collection of all connected components
vector<int> current_cc;

void dfs(int vertex){
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for(int child : g[vertex]){
        if(vis[child]) continue;
        dfs(child); 
    }
}

int main(){

    int n,e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }

    cout << cc.size() << endl; // no. of connected components
    for(auto c_cc : cc){
        for(int vertex : c_cc){
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
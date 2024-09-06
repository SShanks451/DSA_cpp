// topological sort is only possible in case of directed acyclic graph

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
stack<int> st;

void dfs(int vertex){
    vis[vertex] = 1;
    for(auto child : g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
    st.push(vertex);
}

int main(){

    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
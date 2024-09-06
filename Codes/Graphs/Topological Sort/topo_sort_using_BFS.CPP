// This is also called Kahn's Algorithm
// topological sort is only possible in case of directed acyclic graph

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
int indegree[N];
vector<int> topo_sort;
int n,m;

void bfs(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo_sort.push_back(node);
        for(auto it : g[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
}

int main(){

    cin >> n >> m;
    
    for(int j=0; j<m; j++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    

    for(int i=1; i<=n; i++){
        for(auto it : g[i]){
            indegree[it]++;
        }    
    }

    bfs();

    for(int i=0; i<topo_sort.size(); i++){
        cout << topo_sort[i] << " ";
    }

    return 0;
}
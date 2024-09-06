// question link :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/
// This is for undirected graph

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int parent){
    vis[vertex] = 1;
    bool isLoopExist = false;
    for(int child : g[vertex]){
        if(vis[child] && child==parent){
            continue;
        }
        if(vis[child]){
            return true;
        }
        isLoopExist |= dfs(child, vertex);
    }
    return isLoopExist;
}


int main(){

    int n,e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool isLoopExists = false;
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        if(dfs(i, -1)){
            isLoopExists = true;
            break;
        }
    }
    cout<<isLoopExists;

    return 0;
}
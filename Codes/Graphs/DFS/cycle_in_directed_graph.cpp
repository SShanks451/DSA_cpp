#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
bool dfsVis[N];

bool checkCycle(int node){
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto child : g[node]){
        if(!vis[child]){
            if(checkCycle(child)){
                return true;
            }
        }else if(dfsVis[child]){
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

int main(){

    int n,e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    bool isCycle = 0;

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(checkCycle(i)){
                isCycle = 1;
            }
        }
    }

    if(isCycle){
        cout << "Cycle exists" << endl; 
    }else{
        cout << "Cycle do not exist" << endl;
    }

    return 0;
}
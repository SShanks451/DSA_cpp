// question link :- https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

    bool check(int curr, int col, int n, bool graph[101][101], vector<int> &color){
        for(int j=0; j<n; j++){
            if(j!=curr && graph[curr][j]==1 && color[j]==col){
                return false;
            }
        }
        return true;
    }
    
    bool solve(int m, int n, bool graph[101][101], vector<int> &color, int curr){
        
        if(curr == n) return true;
        
        for(int i=1; i<=m; i++){
            if(check(curr,i,n,graph,color)){
                color[curr] = i;
                if(solve(m, n, graph, color, curr+1)){
                    return true;
                }
                color[curr] = 0;
            }
        }
        return false;
    }
    
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0);
        return solve(m,n,graph,color,0);
    }   




int main() {

    // input is not taken
    // it is assumed that graph is constructed and passed into the graphColoring() function

    return 0;
}
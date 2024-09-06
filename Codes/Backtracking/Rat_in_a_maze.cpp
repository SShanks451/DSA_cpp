// question link :- https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rat-in-a-maze-problem

#include <bits/stdc++.h>
using namespace std;


bool check(int row, int col, vector<vector<int>> &m, vector<vector<bool>> &vis){
    int n = m.size();
    if(row>=0 && row<n && col>=0 && col<n && vis[row][col]==0){
        if(m[row][col] == 1) return true;
    }
    return false;
}
    
void solve(int row, int col, vector<string> &ans, vector<vector<int>> &m, int n, string &s, vector<vector<bool>> &vis){
    if(row==n-1 && col==n-1){
        ans.push_back(s);
        return;
    }
    if(check(row+1, col, m, vis)){
        vis[row][col] = 1;
        s.push_back('D');
        solve(row+1, col, ans, m, n, s, vis);
        vis[row][col] = 0;
        s.pop_back();
    }
    if(check(row-1, col, m, vis)){
        vis[row][col] = 1;
        s.push_back('U');
        solve(row-1, col, ans, m, n, s, vis);
        vis[row][col] = 0;
        s.pop_back();
    }
    if(check(row, col+1, m, vis)){
        vis[row][col] = 1;
        s.push_back('R');
        solve(row, col+1, ans, m, n, s, vis);
        vis[row][col] = 0;
        s.pop_back();
    }
    if(check(row, col-1, m, vis)){
        vis[row][col] = 1;
        s.push_back('L');
        solve(row, col-1, ans, m, n, s, vis);
        vis[row][col] = 0;
        s.pop_back();
    }
}

int main() {

    int n = 4;

    vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool> (n));
    string s = "";
    solve(0, 0, ans, m, n, s, vis);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }


    return 0;
}
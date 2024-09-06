// question link :- https://leetcode.com/problems/cherry-pickup/

#include <bits/stdc++.h>
using namespace std;

int dp[55][55][55];

int solve(vector<vector<int>>& grid, int i, int j, int k, int n) {
    if(i>=n || j>=n || k>=n || i+j-k>=n ||grid[i][j]==-1 || grid[k][i+j-k]==-1) {
        return INT_MIN;
    }
    if(i==n-1 && j==n-1) {
        return grid[i][j];
    }

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int z = grid[i][j];
    if(i!=k) {
        z += grid[k][i+j-k];
    }
    dp[i][j][k] = z + max(max(solve(grid,i+1,j,k+1,n), solve(grid,i,j+1,k+1,n)), max(solve(grid,i+1,j,k,n), solve(grid,i,j+1,k,n)));
    return dp[i][j][k];
}



int main () {

    vector<vector<int>> grid = {{0,1,-1}, {1,0,-1}, {1,1,1}};
    int n = grid.size();
    for(int i=0; i<55; i++) {
        for(int j=0; j<55; j++) {
            for(int k=0; k<55; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = solve(grid,0,0,0,n);
    if(ans<0){
        ans = 0;
    }
    cout << ans;

    return 0;
}
// question link :- https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// variable starting and ending points

#include <bits/stdc++.h>
using namespace std;


int maxPathSum(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(j<0 || j>=mat[0].size()){
        return -1e8;
    }
    if(i==0){
        return mat[0][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int up_move = mat[i][j] + maxPathSum(i-1,j,mat,dp);
    int ld_move = mat[i][j] + maxPathSum(i-1,j-1,mat,dp);
    int rd_move = mat[i][j] + maxPathSum(i-1,j+1,mat,dp);
    dp[i][j] = max(up_move,max(ld_move,rd_move));

    return dp[i][j];
}


int main(){

    int n,m;
    cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m,-1));

    int ans = -1e8;
    for(int j=0; j<m; j++){
        ans = max(ans, maxPathSum(n-1,j,mat,dp));
    }
    cout << ans;

    return 0;
}
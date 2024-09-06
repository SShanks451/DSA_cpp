// question link :- https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int pathSum(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i==0 && j==0){
        return mat[0][0];
    }
    if(i<0 || j<0){
        return INF;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = min(mat[i][j]+pathSum(i-1,j,mat,dp), mat[i][j]+pathSum(i,j-1,mat,dp));
    return dp[i][j];
}

int main(){

    int n,m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int> (m,-1));

    cout << pathSum(n-1,m-1,mat,dp);


    return 0;
}
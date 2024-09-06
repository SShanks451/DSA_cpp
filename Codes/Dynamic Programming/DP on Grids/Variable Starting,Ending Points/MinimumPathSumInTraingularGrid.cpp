// question link:- https://leetcode.com/problems/triangle/

// fixed starting point and variable ending point

#include <bits/stdc++.h>
using namespace std;

int triangularGrid(int i, int j, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(i==n-1){
        return mat[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = min(mat[i][j]+triangularGrid(i+1,j,n,mat,dp), mat[i][j]+triangularGrid(i+1,j+1,n,mat,dp));
    return dp[i][j];
}

int main(){

    int n;
    cin >> n;
    
    vector<vector<int>> mat(n);

    for(int i=0; i<n; i++){
        mat[i].resize(i+1);
        for(int j=0; j<(mat[i].size()); j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> dp(n,vector<int> (n,-1));

    cout << triangularGrid(0,0,n,mat,dp);
    

    return 0;
}
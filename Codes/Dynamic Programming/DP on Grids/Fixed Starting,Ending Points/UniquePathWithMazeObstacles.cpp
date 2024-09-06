// question link :- https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;


int mazeObstacle(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &mat){
    if(i>=0 && j>=0 && mat[i][j]==1){
        return 0;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = mazeObstacle(i-1,j,dp,mat) + mazeObstacle(i,j-1,dp,mat);
    return dp[i][j];
}

int main(){

    int m,n;
    cin >> m >> n;
    vector<vector<int>> mat(m,vector<int> (n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> dp(m,vector<int> (n,-1));
    cout << mazeObstacle(m-1,n-1,dp,mat);


}
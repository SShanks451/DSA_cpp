// question link :- https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;

int totalUniquePath(int i, int j, vector<vector<int>> &dp){
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = totalUniquePath(i-1,j,dp) + totalUniquePath(i,j-1,dp);
    return dp[i][j];

}

int main(){

    int m,n;
    cin >> m >> n;

    vector<vector<int>> dp(m,vector<int> (n,-1));

    cout << totalUniquePath(m-1, n-1, dp);
    

    return 0;
}
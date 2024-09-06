// question link :- https://leetcode.com/problems/coin-change/submissions/

#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>> &dp, vector<int> &coins) {

    if(j==0) return 0;
    if(i<0 || j<0) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];
    if(coins[i] <= j) {
        dp[i][j] = min(1+solve(i,j-coins[i],dp,coins), solve(i-1,j,dp,coins));
    }else{
        dp[i][j] = solve(i-1,j,dp,coins);
    }
    return dp[i][j];
}



int main(){

    vector<int> coins = {1,2,5};
    int amount = 11;

    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int> (amount+1, -1)); 
    int ans = solve(n-1,amount,dp,coins);
    if(ans >= 1e9) return -1;

    cout << ans;

    return 0;
}
// question link :- https://www.geeksforgeeks.org/coin-change-dp-7/

#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &coins, vector<vector<int>> &dp) {

    if(j==0) return 1;
    if(i<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    if(coins[i] <= j) {
        dp[i][j] = solve(i-1,j,coins,dp) + solve(i,j-coins[i],coins,dp);
    }else{
        dp[i][j] = solve(i-1,j,coins,dp);
    }
    return dp[i][j];
}

int main(){

    vector<int> coins = {1,2,5};
    int amount = 4;

    int n = coins.size();
    vector<vector<int>> dp(n+1, vector<int> (amount+1,-1));
    int ans = solve(n-1, amount, coins, dp);
    if(ans < 0) {
        cout << 0;
    }else {
        cout << ans;
    }

    return 0;
}
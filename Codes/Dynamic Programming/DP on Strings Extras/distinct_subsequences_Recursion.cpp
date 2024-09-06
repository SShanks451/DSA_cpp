// question link :- https://leetcode.com/problems/distinct-subsequences/

#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]){
        dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
    }else{
        dp[i][j] = solve(i-1,j,s,t,dp);
    }
    return dp[i][j];
}

int main(){

    string s = "babgbag";
    string t = "bag";

    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));

    int ans = solve(n-1,m-1,s,t,dp);
    cout << ans;


    return 0;
}
// question link :- https://leetcode.com/problems/edit-distance/


// 1+solve(i-1,j,word1,word2,dp) -> delete 
// 1+solve(i,j-1,word1,word2,dp) -> insert 
// 1+solve(i-1,j-1,word1,word2,dp) -> repalce 

// base case is important in this problem


#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j] != -1) return dp[i][j];
    if(word1[i] == word2[j]){
        dp[i][j] = solve(i-1,j-1,word1,word2,dp);
    }else{
        dp[i][j] = min(1+solve(i-1,j,word1,word2,dp), min(1+solve(i,j-1,word1,word2,dp), 1+solve(i-1,j-1,word1,word2,dp)));
    }
    return dp[i][j];
}

int main(){

    string word1 = "horse";
    string word2 = "ros";
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n, vector<int> (m, -1));

    int ans = solve(n-1,m-1,word1,word2,dp);
    cout << ans;

    return 0;
}
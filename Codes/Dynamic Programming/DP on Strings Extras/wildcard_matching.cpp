// question link :- https://leetcode.com/problems/wildcard-matching/

// base cases are very very important in this question 



#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int j, string &pattern, string &str, vector<vector<int>> &dp){

    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0){
        for(int i1=0; i1<=i; i1++){
            if(pattern[i1] != '*'){
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(pattern[i]==str[j] || pattern[i]=='?'){
        return dp[i][j] = solve(i-1,j-1,pattern,str,dp);
    }else if(pattern[i] == '*'){
        return dp[i][j] = solve(i-1,j,pattern,str,dp) || solve(i,j-1,pattern,str,dp);
    }
    return dp[i][j]=false;
}


int main(){

    string s = "aa";
    string p = "*";
    int m = s.size();
    int n = p.size();

    vector<vector<int>> dp(n, vector<int> (m,-1));

    bool ans = solve(n-1,m-1,p,s,dp);
    cout << ans;

    return 0;
}
// question link :- https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string s, string sr, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(s[n-1] == sr[m-1]){
        dp[n][m] = 1 + lcs(s, sr, n-1, m-1);
    }else{
        dp[n][m] = max(lcs(s, sr, n-1, m), lcs(s, sr, n, m-1));
    }
    return dp[n][m];
}

int main(){

    string s = "GEEKSFORGEEKS";
    string sr = s;
    reverse(sr.begin(), sr.end());

    memset(dp, -1, sizeof(dp));

    cout << lcs(s, sr, s.size(), sr.size());

    return 0;
}
// question link :- https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include<bits/stdc++.h>
using namespace std;

int static dp[1001][1001];

int lcs(string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(x[n-1] == y[m-1]){
        dp[n][m] = 1+lcs(x, y, n-1, m-1);
    }else{
        dp[n][m] = max(lcs(x, y, n, m-1), lcs(x, y, n-1, m));
    }
    return dp[n][m];
}

int main(){

    string x = "AGGTAB";
    string y = "GXTXAYB";

    int n = x.size();
    int m = y.size();

    memset(dp, -1, sizeof(dp));

    cout << lcs(x, y, n, m);

    return 0;
}
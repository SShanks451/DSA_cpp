// question link :- https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(x[n-1] == y[m-1]){
        dp[n][m] = 1 + lcs(x, y, n-1, m-1);
    }else{
        dp[n][m] = max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
    }
    return dp[n][m];
}

int main(){

    string x = "heap";
    string y = "pea";

    int n = x.size();
    int m = y.size();

    memset(dp, -1, sizeof(dp));

    int count = lcs(x, y, n, m);

    int ans = (n-count) + (m-count);

    cout << ans;

    return 0;
}
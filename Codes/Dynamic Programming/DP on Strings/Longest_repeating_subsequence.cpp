// question link :- https://www.geeksforgeeks.org/longest-repeated-subsequence/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string x, string y, int i, int j){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(x[i-1]==y[j-1] && i!=j){
        dp[i][j] = 1 + lcs(x, y, i-1, j-1);
    }else{
        dp[i][j] = max(lcs(x,y,i-1,j), lcs(x,y,i,j-1));
    }
    return dp[i][j];
}

int main(){

    string str = "AABEBCDD";
    int n = str.size();

    memset(dp, -1, sizeof(dp));

    cout << lcs(str, str, n, n);

    return 0;
}
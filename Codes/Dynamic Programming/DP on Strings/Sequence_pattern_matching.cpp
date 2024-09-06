#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcs(string a, string b, int i, int j){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(a[i-1] == b[j-1]){
        dp[i][j] = 1+lcs(a,b,i-1,j-1);
    }else{
        dp[i][j] = max(lcs(a,b,i-1,j), lcs(a,b,i,j-1));
    }
    return dp[i][j];
}

int main(){

    string a = "AXY";
    string b = "ADXCPY";

    int m = a.size();
    int n = b.size();

    memset(dp, -1, sizeof(dp));

    int check = lcs(a,b,m,n);
    if(check == min(n, m)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
// question link :- https://www.geeksforgeeks.org/longest-common-substring-dp-29/

#include<bits/stdc++.h>
using namespace std;

int main(){

    string x = "adac";
    string y = "adadac";

    int n = x.size();
    int m = y.size();

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }      

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
        }
    }

    int ans = INT_MIN;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans;

    return 0;
}
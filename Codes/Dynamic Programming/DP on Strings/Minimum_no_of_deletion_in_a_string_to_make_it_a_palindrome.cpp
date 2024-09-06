// question link :- https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/

#include<bits/stdc++.h>
using namespace std;

int main(){

    string s = "aebcbda";
    string sr = s;
    reverse(sr.begin(), sr.end());

    int n = s.size();
    int m = n;
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
            if(s[i-1] == sr[j-1]){
                dp[i][j] =  1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int ans = (n-dp[n][m]);
    cout << ans;

    return 0;
}
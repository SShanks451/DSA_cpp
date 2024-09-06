// question link :- https://www.geeksforgeeks.org/printing-longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;

int main(){

    string x = "AGGTAB";
    string y = "GXTXAYB";

    int n = x.size();
    int m = y.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1));

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
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i = n;
    int j = m;
    string ans = "";
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;


    return 0;
}
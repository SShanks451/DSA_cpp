// question link :- https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    for(int i=1; i<n; i++){
        dp[i][i] = 0;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<n; j++){
            int mini = 1e9;
            for(int k=i; k<j; k++){
                int steps = vec[i-1]*vec[k]*vec[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    cout << dp[1][n-1];

    return 0;
}
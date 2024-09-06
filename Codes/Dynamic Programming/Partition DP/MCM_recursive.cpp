// question link :- https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;


int mcm(int i, int j, vector<int> &vec, vector<vector<int>> &dp){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini = 1e9;
    for(int k=i; k<j; k++){
        int steps = vec[i-1]*vec[k]*vec[j] + mcm(i,k,vec,dp) + mcm(k+1,j,vec,dp);
        mini = min(mini, steps);
    }
    dp[i][j] = mini;
    return dp[i][j];
}

int main(){

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    vector<vector<int>> dp(n, vector<int> (n,-1));
    cout << mcm(1,n-1,vec,dp);

    return 0;
}
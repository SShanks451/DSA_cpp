// question link :- https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// state :- 
// dp[i][j] = length of LIS starting from ith index whose previous index is jth

#include <bits/stdc++.h>
using namespace std;

int lis(int index, int prev_index, int n, vector<int> &vec, vector<vector<int>> &dp){
    if(index==n){
        return 0;
    }
    if(dp[index][prev_index+1]!=-1){
        return dp[index][prev_index+1];
    }
    int len = lis(index+1,prev_index,n,vec,dp);
    if(prev_index==-1 || vec[index]>vec[prev_index]){
        len = max(len,1+lis(index+1,index,n,vec,dp));
    }
    dp[index][prev_index+1] = len;
    return dp[index][prev_index+1];
}

int main(){

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    vector<vector<int>> dp(n, vector<int> (n+1, -1));

    cout << lis(0,-1,n,vec,dp);


    return 0;
}
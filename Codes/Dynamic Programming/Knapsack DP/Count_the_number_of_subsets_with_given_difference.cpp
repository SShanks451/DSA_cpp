// question link :- https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &vec, vector<vector<int>> &dp) {
    if(i==0) {
        if(j==0 && vec[i]==0) return 2;
        if(j==0 || j==vec[i]) return 1;
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(vec[i] > j) {
        dp[i][j] = solve(i-1,j,vec,dp);
    }else{
        dp[i][j] = (solve(i-1,j,vec,dp) + solve(i-1,j-vec[i],vec,dp))%1000000007;
    }
    return dp[i][j];
}


int main(){

    int n = 4;
    int d = 3;
    vector<int> arr = {5,2,6,4};

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    if((sum+d)%2) return 0;
    int req = (sum + d) / 2;
    vector<vector<int>> dp(n, vector<int> (req+5, -1));
    cout << solve(n-1, req , arr, dp);

    return 0;
}
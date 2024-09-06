// https://leetcode.com/problems/target-sum/

#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {

    if(i<0 && j==0) return 1;
    if(i<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(nums[i] <= j) {
        dp[i][j] = solve(i-1,j,nums,dp) + solve(i-1,j-nums[i],nums,dp);
    }else{
        dp[i][j] = solve(i-1,j,nums,dp);
    }
    return dp[i][j];
}

int main(){

    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    int sum = 0;
    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
    }

    target = abs(target);

    if((sum+target) % 2) {
        cout << 0;
    }else {
        vector<vector<int>> dp(nums.size()+1, vector<int> (1005, -1));
        int req = (sum+target) / 2;
        cout << solve(nums.size()-1, req, nums, dp);
    }
    

    return 0;
}
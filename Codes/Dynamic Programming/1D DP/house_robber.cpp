// question link :- https://leetcode.com/problems/house-robber/description/

#include <bits/stdc++.h>
using namespace std;


int solve(int i, vector<int> &dp, vector<int> &nums){
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i] = max(solve(i-1,dp,nums), nums[i]+solve(i-2,dp,nums));
    return dp[i];
}


int main() {

    vector<int> nums = {1,2,3,1};
    int n = nums.size();

    vector<int> dp(n+1, -1);

    cout << solve(n-1, dp, nums);


    return 0;
}
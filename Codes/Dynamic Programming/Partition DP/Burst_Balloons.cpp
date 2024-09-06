
// question link :- https://leetcode.com/problems/burst-balloons/

#include <bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &dp, int l, int r, vector<int> &nums)
{
    int n = nums.size();

    if (r < l)
    {
        return 0;
    }
    if (l == r)
    {
        int temp = nums[l];
        if (l - 1 >= 0)
        {
            temp *= nums[l - 1];
        }
        if (r + 1 < n)
        {
            temp *= nums[r + 1];
        }
        return temp;
    }

    if (dp[l][r] != -1)
        return dp[l][r];

    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        int temp = nums[i];
        if (l - 1 >= 0)
        {
            temp *= nums[l - 1];
        }
        if (r + 1 < n)
        {
            temp *= nums[r + 1];
        }
        temp += (func(dp, l, i - 1, nums) + func(dp, i + 1, r, nums));
        ans = max(ans, temp);
    }
    return dp[l][r] = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> vec;
    vec.push_back(1);
    for (int i = 0; i < n; i++)
    {
        vec.push_back(nums[i]);
    }
    vec.push_back(1);
    vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
    cout << func(dp, 1, n, vec);

    return 0;
}
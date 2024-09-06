// question link :- https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    vector<int> dp(n,1);
    vector<int> cnt(n,1);

    int maxi = dp[0];

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(vec[j]<vec[i] && 1+dp[j]>dp[i]){
                dp[i] = 1+dp[j];
                cnt[i] = cnt[j];
            }else if(vec[j]<vec[i] && 1+dp[j]==dp[i]){
                cnt[i] += cnt[j];
            }
        }
        maxi = max(maxi,dp[i]);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(dp[i]==maxi){
            ans += cnt[i];
        }
    }
    cout << ans;

    return 0;
}
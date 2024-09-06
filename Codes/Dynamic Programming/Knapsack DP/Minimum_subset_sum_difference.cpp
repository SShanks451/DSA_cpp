// question link :- https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = { 3, 1, 4, 2, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int> (sum+1));
    for(int i=0; i<=sum; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            }
        }
    }

    int var = INT_MAX;
    for(int i=0; i<=(sum/2); i++){
        if(dp[n][i]){
            var = min(var, sum-(2*i));
        }
    }

    cout << var << endl;



    return 0;
}
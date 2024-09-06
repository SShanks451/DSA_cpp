// question link :- https://www.geeksforgeeks.org/partition-problem-dp-18/

#include<bits/stdc++.h>
using namespace std;

int dp[101][10001];

bool check(int arr[], int i, int j){
    if(j==0){
        return 1;
    }
    if(i==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(arr[i-1]>j){
        dp[i][j] = check(arr, i-1, j);
    }else{
        dp[i][j] = check(arr,i-1,j)||check(arr,i-1,j-arr[i-1]);
    }
    return dp[i][j];
}

int main(){

    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    if(sum%2 != 0){
        cout<<0;
    }else{
        memset(dp, -1, sizeof(dp));
        cout<<check(arr, n, (sum/2));
    }

    return 0;
}
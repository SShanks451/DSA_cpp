// question link :- https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int check(int arr[], int i, int j){
    if(j==0){
        return 1;
    }
    if(i==0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(j < arr[i-1]){
        dp[i][j] = check(arr, i-1, j);
    }else{
        dp[i][j] = check(arr, i-1, j-arr[i-1]) + check(arr, i-1, j);
    }
    return dp[i][j];
}

int main(){

    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(arr) / sizeof(int);
    int sum = 10;

    memset(dp, -1, sizeof(dp));

    cout << check(arr, n, sum);

    return 0;
}
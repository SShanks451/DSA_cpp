// question link :- https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/

#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int unboundedKnapsack(int W, int n, int val[], int wt[]){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    if(wt[n-1] > W){
        dp[n][W] = unboundedKnapsack(W, n-1, val, wt);
    }else{
        dp[n][W] = max(unboundedKnapsack(W, n-1, val, wt), val[n-1]+unboundedKnapsack(W-wt[n-1], n, val, wt));
    }
    return dp[n][W];
}

int main(){

    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val)/sizeof(val[0]);

    memset(dp, -1, sizeof(dp));
 
    cout << unboundedKnapsack(W, n, val, wt);

    return 0;
}
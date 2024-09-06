// question link :- https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int knapSack(int W, int wt[], int val[], int n){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    if(wt[n-1]<=W){
        dp[n][W] = max(val[n-1]+knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
    }else if(wt[n-1]>W){
        dp[n][W] = knapSack(W, wt, val, n-1);
    }
    return dp[n][W];

}

int main(){

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
     
    memset(dp, -1, sizeof(dp));
    cout << knapSack(W, wt, val, n);

    return 0;
}
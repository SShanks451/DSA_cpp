// question link :- https://www.geeksforgeeks.org/subset-sum-problem-dp-25/


#include<bits/stdc++.h>
using namespace std;

int dp[102][100002];

bool check(int set[], int i, int j){
    if(j==0){
        return 1;
    }
    if(i==0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(set[i-1]>j){
        dp[i][j] = check(set, i-1, j);
    }else{
        dp[i][j] = check(set, i-1, j) || check(set, i-1, j-set[i-1]);
    }
    return dp[i][j];
}

int main(){
    
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    memset(dp, -1, sizeof(dp));
    cout << check(set, n, sum);

    return 0;
}
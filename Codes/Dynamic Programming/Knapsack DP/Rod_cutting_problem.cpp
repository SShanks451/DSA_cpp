// question link :- https://www.geeksforgeeks.org/cutting-a-rod-dp-13/ 

#include<bits/stdc++.h>
using namespace std;

int dp[1001][100001];

int check(int length[], int price[], int i, int j){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(length[i-1] > j){
        dp[i][j] = check(length, price, i-1, j);
    }else{
        dp[i][j] = max(check(length, price, i-1, j), price[i-1] + check(length, price, i, j-length[i-1]));
    }
    return dp[i][j];
}

int main(){

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    const int size = sizeof(price)/sizeof(price[0]);

    int length[size];
    for(int i=0; i<size; i++){
        length[i] = i+1;
    }
    memset(dp, -1, sizeof(dp));

    cout << check(length, price, size, size);



    return 0;
}